# Linear data structures
- Arrays
- Linked Lists
  - Singly Linked Lists
  - Doubly Linked Lists
  - Circular Lists
- Queues
  - Linked list implementation of Queues
  - Array implementation of Queues
  - Priority Queues
- Stacks
  - Linked list implementation of Stacks
  - Array implementation of Stacks
  - Applications
    - Function call stack
    - Expression evaluation, infix to postfix


Arrays
---
| Feature | One-Dimensional Array | Multi-Dimensional Array |
| ------- | --------------------- | ----------------------- |
| **Definition** | A linear collection of elements, all of the same type, stored at contiguous memory locations. | An array consisting of more than one dimension, such as a 2D array (matrix) or 3D array (cube), allowing for complex data structures. |
| **Declaration** | `datatype arrayName[size];` | `datatype arrayName[size1][size2]...[sizeN];` |
| **Dimensionality** | Single line of elements. | Multiple lines, creating a table (2D), cube (3D), etc. |
| **Access** | Accessed with a single index: `arrayName[index];` | Accessed with multiple indices: `arrayName[index1][index2]...[indexN];` |
| **Initialization** | Can be initialized with a single list: `int arr[] = {1, 2, 3};` | Can be initialized with nested braces: `int arr[][3] = {{1, 2, 3}, {4, 5, 6}};` |
| **Memory Layout** | Sequential in memory. | Sequential in memory but can be visualized in rows and columns (or higher dimensions). |
| **Use Cases** | - Storing a simple list of elements. <br> - Implementing data structures like stacks and queues. | - Representing complex data structures like matrices, tables, and spatial relationships. <br> - Implementing algorithms that require multi-dimensional data representation. |
| **Size Calculation** | Size is the number of elements multiplied by the size of the data type. | Size is the product of the number of elements in each dimension multiplied by the size of the data type. |
| **Example** | `int grades[10];` | `int matrix[3][4];` |
