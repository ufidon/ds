# Overview of data structures

How do we represent data?
---
<table border="1">
  <tr>
    <th>Feature</th>
    <th>C Primitive Type</th>
    <th>C Struct</th>
    <th>C++ Primitive Type</th>
    <th>C++ Struct</th>
    <th>C++ Class</th>
  </tr>
  <tr>
    <td><strong>Access Specifiers</strong></td>
    <td>N/A</td>
    <td>All public</td>
    <td>N/A</td>
    <td>Public by default</td>
    <td>Private by default</td>
  </tr>
  <tr>
    <td><strong>Inheritance</strong></td>
    <td>N/A</td>
    <td>Not supported</td>
    <td>N/A</td>
    <td>Supported</td>
    <td>Supported</td>
  </tr>
  <tr>
    <td><strong>Methods</strong></td>
    <td>N/A</td>
    <td>Not supported</td>
    <td>N/A</td>
    <td>Supported</td>
    <td>Supported</td>
  </tr>
  <tr>
    <td><strong>Constructors/Destructors</strong></td>
    <td>N/A</td>
    <td>Not supported</td>
    <td>N/A</td>
    <td>Supported</td>
    <td>Supported</td>
  </tr>
  <tr>
    <td><strong>Encapsulation</strong></td>
    <td>N/A</td>
    <td>Not supported</td>
    <td>N/A</td>
    <td>Supported</td>
    <td>Supported</td>
  </tr>
  <tr>
    <td><strong>Polymorphism</strong></td>
    <td>N/A</td>
    <td>Not supported</td>
    <td>N/A</td>
    <td>Supported (with virtual functions)</td>
    <td>Supported (with virtual functions)</td>
  </tr>
  <tr>
    <td><strong>Example</strong></td>
    <td>int, char</td>
    <td>
      struct Point {<br>
        int x, y;<br>
      };
    </td>
    <td>int, char</td>
    <td>
      struct Point {<br>
        int x, y;<br>
        void print() {<br>
          std::cout << x << ", " << y << std::endl;<br>
        }<br>
      };
    </td>
    <td>
      class Point {<br>
        int x, y;<br>
      public:<br>
        Point(int x, int y) : x(x), y(y) {}<br>
        void print() {<br>
          std::cout << x << ", " << y << std::endl;<br>
        }<br>
      };
    </td>
  </tr>
</table>


How do we hold data?
---
<table border="1">
  <tr>
    <th></th>
    <th>Stack (C/C++)</th>
    <th>Heap (C)</th>
    <th>Heap (C++)</th>
  </tr>
    <tr>
    <td><strong>Memory Allocation</strong></td>
    <td>Automatic allocation (for local variables)</td>
    <td>Dynamic allocation (using `malloc` and `free`)</td>
    <td>Dynamic allocation (using `new` and `delete`)</td>
  </tr>
  <tr>
    <td><strong>Lifetime</strong></td>
    <td>Until the scope ends</td>
    <td>Until manually freed</td>
    <td>Until manually deleted</td>
  </tr>
  <tr>
    <td><strong>Size</strong></td>
    <td>Smaller (limited by the operating system)</td>
    <td>Larger (limited by system memory)</td>
    <td>Larger (limited by system memory)</td>
  </tr>
  <tr>
    <td><strong>Access Speed</strong></td>
    <td>Faster</td>
    <td>Slower</td>
    <td>Slower</td>
  </tr>
  <tr>
    <td><strong>Usage</strong></td>
    <td>For small data with simple lifetimes</td>
    <td>For large data or complex lifetimes</td>
    <td>For large data or complex lifetimes</td>
  </tr>
  <tr>
    <td><strong>Single Object Allocation</strong></td>
    <td>
      // Stack allocation<br>
      int x = 10;
    </td>
    <td>
      // Heap allocation<br>
      int* ptr = (int*)malloc(sizeof(int));<br>
      *ptr = 10;
    </td>
    <td>
      // Heap allocation<br>
      int* ptr = new int;<br>
      *ptr = 10;
    </td>
  </tr>
  <tr>
    <td><strong>Single Object Deallocation</strong></td>
    <td>
      // Automatic deallocation when the scope ends
    </td>
    <td>
      // Heap deallocation<br>
      free(ptr);
    </td>
    <td>
      // Heap deallocation<br>
      delete ptr;
    </td>
  </tr>
  <tr>
    <td><strong>Array Allocation</strong></td>
    <td>
      // Stack allocation<br>
      int arr[5] = {0, 1, 2, 3, 4};
    </td>
    <td>
      // Heap allocation<br>
      int* arr = (int*)malloc(5 * sizeof(int));<br>
      for(int i = 0; i < 5; ++i) arr[i] = i;
    </td>
    <td>
      // Heap allocation<br>
      int* arr = new int[5];<br>
      for(int i = 0; i < 5; ++i) arr[i] = i;
    </td>
  </tr>
  <tr>
    <td><strong>Array Deallocation</strong></td>
    <td>
      // Automatic deallocation when the scope ends
    </td>
    <td>
      // Heap deallocation<br>
      free(arr);
    </td>
    <td>
      // Heap deallocation<br>
      delete[] arr;
    </td>
  </tr>
