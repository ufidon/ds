Binary Heap
---
- Heap properties
  - Shape property: It is a `complete binary tree`
     - each non-last level is full
     - the `last level` may not be full and all its leaves are `placed leftmost`
  - Heap property: 
    - Max heap: each node is `greater than or equal to` any of its children
    - Min heap: each node is `less than or equal to` any of its children
- A binary heap can be stored in a vector or an array if the heap size is known in advance
  - The `root` is at position `0`, 
    - its two children are at positions 1 and 2 
  - For a node at position `i` 
    - its `left` child is at position `2i + 1`
    - its `right` child is at position `2i + 2` 
    - its `parent` is at `⌊(i - 1)/2⌋`


💡 Intuition
---
- [Heap animation](https://csvistool.com/Heap)
- If the underlying array `indexes from 1`, then
  - The `root` is at position `1`, 
    - its two children are at positions 2 and 3 
  - For a node at position `k` 
    - its `left` child is at position `2k`
    - its `right` child is at position `2k + 1` 
    - its `parent` is at `⌊k/2⌋`


The max heap class
---
- The `void insert(T value)` method `heapify-up (or bubble-up) to restore the heap property`
  1. appends the the new node with value to the heap
     - i.e. as the last element of the array
  2. swaps the node with its parent if the node is greater than its parent
     - This process continues until the new node becomes the root or is not greater than its parent
- The `T extractMax()` method `heapify-down (or bubble-down) to restore the heap property`
  - removes and returns the root, To maintain the heap property, 
    - moves the last node to the root position 
    - swaps it with its larger child if it is less than the larger child 
  - This process continues until the last node becomes a leaf or is not less than its children


🏃 Implementation
---
```c++
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class MaxHeap
{
private:
  std::vector<T> heap;

  void heapifyUp(int index)
  {
    if (index == 0)
      return;
    int parentIndex = (index - 1) / 2;
    if (heap[index] > heap[parentIndex])
    {
      drawHeap();
      std::swap(heap[index], heap[parentIndex]);
      drawHeap();

      heapifyUp(parentIndex);
    }
  }

  void heapifyDown(int index)
  {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap.size() && heap[leftChild] > heap[largest])
      largest = leftChild;

    if (rightChild < heap.size() && heap[rightChild] > heap[largest])
      largest = rightChild;

    if (largest != index)
    {
      drawHeap();
      std::swap(heap[index], heap[largest]);
      drawHeap();
      heapifyDown(largest);
    }
  }

  int getParent(int index)
  {
    if (isEmpty())
    {
      std::cout << "Heap is empty" << std::endl;
      return -1;
    }
    else if (index == 0)
    {
      std::cout << "root has NO parent!" << std::endl;
      return -1;
    }
    else
      return (index - 1) / 2;
  }
  int getRightChild(int index)
  {
    int ri = 2 * index + 2;
    if (isEmpty())
    {
      std::cout << "Heap is empty" << std::endl;
      return -2;
    }
    else if (ri >= heap.size())
    {
      return -1;
    }
    else
      return ri;
  }
  int getLeftChild(int index)
  {
    int li = 2 * index + 1;
    if (isEmpty())
    {
      std::cout << "Heap is empty" << std::endl;
      return -2;
    }
    else if (li >= heap.size())
    {
      return -1;
    }
    else
      return li;
  }

public:
  void insert(T value)
  {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
  }

  T extractMax()
  {
    if (heap.size() == 0)
      throw std::out_of_range("Heap is empty");

    drawHeap();
    T root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return root;
  }

  T getMax() const
  {
    if (heap.size() == 0)
      throw std::out_of_range("Heap is empty");

    return heap[0];
  }

  bool isEmpty() const
  {
    return heap.size() == 0;
  }

  void printHeap(void)
  {
    if (!isEmpty())
    {
      for (auto &e : heap)
      {
        std::cout << e << " ";
      }
      std::cout << std::endl;
    }
  }

  void drawHeap(std::string indent, int index, char sign = ' ')
  {
    if (!isEmpty() && index != -1)
    {
      drawHeap(indent + "   ", getRightChild(index), ',');
      std::cout << indent + sign + "--" << heap[index] << std::endl;
      drawHeap(indent + "   ", getLeftChild(index), '`');
    }
  }
  void drawHeap()
  {
    printHeap();
    drawHeap("", 0);
    std::cout << std::endl;
  }
};

