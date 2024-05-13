# Priority queue

<table>
  <thead>
    <tr>
      <th>Aspect</th>
      <th>Priority Queues</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Definition</td>
      <td>A data structure similar to a regular queue but <span style="color:green">each element has an associated priority</span>.</td>
    </tr>
    <tr>
      <td>Implementation</td>
      <td>Can be implemented using various data structures like binary heaps, balanced binary search trees, or arrays.</td>
    </tr>
    <tr>
      <td>Operations</td>
      <td>▶️Insert: enqueue an element with a priority<br>▶️DeleteMax/DeleteMin: dequeue the element with the highest/lowest priority<br>▶️Peek: get the element with the highest/lowest priority without removing it</td>
    </tr>
    <tr>
      <td>Features</td>
      <td>Efficient insertion and deletion of elements based on priority, Elements are dequeued based on their priority level, Not necessarily FIFO order.</td>
    </tr>
    <tr>
      <td>Applications</td>
      <td>Task scheduling, Dijkstra's shortest path algorithm, Huffman coding, Job scheduling in operating systems.</td>
    </tr>
  </tbody>
</table>

🍎 Implementations
---
- by sorted array in descending order
  - so the highest priority element is always at the front

```c++
#include <iostream>
#include <stdexcept> // For std::runtime_error

// Template class for Priority Queue
template <typename T>
class PriorityQueue
{
private:
  T *data;         // Dynamic array to store the elements
  size_t capacity; // Maximum capacity of the priority queue
  size_t count;    // Current number of elements in the priority queue

  // Function to resize the array when full
  void resize()
  {
    size_t newCapacity = capacity * 2;
    T *newData = new T[newCapacity];
    for (size_t i = 0; i < count; ++i)
    {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
  }

public:
  // Constructor
  PriorityQueue(size_t initialCapacity = 10) : capacity(initialCapacity), count(0)
  {
    data = new T[capacity];
  }

  // Destructor
  ~PriorityQueue()
  {
    delete[] data;
  }

  // Insert element into the priority queue
  void insert(const T &element)
  {
    if (count == capacity)
    {
      resize();
    }
    data[count] = element;
    size_t i = count;
    count++;

    // Perform insertion sort to maintain the order
    while (i > 0 && data[i] > data[i - 1])
    {
      std::swap(data[i], data[i - 1]);
      i--;
    }
  }

  // Remove the element with the highest priority
  T extractMax()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Priority Queue is empty");
    }
    T maxElement = data[0];
    for (size_t i = 1; i < count; ++i)
    {
      data[i - 1] = data[i];
    }
    count--;
    return maxElement;
  }

  // Peek at the element with the highest priority without removing it
  T getMax() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Priority Queue is empty");
    }
    return data[0];
  }

  // Check if the priority queue is empty
  bool isEmpty() const
  {
    return count == 0;
  }

  // Get the size of the priority queue
  size_t size() const
  {
    return count;
  }
};

// Example usage
int main()
{
  PriorityQueue<int> pq;

  // Insert elements into the priority queue
  pq.insert(40);
  pq.insert(30);
  pq.insert(20);
  pq.insert(50);

  // Extracting elements from the priority queue
  std::cout << "Extracted max: " << pq.extractMax() << std::endl;
  std::cout << "Next max: " << pq.getMax() << std::endl;

  // Checking the size of the priority queue
  std::cout << "Priority Queue size: " << pq.size() << std::endl;

  return 0;
}
```
---

- by sorted list in descending order
  - so the highest priority element is always at the front