</table>



How do we organize and store data with ${n}$ elements? 
---
- Data structures are also called `containers`
  - used to hold ${n \in ℕ}$, i.e. 0 or more elements
  - designed to be **dynamically growable** in `capacity`
- Linear data structures

<table border="1">
  <tr>
    <th>Data Structure</th>
    <th>Definition</th>
    <th>Properties</th>
    <th>Example</th>
  </tr>
  <tr>
    <td><strong>Array</strong></td>
    <td>Collection of elements of the same type placed in contiguous memory locations.</td>
    <td>Fixed size, random access, index-based.</td>
    <td>
      int numbers[5] = {1, 2, 3, 4, 5};
    </td>
  </tr>
  <tr>
    <td><strong>Linked List</strong></td>
    <td>Collection of nodes where each node contains data and a reference or pointer to the next node.</td>
    <td>Dynamic size, sequential access.</td>
    <td>
      struct Node {<br>
        int data;<br>
        Node* next;<br>
      };
    </td>
  </tr>
  <tr>
    <td><strong>Stack</strong></td>
    <td>Collection of elements that follows the Last-In-First-Out (LIFO) principle.</td>
    <td>Dynamic size, LIFO, insert and delete only the top element.</td>
    <td>
      std::stack<int> stack;<br>
      stack.push(10);<br>
      stack.pop();
    </td>
  </tr>
  <tr>
    <td><strong>Queue</strong></td>
    <td>Collection of elements that follows the First-In-First-Out (FIFO) principle.</td>
    <td>Dynamic size, FIFO, delete at the front and insert at the back.</td>
    <td>
      std::queue<int> queue;<br>
      queue.push(10);<br>
      queue.pop();
    </td>
  </tr>
</table>


- Nonlinear data structures: 

<table border="1">
  <tr>
    <th>Data Structure</th>
    <th>Definition</th>
    <th>Properties</th>
    <th>Example</th>
  </tr>
  <tr>
    <td><strong>Tree</strong></td>
    <td>A hierarchical structure with a root value and subtrees of children, with no cycles.</td>
    <td>Hierarchical, each node can have any number of children.</td>
    <td>
      struct TreeNode {<br>
        int value;<br>
        TreeNode* left;<br>
        TreeNode* right;<br>
      };
    </td>
  </tr>
  <tr>
    <td><strong>Graph</strong></td>
    <td>A collection of nodes (vertices) connected by edges.</td>
    <td>Can be directed or undirected, cyclic or acyclic, weighted or unweighted.</td>
    <td>
      struct GraphNode {<br>
        int value;<br>
        std::vector<GraphNode*> neighbors;<br>
      };
    </td>
  </tr>
  <tr>
    <td><strong>Heap</strong></td>
    <td>A special tree-based data structure that satisfies the heap property.</td>
    <td>Can be a max-heap or min-heap, used in priority queues.</td>
    <td>
      std::priority_queue<int> maxHeap;
    </td>
  </tr>
  <tr>
    <td><strong>Hash Table</strong></td>
    <td>A data structure that implements an associative array, a structure that can map keys to values.</td>
    <td>Provides fast insertion, deletion, and lookup.</td>
    <td>
      std::unordered_map<std::string, int> hashMap;
    </td>
  </tr>
</table>


ADTs (Abstract data types) vs data structures
---
- ADTs define `a set of data and operations` that can be performed on these data
- Data structures are the `concrete ways of organizing and storing data` to implement ADTs

