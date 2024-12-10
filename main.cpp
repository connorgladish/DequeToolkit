/**
 * @file main.cpp
 * @author CJ Gladish, Reece Cosbey
 * @date 2024-12-09
 * @brief Tests the Deque class through a menu.
 * 
 * 
 */
#include "deque.h"
#include <iostream>
#include <cassert>
#include <random>
#include <vector>
using namespace std;

/**
 * Performs a single random operation on the deque for stress testing.
 *
 * @param d The deque object being tested
 * @param reference A vector used as a reference to validate deque behavior
 * @param generator A random number generator
 * @param operation_count The current operation count for display
 * @pre `d` is initialized and ready for operations
 * @return void
 * @post A single random operation (push_front, push_back, pop_front, or pop_back) has been performed on the deque
 */
void perform_random_operation(Deque& d, vector<int>& reference, default_random_engine& generator, int operation_count) {
    uniform_int_distribution<int> distribution(1, 1000); // Range of values
    uniform_int_distribution<int> operation_dist(0, 3);  // Random operation type
    int op = operation_dist(generator);
    int value = distribution(generator);

    switch (op) {
    case 0: // push_front
        cout << "Operation " << operation_count << ": push_front(" << value << ")" << endl;
        d.push_front(value);
        reference.insert(reference.begin(), value);
        break;
    case 1: // push_back
        cout << "Operation " << operation_count << ": push_back(" << value << ")" << endl;
        d.push_back(value);
        reference.push_back(value);
        break;
    case 2: // pop_front
        if (!d.empty()) {
            cout << "Operation " << operation_count << ": pop_front()" << endl;
            d.pop_front();
            reference.erase(reference.begin());
        }
        break;
    case 3: // pop_back
        if (!d.empty()) {
            cout << "Operation " << operation_count << ": pop_back()" << endl;
            d.pop_back();
            reference.pop_back();
        }
        break;
    }
}

/**
 * Conducts a stress test on the deque implementation by performing a series of random operations.
 *
 * @pre The deque implementation is properly initialized
 * @return void
 * @post Random operations have been performed, and the implementation has been validated against a reference vector
 */
void stress_test() {
    cout << "\nStarting stress test...\n" << endl;

    Deque d;
    const int operations = 100;  // Number of random operations (reduce for better visual clarity)
    vector<int> reference;   // Reference implementation for validation
    default_random_engine generator;

    // Perform operations
    for (int i = 0; i < operations; ++i) {
        perform_random_operation(d, reference, generator, i + 1);
    }

    // Validate deque against reference
    assert(d.size() == reference.size());
    for (size_t i = 0; i < reference.size(); ++i) {
        assert(d[i] == reference[i]);
    }

    cout << "\nStress test passed successfully!" << endl;
}

/**
 * Tests operations on an empty deque to verify proper exception handling.
 *
 * @pre The deque is empty
 * @return void
 * @post Proper exceptions have been thrown for pop operations on an empty deque
 */
void test_empty_operations() {
    cout << "\nTesting operations on an empty deque...\n" << endl;

    Deque d;

    // Test pop_front on empty deque
    try {
        cout << "Attempting pop_front() on an empty deque..." << endl;
        d.pop_front();
    } catch (const out_of_range&) {
        cout << "Caught exception on pop_front as expected!" << endl;
    }

    // Test pop_back on empty deque
    try {
        cout << "Attempting pop_back() on an empty deque..." << endl;
        d.pop_back();
    } catch (const out_of_range&) {
        cout << "Caught exception on pop_back as expected!" << endl;
    }

    assert(d.empty());
    cout << "\nEmpty operations test passed!" << endl;
}

/**
 * Tests handling of a large number of elements to ensure the deque resizes correctly.
 *
 * @pre The deque is initialized
 * @return void
 * @post Large-scale pushes and pops have been tested successfully
 */
void test_large_data_handling() {
    cout << "\nTesting large data handling...\n" << endl;

    Deque d;
    const int large_size = 50; // Reduce for visualization (set to 100,000 for stress testing)

    // Push a large number of elements
    for (int i = 0; i < large_size; ++i) {
        cout << "push_back(" << i << ")" << endl;
        d.push_back(i);
    }
    assert(d.size() == large_size);

    // Verify all elements and pop back
    for (int i = large_size - 1; i >= 0; --i) {
        cout << "pop_back() -> " << d.back() << endl;
        assert(d.back() == i);
        d.pop_back();
    }
    assert(d.empty());

    cout << "\nLarge data handling test passed!" << endl;
}

/**
 * Displays the main menu for testing options.
 *
 * @pre None
 * @return void
 * @post Menu options have been printed to stdout
 */
void display_menu() {
    cout << "\n--- Deque Test Menu ---" << endl;
    cout << "1. Run Stress Test" << endl;
    cout << "2. Test Empty Operations" << endl;
    cout << "3. Test Large Data Handling" << endl;
    cout << "4. Exit" << endl;
    cout << "Select an option: ";
}

/**
 * The main function to drive the menu-based testing of the deque implementation.
 *
 * @pre None
 * @return int Returns 0 on successful execution
 * @post User-selected tests have been executed, and results have been displayed
 */
int main() {
    int choice;
    do {
        display_menu();
        cin >> choice;

        switch (choice) {
        case 1:
            stress_test();
            break;
        case 2:
            test_empty_operations();
            break;
        case 3:
            test_large_data_handling();
            break;
        case 4:
            cout << "\nExiting... Goodbye!" << endl;
            break;
        default:
            cout << "\nInvalid choice. Please try again!" << endl;
        }
    } while (choice != 4);

    return 0;
}
