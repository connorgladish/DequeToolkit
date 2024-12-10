/**
 * @file deque.h
 * @author CJ Gladish
 * @date 2024-12-09
 * @brief Defines members, classes, and declarations.
 * 
 * 
 */
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

/**
 * A Deque class implementation using a dynamic 2D array (blockmap).
 */
class Deque {
private:
    int** blockmap;  // 2D dynamic array for storing elements
    size_t block_size;  // Number of elements in each block
    size_t num_blocks;  // Number of blocks in the blockmap
    size_t capacity;  // Total capacity of the deque
    size_t current_size;  // Current number of elements in the deque
    size_t front_index;  // Index of the front element
    size_t back_index;   // Index of the next position after the last element

    /**
     * Expands the blockmap by adding a new block and re-mapping existing elements.
     *
     * @pre The deque is full and needs more capacity
     * @return void
     * @post The blockmap is expanded, and all elements are re-mapped
     */
    void expand_blockmap();

public:
    /**
     * Constructs an empty Deque.
     *
     * @pre None
     * @return void
     * @post A Deque object is initialized with default values
     */
    Deque();

    /**
     * Destroys the Deque and releases all allocated memory.
     *
     * @pre The Deque object exists
     * @return void
     * @post All dynamically allocated memory is freed
     */
    ~Deque();

    /**
     * Adds an element to the front of the deque.
     *
     * @param value The value to be added to the front
     * @pre None
     * @return void
     * @post The value is added to the front of the deque
     */
    void push_front(int value);

    /**
     * Adds an element to the back of the deque.
     *
     * @param value The value to be added to the back
     * @pre None
     * @return void
     * @post The value is added to the back of the deque
     */
    void push_back(int value);

    /**
     * Removes the element at the front of the deque.
     *
     * @pre The deque is not empty
     * @return void
     * @post The front element is removed
     */
    void pop_front();

    /**
     * Removes the element at the back of the deque.
     *
     * @pre The deque is not empty
     * @return void
     * @post The back element is removed
     */
    void pop_back();

    /**
     * Retrieves the element at the front of the deque.
     *
     * @pre The deque is not empty
     * @return int The value at the front of the deque
     * @post The front element is returned without being removed
     */
    int front() const;

    /**
     * Retrieves the element at the back of the deque.
     *
     * @pre The deque is not empty
     * @return int The value at the back of the deque
     * @post The back element is returned without being removed
     */
    int back() const;

    /**
     * Checks if the deque is empty.
     *
     * @pre None
     * @return bool Returns true if the deque is empty, false otherwise
     * @post The empty state of the deque is returned
     */
    bool empty() const;

    /**
     * Retrieves the current size of the deque.
     *
     * @pre None
     * @return size_t The number of elements in the deque
     * @post The size of the deque is returned
     */
    size_t size() const;

    /**
     * Provides access to the element at the given index.
     *
     * @param index The index of the element to retrieve
     * @pre `index` is within the range [0, current_size)
     * @return int& A reference to the element at the specified index
     * @post The element at the specified index is returned by reference
     */
    int& operator[](size_t index);
};

#endif // DEQUE_H