| Feature | Abstract Data Type (ADT) | Data Structure |
|---------|--------------------------|----------------|
| **Definition** | A `mathematical model` that defines a set of data and a set of operations on the data | The `actual representation` of data, used to implement an ADT. |
| **Purpose** | Defines the `type of data and operations` without concern for the actual representation of data. | Provides `concrete methods` for storing and manipulating data to implement an ADT. |
| **Examples** | Stack, Queue, List | Linked List, Array, Tree |
| **Focus** | `Logical properties` and effects of operations | `Physical layout` and efficiency of data |
| **Implementation** | Typically described in `pseudocode` or natural language | Typically coded in a `programming language` |


Applications of DSes
---
| Data Structure | Use Cases | Examples |
| -------------- | --------- | -------- |
| **Arrays** | - Storing and accessing elements in a list of student grades. <br> - Implementing image processing algorithms where pixels are stored in a two-dimensional array. <br> - Representing sparse matrices where most elements are zero. | - `int grades[10];` <br> - `int image[width][height];` <br> - `int sparseMatrix[10][10];` |
| **Linked Lists** | - Implementing dynamic memory allocation in languages like C and C++. <br> - Representing adjacency lists in graph data structures. <br> - Implementing undo functionality in text editors or command history in shells. | - `struct Node { int data; Node* next; };` <br> - `List<int> adjacencyList[numVertices];` <br> - `List<Command> history;` |
| **Stacks** | - Implementing function call stack in programming languages. <br> - Parsing and evaluating arithmetic expressions. <br> - Implementing backtracking algorithms in solving problems like the Tower of Hanoi or maze traversal. | - `std::stack<int> callStack;` <br> - `std::stack<char> operators;` <br> - `std::stack<Move> moves;` |
| **Queues** | - Managing tasks in a print queue of a printer. <br> - Implementing breadth-first search in graph traversal algorithms. <br> - Simulating waitlists or queues in a customer service system. | - `std::queue<PrintJob> printQueue;` <br> - `std::queue<Node*> bfsQueue;` <br> - `std::queue<Customer> serviceQueue;` |
| **Trees** | - Representing hierarchical data structures like file systems. <br> - Implementing symbol tables and dictionaries in compilers and interpreters. <br> - Optimizing searching, sorting, and insertion operations in self-balancing binary search trees. | - `struct TreeNode { int value; TreeNode* left; TreeNode* right; };` <br> - `TreeMap<String, Symbol> symbolTable;` <br> - `AVLTree<int> balanceTree;` |
| **Graphs** | - Modeling social networks, with nodes representing individuals and edges representing connections. <br> - Implementing navigation systems to find the shortest path between locations. <br> - Representing dependencies between tasks in project management software. | - `Graph<Person> socialNetwork;` <br> - `Graph<Location> navigationMap;` <br> - `Graph<Task> taskDependencies;` |
| **Heaps** | - Implementing priority queues in task scheduling algorithms. <br> - Finding the k largest or smallest elements in a collection efficiently. <br> - Implementing efficient algorithms for heap sort and heap-based binary search. | - `std::priority_queue<Task> taskScheduler;` <br> - `MinHeap<int> minHeap;` <br> - `MaxHeap<int> maxHeap;` |


How do we process data?
---
- acquire, create, destroy, store
- compare, search, traverse
- move, copy, combine, split
- sort, transform, aggregate
- extend, compress
- analyze, mine, visualize


Algorithm
---
- `A set of instructions or a step-by-step process` 
  - used to solve a specific problem: `Input —Algorithms→ Output`
- Used in various fields such as artificial intelligence, databases, graphics, networking, operating systems, and security. 
- The `efficiency` of an algorithm is often measured by its `complexity`
  - `complexity` refers to the `amount of resources (like time or memory)` required to solve a problem as `the size of the input grows`



🍎 Example
---
| Algorithm | Definition | Complexity | Application |
|-----------|------------|------------|-------------|
| Bubble Sort | A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. | Average: $O(n^2)$ | Used in educational settings for teaching sorting algorithms. |
| Quicksort | An efficient sorting algorithm that uses a divide-and-conquer approach to sort elements. | Average: $O(n \log n)$ | Widely used in practice for sorting large datasets. |
| Merge Sort | A divide-and-conquer algorithm that divides the input array into two halves, sorts them, and then merges them. | Average: $O(n \log n)$ | Useful in sorting linked lists and for external sorting. |
| Binary Search | A search algorithm that finds the position of a target value within a sorted array by repeatedly dividing the search interval in half. | Average: $O(\log n)$ | Efficient for searching in large sorted arrays. |
| Dijkstra's Algorithm | An algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. | Average: $O(V^2)$, with $V$ being the number of vertices. | Used in GPS systems to find the shortest path. |



Course Objectives
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
