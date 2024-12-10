## Deque Toolkit
# CJ Gladish
# Reece Cosbey
# Date: December 9, 2024
---
## Project Overview:
This project implements a dynamic, circular deque in C++ and includes functionality to manage elements efficiently using a block-based memory structure. 
---
The implementation includes:

- A `Deque` class for dynamic memory management.
- Comprehensive methods for deque operations like pushing, popping, and indexing.
- A menu-driven testing program to validate functionality under various scenarios.
---
## Features Documented:
# Deque Class:

- **Constructor**: Initializes the deque with default values.
- **Destructor**: Cleans up all dynamically allocated memory.
- **push_front/push_back**: Add elements to the front or back.
- **pop_front/pop_back**: Remove elements from the front or back.
- **front/back**: Retrieve elements at the front or back.
- **empty**: Checks if the deque is empty.
- **size**: Returns the current size of the deque.
- **operator[]**: Accesses elements by index.
---
# Main Program:

- **Stress Test**: Performs randomized operations to test robustness.
- **Empty Operations Test**: Validates behavior with an empty deque.
- **Large Data Handling**: Tests scalability and performance.
---
This was completed by CJ Gladish and Reece Cosbey.
