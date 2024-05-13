# Array

Static Arrays
---
| Feature | One-Dimensional Array | Multi-Dimensional Array |
| ------- | --------------------- | ----------------------- |
| **Definition** | A linear collection of elements, all of the same type, stored at `contiguous memory` locations. | An array consisting of more than one dimension, such as a 2D array (matrix) or 3D array (cube), allowing for complex data structures. |
| **Declaration** | `datatype arrayName[size];` | `datatype arrayName[size1][size2]...[sizeN];` |
| **Dimensionality** | Single line of elements. | Multiple lines, creating a table (2D), cube (3D), etc. |
| **Access** | Accessed with a single index: `arrayName[index];` | Accessed with multiple indices: `arrayName[index1][index2]...[indexN];` |
| **Initialization** | Can be initialized with a single list: `int arr[] = {1, 2, 3};` | Can be initialized with nested braces: `int arr[][3] = {{1, 2, 3}, {4, 5, 6}};` |
| **Memory Layout** | Sequential in memory. | Sequential in memory but can be visualized in rows and columns (or higher dimensions). |
| **Use Cases** | - Storing a simple list of elements. <br> - Implementing data structures like stacks and queues. | - Representing complex data structures like matrices, tables, and spatial relationships. <br> - Implementing algorithms that require multi-dimensional data representation. |
| **Size Calculation** | Size is the number of elements multiplied by the size of the data type. | Size is the product of the number of elements in each dimension multiplied by the size of the data type. |
| **Example** | `int grades[10];` | `int matrix[3][4];` |


Encapsulating a fixed-size array with `std::array from <array>`
---
- `Type Safe`: Offers type safety compared to C-style arrays.
- `Performance`: comparable to C-style arrays with the added benefits of a container.
- `Member Functions`: Includes member functions like `at(), front(), back(), fill(), and swap()`.
- `Iterators`: Supports random access iterators with operations like `begin(), end(), rbegin(), and rend()`.
- `No Decay`: Unlike C-style arrays, std::array does not decay to a pointer automatically.
- `Aggregate Type`: can be initialized with aggregate-initialization.
- `Operations`: Supports `comparison` operations and can be used with algorithms that work on sequences.


```c++
#include <array>
#include <iostream>

int main() {
    std::array<int, 3> arr = {1, 2, 3};

    // Access elements
    std::cout << "First element: " << arr[0] << std::endl;

    // Modify elements
    arr[1] = 5;

    // Iterate over elements
    for (auto& el : arr) {
        std::cout << el << ' ';
    }
    std::cout << std::endl;

    return 0;
}
```

Array vs. pointer
---
<table>
  <thead>
    <tr>
      <th>Aspect</th>
      <th>Arrays</th>
      <th>Pointers</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Definition</td>
      <td>Contiguous blocks of memory used to store multiple elements of the same data type.</td>
      <td>Variables that store memory addresses of other variables or objects.</td>
    </tr>
    <tr>
      <td>Declaration</td>
      <td>Size must be known at compile time.</td>
      <td>Can be dynamically allocated or assigned.</td>
    </tr>
    <tr>
      <td>Access</td>
      <td>Elements accessed using array indexing. Example: <code>array[index]</code></td>
      <td>Elements accessed using pointer arithmetic. Example: <code>*(ptr + index)</code> (or <code>ptr[index]</code> if ptr is an array)</td>
    </tr>
    <tr>
      <td>Modification</td>
      <td>Elements can be modified directly. Example: <code>array[index] = value;</code></td>
      <td>Can be used to indirectly modify elements. Example: <code>*(ptr + index) = value;</code> (or <code>ptr[index] = value;</code> if ptr is an array)</td>
    </tr>
    <tr>
      <td>Memory Management</td>
      <td>Memory is allocated statically or dynamically (with <code>new</code>). Size cannot be changed after declaration.</td>
      <td>Pointers can be used to dynamically allocate and deallocate memory. Memory can be reallocated using <code>new</code> and <code>delete</code>. Pointers can be reassigned to different memory addresses.</td>
    </tr>
    <tr>
      <td>Example</td>
      <td>
        <pre><code>int array[5] = {1, 2, 3, 4, 5};</code></pre>
      </td>
      <td>
        <pre><code>int* ptr = new int[5];
for (int i = 0; i &lt; 5; i++) {
    *(ptr + i) = i + 1;
}
delete[] ptr;
</code></pre>
      </td>
    </tr>
  </tbody>
</table>


Dynamic array
---
- a dynamic array-like data structure
- can dynamically `resize` itself to `accommodate any number of elements`
- allows adding and removing elements dynamically


💡 Intuition
---
- [animation](https://csvistool.com/ArrayList)


🍎 Example implementation
---
```c++
#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayList
{
private:
  T *data;
  size_t capacity;
  size_t length;

  // Resizes the array when the capacity is reached
  void resize()
  {
    capacity = capacity * 2;
    T *newData = new T[capacity];
    for (size_t i = 0; i < length; ++i)
    {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }

public:
  // Constructor
  ArrayList(size_t initialCapacity = 10) : capacity(initialCapacity), length(0)
  {
    data = new T[capacity];
  }

  // Destructor
  ~ArrayList()
  {
    delete[] data;
  }

  // Adds an element to the end of the list
  void add(const T &value)
  {
    if (length == capacity)
    {
      resize();
    }
    data[length++] = value;
  }

  // Removes the element at the specified index
  void remove(size_t index)
  {
    if (index >= length)
    {
      throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < length - 1; ++i)
    {
      data[i] = data[i + 1];
    }
    --length;
  }

  // Gets the element at the specified index
  T get(size_t index) const
  {
    if (index >= length)
    {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }

  // Returns the current size of the list
  size_t size() const
  {
    return length;
  }
};

int main()
{
  ArrayList<int> list;

  // Adding elements
  list.add(1);
  list.add(2);
  list.add(3);

  // Accessing elements
  std::cout << "Element at index 1: " << list.get(1) << std::endl;

  // Removing elements
  list.remove(1);

  // Size of the list
  std::cout << "Size of list after removal: " << list.size() << std::endl;

  return 0;
}
```


C++ (STL) dynamic array - [std::vector](https://en.cppreference.com/w/cpp/header/vector)
---
```c++
#include <iostream>
#include <vector>

int main()
{
  // Initialize a vector with an initializer list
  std::vector<int> vec = {1, 2, 3, 4, 5};

  // Add elements to the vector
  vec.push_back(6);
  vec.push_back(7);

  // Access and modify elements
  vec[2] = 30;

  // Iterate over the vector and print elements
  for (int num : vec)
  {
    std::cout << num << ' ';
  }
  std::cout << std::endl;

  // Remove the last element
  vec.pop_back();

  return 0;
}
```