```c++
#include <iostream>

// Node structure for the linked list
template <typename T>
struct Node
{
  T data;
  int priority;
  Node *next;

  Node(T val, int p) : data(val), priority(p), next(nullptr) {}
};

// Priority Queue using a sorted linked list
template <typename T>
class PriorityQueue
{
private:
  Node<T> *head;

public:
  PriorityQueue() : head(nullptr) {}

  // Insert an element with a given priority
  void push(T value, int priority)
  {
    Node<T> *newNode = new Node<T>(value, priority);

    if (!head || priority > head->priority)
    {
      newNode->next = head;
      head = newNode;
    }
    else
    {
      Node<T> *temp = head;
      while (temp->next && temp->next->priority > priority)
      {
        temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }

  // Remove the element with the highest priority
  void pop()
  {
    if (!head)
    {
      throw std::runtime_error("Priority Queue is empty");
    }
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }

  // Get the element with the highest priority
  T top() const
  {
    if (!head)
    {
      throw std::runtime_error("Priority Queue is empty");
    }
    return head->data;
  }

  // Check if the priority queue is empty
  bool isEmpty() const
  {
    return !head;
  }
};

// Example usage
int main()
{
  PriorityQueue<int> pq;

  pq.push(10, 2);
  pq.push(20, 1);
  pq.push(30, 3);

  while (!pq.isEmpty())
  {
    std::cout << pq.top() << " ";
    pq.pop();
  }

  return 0;
}
```

---

- by sorted std::vector in descending order
  - so the highest priority element is always at the front

```c++
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

// Template class for Priority Queue
template <typename T>
class PriorityQueue
{
private:
  std::vector<T> data;

public:
  // Insert element into the priority queue
  void insert(const T &element)
  {
    data.push_back(element);
    // Sort the array after each insertion to maintain order
    std::sort(data.begin(), data.end(), std::greater<T>());
  }

  // Remove the element with the highest priority
  T extractMax()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Priority Queue is empty");
    }
    T maxElement = data.front();
    data.erase(data.begin()); // Remove the element from the front
    return maxElement;
  }

  // Peek at the element with the highest priority without removing it
  T getMax() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Priority Queue is empty");
    }
    return data.front();
  }

  // Check if the priority queue is empty
  bool isEmpty() const
  {
    return data.empty();
  }

  // Get the size of the priority queue
  size_t size() const
  {
    return data.size();
  }
};

// Example usage
int main()
{
  PriorityQueue<int> pq;

  // Insert elements into the priority queue
  pq.insert(30);
  pq.insert(10);
  pq.insert(20);
  pq.insert(5);

  // Extracting elements from the priority queue
  std::cout << "Extracted max: " << pq.extractMax() << std::endl;
  std::cout << "Next max: " << pq.getMax() << std::endl;

  // Checking the size of the priority queue
  std::cout << "Priority Queue size: " << pq.size() << std::endl;

  return 0;
}
```

## C++ STL std::priority_queue
- uses a `max heap` by default
  - can also be configured to use a `min heap` by providing a custom comparison function
- in the example below, the largest number is always at the top
  - elements are popped from the queue in `descending` order

```c++
#include <iostream>
#include <queue>

int main()
{
  // Create a priority queue to store integers
  std::priority_queue<int> pq;

  // Insert some elements into the priority queue
  pq.push(30);
  pq.push(20);
  pq.push(50);
  pq.push(40);
  pq.push(10);

  // Display the top element of the priority queue
  std::cout << "The top element is: " << pq.top() << std::endl;

  // Remove the top element
  pq.pop();

  // Display the top element again
  std::cout << "After pop, the top element is: " << pq.top() << std::endl;

  // Display all elements in the priority queue
  std::cout << "Elements in priority queue: ";
  while (!pq.empty())
  {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << std::endl;

  return 0;
}
```

---
- configured as a min heap using the std::greater<int> comparison function
  - the top element of the min heap is the smallest value
  - elements are removed in `ascending` order

```c++
#include <iostream>
#include <queue>

int main()
{
  // Create a min heap (priority queue) for integers
  std::priority_queue<int, std::vector<int>, std::greater<int>> my_min_heap;

  // Insert some elements into the min heap
  my_min_heap.push(30);
  my_min_heap.push(20);
  my_min_heap.push(50);
  my_min_heap.push(40);
  my_min_heap.push(10);

  // Display the top element (minimum) of the min heap
  std::cout << "The top element (minimum) is: " << my_min_heap.top() << std::endl;

  // Remove the top element
  my_min_heap.pop();

  // Display the new top element after removal
  std::cout << "After pop, the new top element is: " << my_min_heap.top() << std::endl;

  // Display all elements in the min heap
  std::cout << "Elements in the min heap: ";
  while (!my_min_heap.empty())
  {
    std::cout << my_min_heap.top() << " ";
    my_min_heap.pop();
  }
  std::cout << std::endl;

  return 0;
}
```