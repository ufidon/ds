# Overview of data structures


Objectives
---
- Understanding various `common data structures`, such as 
  - `arrays, linked lists, stacks, queues, trees, graphs`, etc.
- Mastering `basic operations` of data structures, including 
  - `creating, disposing, insertion, deletion, searching, traversal`, etc.
- Understanding the `characteristics and applicable scenarios` of data structures
  - and `selecting appropriate data structures` to solve specific problems
- Familiarizing oneself with `common data structure algorithms`, such as 
  - `sorting algorithms, searching algorithms, graph algorithms`, etc.
- Mastering the `storage and implementation methods` of data structures, including 
  - the `storage structures of arrays, linked lists, trees`, etc.
- Understanding the `time complexity and space complexity` of data structures
  - and `evaluating the efficiency and performance` of algorithms
- Learning the `design principles and techniques` of data structures, including 
  - `recursion, dynamic programming, greedy algorithms`, etc.
- Practicing and exercising, deepening understanding and `application` of data structures through `coding and problem-solving`


Data structures (DSes)
---
- include `two` main categories:
- `Linear Structures`: indexers have a `one-to-one relationship` with data elements
  - `Arrays`: store elements in `contiguous memory locations` and allow fast access via indices
  - `Linked Lists`: each element contains `data and a pointer` to the next element, allowing for dynamic memory allocation
  - `Stacks`: A `Last-In-First-Out (LIFO)` data structure 
    - allows `insertion and deletion operations only at the top`
  - `Queues`: A `First-In-First-Out (FIFO)` data structure 
    - allows `insertion at the rear and deletion at the front`
- `Nonlinear Structures`: indexers have a `one-to-many or many-to-many relationship` with data elements
  - `Trees`: `hierarchical` data structures 
    - include binary trees, binary search trees, balanced trees, etc.
  - `Heaps`: A special tree-based data structure commonly used to implement `priority queues`
  - `Graphs`: consist of `nodes and edges`
    - relationships between nodes can be `arbitrary` indicated by the edges


Applications of DSes
---
- `Arrays`:
  - Storing and accessing elements in a list of `student grades`.
  - Implementing `image processing` algorithms where pixels are stored in a `two-dimensional array`.
  - Representing `sparse matrices` where most elements are zero.
- `Linked Lists`:
  - Implementing `dynamic memory allocation` in languages like C and C++.
  - Representing `adjacency lists` in `graph data structures`.
  - Implementing `undo functionality` in text editors or command history in shells.
- `Stacks`:
  - Implementing `function call stack` in programming languages.
  - Parsing and evaluating `arithmetic expressions`.
  - Implementing `backtracking algorithms` in solving problems like the Tower of Hanoi or maze traversal.
- `Queues`:
  - Managing tasks in a `print queue` of a printer.
  - Implementing `breadth-first` search in graph traversal algorithms.
  - Simulating `waitlists` or queues in a customer service system.
- `Trees`:
  - Representing `hierarchical` data structures like `file systems`.
  - Implementing `symbol tables and dictionaries` in compilers and interpreters.
  - Optimizing `searching, sorting, and insertion` operations in `self-balancing binary search trees`.
- `Graphs`:
  - Modeling `social networks`, with nodes representing individuals and edges representing connections.
  - Implementing `navigation systems` to find the `shortest path` between locations.
  - Representing `dependencies` between tasks in project management software.
- `Heaps`:
  - Implementing `priority queues` in `task scheduling` algorithms.
  - Finding the `k largest or smallest elements` in a collection efficiently.
  - Implementing efficient algorithms for `heap sort and heap-based binary search`


Analysis methods for DSes and algorithms
---
- `Problem Analysis`: specifies the problem requirements and constraints, including
  - the types and scales of input data
  - the expected output results
- `Selecting Appropriate Data Structures`: based on the problem characteristics and requirements
  - stores and organizes data 
  - improves the efficiency and performance of the algorithm
- `Algorithm Design`: according to the selected `data structures` and the `problem's characteristics` including
  - complexity, feasibility, and efficiency
  - can be designed using `top-down` or `bottom-up` approaches, including 
    - divide and conquer, greedy algorithms, dynamic programming, backtracking, etc.
- `Analyzing the Algorithm's Time and Space Complexity`: 
  - `Time complexity` describes how the algorithm's `execution time varies with the input size`
  - `Space complexity` describes the `memory space required` by the algorithm `during execution`
- `Implementing the Algorithm`: into code using a specific programming language considering factors such as 
  - code readability, maintainability, and efficiency
  - Testing and debugging should be conducted regularly to ensure the correctness and stability of the algorithm
- `Testing and Optimization`: verify its correctness and performance under various circumstances. Based on the test results, optimize the algorithm, which may involve adjusting the implementation or selecting different data structures to improve efficiency and performance.