int main()
{
  MaxHeap<int> maxHeap;

  maxHeap.insert(10);
  std::cout << "Heapified: " << std::endl;
  maxHeap.drawHeap();
  std::cout << "--------------------------\n" << std::endl;

  maxHeap.insert(20);
  std::cout << "Heapified: " << std::endl;
  maxHeap.drawHeap();
  std::cout << "--------------------------\n" << std::endl;

  maxHeap.insert(5);
  std::cout << "Heapified: " << std::endl;
  maxHeap.drawHeap();
  std::cout << "--------------------------\n" << std::endl;

  maxHeap.insert(30);
  std::cout << "Heapified: " << std::endl;
  maxHeap.drawHeap();
  std::cout << "--------------------------\n" << std::endl;

  std::cout << "Max element: " << maxHeap.getMax() << std::endl;
  std::cout << "Extracted max element: " << maxHeap.extractMax() << std::endl;
  std::cout << "Heapified: " << std::endl;
  maxHeap.drawHeap();
  std::cout << "--------------------------\n" << std::endl;
  std::cout << "Max element after extraction: " << maxHeap.getMax() << std::endl;

  return 0;
}
```


Heap sort
---
- creates a heap and add all the elements from the vector
- removes all the elements from the heap and put back to the vector

```c++
template <typename T>
void heapSort(std::vector<T> &vec)
{
  MaxHeap<T> heap(vec);
  for (size_t i = 0; i < vec.size(); i++)
  {
    vec[i] = heap.extractMax();
  }
}
```  
- Time complexity: $𝐎(n\log n)$ for all cases


Priority queue
---
- Supports efficient retrieval of the highest (or lowest) priority element
- Commonly implemented with a binary heap
- Provided a `std::priority_queue` class template in C++ STL


Characteristics of `std::priority_queue`
---
- **Container Adapter**: it is built on top of another container to provide specific functionalities
  - using `std::vector` by default as the underlying container
- **Default Ordering**: it implements a `max-heap` by default 
  - i.e. the `largest element` has the highest priority and is `at the front`
- **Custom Ordering**: A `min-heap` can be created by providing a `custom comparator` to customize the ordering


Key member functions of `std::priority_queue`
---
- `push(const T& value)`: inserts a new element into the priority queue
- `pop()`: removes the top (highest priority) element from the priority queue
- `top() const`: returns a reference to the top (highest priority) element
- `empty() const`: checks if the priority queue is empty
- `size() const`: returns the number of elements in the priority queue


🍎 Example
---
```c++
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater

int main()
{
  std::cout << "----1. Demonstrating how to use std::priority_queue----" << std::endl;
  // Create a max-heap priority queue
  std::priority_queue<int> maxHeap;

  // Insert elements into the priority queue
  maxHeap.push(10);
  maxHeap.push(20);
  maxHeap.push(5);
  maxHeap.push(30);

  // Display and remove elements in priority order
  while (!maxHeap.empty())
  {
    std::cout << "Top element: " << maxHeap.top() << std::endl;
    maxHeap.pop();
  }

  std::cout << "----2. Custom comparator by std::greater<T>----" << std::endl;
  // Create a min-heap priority queue
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  // Insert elements into the priority queue
  minHeap.push(10);
  minHeap.push(20);
  minHeap.push(5);
  minHeap.push(30);

  // Display and remove elements in priority order
  while (!minHeap.empty())
  {
    std::cout << "Top element: " << minHeap.top() << std::endl;
    minHeap.pop();
  }

  std::cout << "----3. Custom comparator by a custom lambda function----" << std::endl;

  // Custom comparator for a min-heap
  auto cmp = [](int left, int right)
  { return left > right; };

  // Create a min-heap priority queue with the custom comparator
  std::priority_queue<int, std::vector<int>, decltype(cmp)> minHeap2(cmp);

  // Insert elements into the priority queue
  minHeap2.push(10);
  minHeap2.push(20);
  minHeap2.push(5);
  minHeap2.push(30);

  // Display and remove elements in priority order
  while (!minHeap2.empty())
  {
    std::cout << "Top element: " << minHeap2.top() << std::endl;
    minHeap2.pop();
  }

  return 0;
}
```