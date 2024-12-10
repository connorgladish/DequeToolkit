/**
 * @file deque.cpp
 * @author CJ Gladish, Reece Cosbey
 * @date 2024-12-09
 * @brief Implements deque.h methods.
 * 
 * 
 */
#include "deque.h"
#include <stdexcept>
#include <iostream> 
using namespace std;
/**
 * Constructs an empty Deque.
 *
 * @pre None
 * @return void
 * @post A Deque object is initialized with default values and allocated memory for one block.
 */
Deque::Deque()
    : blockmap(nullptr), block_size(4), num_blocks(1), capacity(4), current_size(0), front_index(0), back_index(0) {
    blockmap = new int*[num_blocks];
    blockmap[0] = new int[block_size];
}

/**
 * Destroys the Deque and releases all allocated memory.
 *
 * @pre The Deque object exists
 * @return void
 * @post All dynamically allocated memory is freed.
 */
Deque::~Deque() {
    for (size_t i = 0; i < num_blocks; ++i) {
        delete[] blockmap[i];
    }
    delete[] blockmap;
}

/**
 * Expands the blockmap to accommodate more elements by adding a new block and re-mapping existing elements.
 *
 * @pre The Deque has reached its current capacity
 * @return void
 * @post A new block is added, and all existing elements are correctly re-mapped to the new blockmap.
 */
void Deque::expand_blockmap() {
    size_t new_blocks = num_blocks + 1;
    int** new_map = new int*[new_blocks];
    for (size_t i = 0; i < new_blocks; ++i) {
        new_map[i] = new int[block_size];
    }

    // Re-map existing elements to the new blockmap
    size_t current = front_index;
    for (size_t i = 0; i < current_size; ++i) {
        new_map[i / block_size][i % block_size] = blockmap[current / block_size][current % block_size];
        current = (current + 1) % capacity;
    }

    // Clean up old blockmap
    for (size_t i = 0; i < num_blocks; ++i) {
        delete[] blockmap[i];
    }
    delete[] blockmap;

    blockmap = new_map;
    num_blocks = new_blocks;
    capacity += block_size;

    // Reset front and back indices
    front_index = 0;
    back_index = current_size;
}

/**
 * Adds an element to the front of the deque.
 *
 * @param value The value to be added to the front
 * @pre None
 * @return void
 * @post The element is added to the front, and the front index is adjusted appropriately.
 */
void Deque::push_front(int value) {
    if (current_size == capacity) {
        expand_blockmap();
    }
    front_index = (front_index == 0) ? capacity - 1 : front_index - 1; // Wrap-around logic
    blockmap[front_index / block_size][front_index % block_size] = value;
    ++current_size;
}

/**
 * Adds an element to the back of the deque.
 *
 * @param value The value to be added to the back
 * @pre None
 * @return void
 * @post The element is added to the back, and the back index is adjusted appropriately.
 */
void Deque::push_back(int value) {
    if (current_size == capacity) {
        expand_blockmap();
    }
    blockmap[back_index / block_size][back_index % block_size] = value;
    back_index = (back_index + 1) % capacity; // Wrap-around logic
    ++current_size;
}

/**
 * Removes the element at the front of the deque.
 *
 * @pre The deque is not empty
 * @return void
 * @post The front element is removed, and the front index is adjusted appropriately.
 */
void Deque::pop_front() {
    if (empty()) throw out_of_range("Deque is empty");
    front_index = (front_index + 1) % capacity; // Move to the next element
    --current_size;
}

/**
 * Removes the element at the back of the deque.
 *
 * @pre The deque is not empty
 * @return void
 * @post The back element is removed, and the back index is adjusted appropriately.
 */
void Deque::pop_back() {
    if (empty()) throw out_of_range("Deque is empty");
    back_index = (back_index == 0) ? capacity - 1 : back_index - 1; // Adjust back_index for circular deque
    --current_size; // Decrease the size
}

/**
 * Retrieves the element at the front of the deque.
 *
 * @pre The deque is not empty
 * @return int The value at the front of the deque
 * @post The front element is returned without being removed.
 */
int Deque::front() const {
    if (empty()) throw out_of_range("Deque is empty");
    return blockmap[front_index / block_size][front_index % block_size];
}

/**
 * Retrieves the element at the back of the deque.
 *
 * @pre The deque is not empty
 * @return int The value at the back of the deque
 * @post The back element is returned without being removed.
 */
int Deque::back() const {
    if (empty()) throw out_of_range("Deque is empty");
    size_t last_index = (back_index == 0) ? capacity - 1 : back_index - 1; // Access the last valid element
    return blockmap[last_index / block_size][last_index % block_size];
}

/**
 * Checks if the deque is empty.
 *
 * @pre None
 * @return bool Returns true if the deque is empty, false otherwise
 * @post The empty state of the deque is returned.
 */
bool Deque::empty() const {
    return current_size == 0;
}

/**
 * Retrieves the current size of the deque.
 *
 * @pre None
 * @return size_t The number of elements currently in the deque
 * @post The size of the deque is returned.
 */
size_t Deque::size() const {
    return current_size;
}

/**
 * Provides access to the element at the given index.
 *
 * @param index The index of the element to retrieve
 * @pre `index` is within the range [0, current_size)
 * @return int& A reference to the element at the specified index
 * @post The element at the specified index is returned by reference.
 */
int& Deque::operator[](size_t index) {
    if (index >= current_size) throw out_of_range("Index out of range");
    size_t actual_index = (front_index + index) % capacity; // Map logical index to physical location
    return blockmap[actual_index / block_size][actual_index % block_size];
}
