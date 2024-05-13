# Queue

<table border="1">
        <tr>
            <th>Feature</th>
            <th>Queue (single-ended queue)</th>
            <th>Deque (double-ended queue)</th>
        </tr>
        <tr>
            <td>Type</td>
            <td><code>std::queue&lt;T&gt;</code></td>
            <td><code>std::deque&lt;T&gt;</code></td>
        </tr>
        <tr>
            <td>Underlying Structure</td>
            <td>Typically implemented using a container like <code>std::list</code> or <code>std::deque</code></td>
            <td>Indexed sequence container with dynamic resizing</td>
        </tr>
        <tr>
            <td>Element Access</td>
            <td>Access to the front and back elements only</td>
            <td>Access to elements at both ends and by index</td>
        </tr>
        <tr>
            <td>Insertion</td>
            <td>Elements are added to the back</td>
            <td>Elements can be added to both the front and back</td>
        </tr>
        <tr>
            <td>Deletion</td>
            <td>Elements are removed from the front</td>
            <td>Elements can be removed from both the front and back</td>
        </tr>
        <tr>
            <td>Iteration</td>
            <td>Front to back iteration only</td>
            <td>Both directions (front to back, back to front)</td>
        </tr>
        <tr>
            <td>Performance</td>
            <td>Constant time O(1) for insertion and removal at the ends</td>
            <td>Constant time O(1) for insertion and removal at both ends, linear time O(n) for middle operations</td>
        </tr>
        <tr>
            <td>Use Case</td>
            <td>First-In-First-Out (FIFO) data structure</td>
            <td>Generalized queue that can be used as both stack and queue</td>
        </tr>
    </table>


💡 Intuition
---
![queue](https://upload.wikimedia.org/wikipedia/commons/5/52/Data_Queue.svg)

- Animation
  - [Array implementation](https://www.cs.usfca.edu/~galles/visualization/QueueArray.html)
  - [Linked list implementation](https://www.cs.usfca.edu/~galles/visualization/QueueLL.html)
    - [Detailed view](https://web.eecs.utk.edu/~czheng4/viz/animations/linked_data_structures/queue/queue.html)


## Queue implementation
🍎 Example: array implementation
---
- Fixed-size queue with array implementation
- 💡 [Intuition by animation](https://csvistool.com/QueueArray)

```c++
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue
{
private:
  T *arr;       // Array to store queue elements
  int capacity; // Maximum capacity of the queue
  int front;    // Front points to the front element in the queue
  int rear;     // Rear points to the last element in the queue
  int count;    // Current size of the queue

public:
  Queue(int size = 10); // Constructor with default size
  ~Queue();             // Destructor

  void enqueue(T item); // Add an item to the queue
  T dequeue();          // Remove an item from the queue
  T peek();             // Get the front item of the queue
  int size();           // Get the current size of the queue
  bool isEmpty();       // Check if the queue is empty
  bool isFull();        // Check if the queue is full
};

template <typename T>
Queue<T>::Queue(int size) : capacity(size), front(0), rear(-1), count(0)
{
  arr = new T[capacity];
}

template <typename T>
Queue<T>::~Queue()
{
  delete[] arr;
}

template <typename T>
void Queue<T>::enqueue(T item)
{
  if (isFull())
  {
    throw std::overflow_error("Queue is full");
  }
  rear = (rear + 1) % capacity;
  arr[rear] = item;
  count++;
}

template <typename T>
T Queue<T>::dequeue()
{
  if (isEmpty())
  {
    throw std::underflow_error("Queue is empty");
  }
  T item = arr[front];
  front = (front + 1) % capacity;
  count--;
  return item;
}

template <typename T>
T Queue<T>::peek()
{
  if (isEmpty())
  {
    throw std::underflow_error("Queue is empty");
  }
  return arr[front];
}

template <typename T>
int Queue<T>::size()
{
  return count;
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return (count == 0);
}

template <typename T>
bool Queue<T>::isFull()
{
  return (count == capacity);
}

// Example usage
int main()
{
  Queue<int> q(5);

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);

  std::cout << "Front element is: " << q.peek() << std::endl;
  q.dequeue();
  std::cout << "Front element is: " << q.peek() << std::endl;

  q.enqueue(4);
  std::cout << "Queue size is: " << q.size() << std::endl;

  return 0;
}
```
---

- Dynamic queue with array implementation

```c++
#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicQueue
{
private:
  T *arr;       // Array to store queue elements
  int capacity; // Maximum capacity of the queue
  int front;    // Front points to the front element in the queue
  int rear;     // Rear points to the last element in the queue
  int count;    // Current size of the queue

public:
  DynamicQueue(int initialSize = 10); // Constructor with default initial size
  ~DynamicQueue();                    // Destructor

  void enqueue(T item); // Add an item to the queue
  T dequeue();          // Remove an item from the queue
  T peek();             // Get the front item of the queue
  int size();           // Get the current size of the queue
  bool isEmpty();       // Check if the queue is empty
};

template <typename T>
DynamicQueue<T>::DynamicQueue(int initialSize) : capacity(initialSize), front(0), rear(-1), count(0)
{
  arr = new T[capacity];
}

template <typename T>
DynamicQueue<T>::~DynamicQueue()
{
  delete[] arr;
}

template <typename T>
void DynamicQueue<T>::enqueue(T item)
{
  if (count == capacity)
  {
    // Resize the array (e.g., double the capacity)
    int newCapacity = capacity * 2;
    T *newArr = new T[newCapacity];
    for (int i = 0; i < count; ++i)
    {
      newArr[i] = arr[(front + i) % capacity];
    }
    delete[] arr;
    arr = newArr;
    front = 0;
    rear = count - 1;
    capacity = newCapacity;
  }

  rear = (rear + 1) % capacity;
  arr[rear] = item;
  count++;
}

template <typename T>
T DynamicQueue<T>::dequeue()
{
  if (isEmpty())
  {
    throw std::underflow_error("Queue is empty");
  }
  T item = arr[front];
  front = (front + 1) % capacity;
  count--;
  return item;
}

template <typename T>
T DynamicQueue<T>::peek()
{
  if (isEmpty())
  {
    throw std::underflow_error("Queue is empty");
  }
  return arr[front];
}

template <typename T>
int DynamicQueue<T>::size()
{
  return count;
}

template <typename T>
bool DynamicQueue<T>::isEmpty()
{
  return (count == 0);
}

// Example usage
int main()
{
  DynamicQueue<int> q(3);

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);

  std::cout << "Front element is: " << q.peek() << std::endl;
  q.dequeue();
  std::cout << "Front element is: " << q.peek() << std::endl;

  q.enqueue(4);
  std::cout << "Queue size is: " << q.size() << std::endl;

  return 0;
}
```

---

🍎 Example: linked list implementation
---
- 💡 [Intuition by animation](https://csvistool.com/QueueLL)
```c++
#include <iostream>
#include <stdexcept>

// Node structure for the linked list
template <typename T>
struct Node
{
  T data;
  Node *next;

  Node(T val) : data(val), next(nullptr) {}
};

// Queue class using linked list
template <typename T>
class LinkedListQueue
{
private:
  Node<T> *front; // Points to the front of the queue
  Node<T> *rear;  // Points to the rear of the queue
  int size;       // Number of elements in the queue

public:
  LinkedListQueue() : front(nullptr), rear(nullptr), size(0) {}

  ~LinkedListQueue()
  {
    while (front != nullptr)
    {
      Node<T> *temp = front;
      front = front->next;
      delete temp;
    }
  }

  void enqueue(T value)
  {
    Node<T> *newNode = new Node<T>(value);
    if (rear == nullptr)
    {
      front = rear = newNode;
    }
    else
    {
      rear->next = newNode;
      rear = newNode;
    }
    size++;
  }

  T dequeue()
  {
    if (isEmpty())
    {
      throw std::underflow_error("Queue is empty");
    }
    Node<T> *temp = front;
    T value = front->data;
    front = front->next;
    if (front == nullptr)
    {
      rear = nullptr;
    }
    delete temp;
    size--;
    return value;
  }

  T peek() const
  {
    if (isEmpty())
    {
      throw std::underflow_error("Queue is empty");
    }
    return front->data;
  }

  bool isEmpty() const
  {
    return size == 0;
  }

  int getSize() const
  {
    return size;
  }
};

// Example usage
int main()
{
  LinkedListQueue<int> queue;

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  std::cout << "Front element: " << queue.peek() << std::endl;
  std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
  std::cout << "New front element: " << queue.peek() << std::endl;

  return 0;
}
```

## Deque implementation

🍎 Example
---
- implemented with array
- 💡 [intuition by animation](https://csvistool.com/DequeArray)

```c++
#include <iostream>
#include <stdexcept>

template <typename T>
class Deque
{
private:
  T *arr;       // Array to store deque elements
  int capacity; // Maximum capacity of the deque
  int front;    // Front index
  int rear;     // Rear index
  int count;    // Current size of the deque

  // Function to double the capacity of the deque
  void resize()
  {
    int newCapacity = capacity * 2;
    T *newArr = new T[newCapacity];
    int j = front;
    for (int i = 0; i < count; ++i)
    {
      newArr[i] = arr[j];
      j = (j + 1) % capacity;
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
    front = 0;
    rear = count - 1;
  }

public:
  Deque(int size = 10) : capacity(size), front(0), rear(size - 1), count(0)
  {
    arr = new T[capacity];
  }

  ~Deque()
  {
    delete[] arr;
  }

  bool isEmpty() const
  {
    return count == 0;
  }

  bool isFull() const
  {
    return count == capacity;
  }

  void insertFront(T value)
  {
    if (isFull())
    {
      resize();
    }
    front = (front - 1 + capacity) % capacity;
    arr[front] = value;
    count++;
  }

  void insertRear(T value)
  {
    if (isFull())
    {
      resize();
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;
  }

  T deleteFront()
  {
    if (isEmpty())
    {
      throw std::underflow_error("Deque is empty");
    }
    T value = arr[front];
    front = (front + 1) % capacity;
    count--;
    return value;
  }

  T deleteRear()
  {
    if (isEmpty())
    {
      throw std::underflow_error("Deque is empty");
    }
    T value = arr[rear];
    rear = (rear - 1 + capacity) % capacity;
    count--;
    return value;
  }

  T getFront() const
  {
    if (isEmpty())
    {
      throw std::underflow_error("Deque is empty");
    }
    return arr[front];
  }

  T getRear() const
  {
    if (isEmpty())
    {
      throw std::underflow_error("Deque is empty");
    }
    return arr[rear];
  }

  int size() const
  {
    return count;
  }
};

// Example usage
int main()
{
  Deque<int> myDeque;

  myDeque.insertFront(1);
  myDeque.insertRear(2);
  myDeque.insertFront(3);

  std::cout << "Front element: " << myDeque.getFront() << std::endl;
  std::cout << "Rear element: " << myDeque.getRear() << std::endl;

  myDeque.deleteFront();
  std::cout << "After deleting front, new front: " << myDeque.getFront() << std::endl;

  myDeque.deleteRear();
  std::cout << "After deleting rear, new rear: " << myDeque.getRear() << std::endl;

  return 0;
}
```

---
- implemented with doubly-linked list
- 💡 [intuition by animation](https://csvistool.com/DequeLL)

```c++
#include <iostream>

// Define the node of the doubly linked list
template <typename T>
struct Node
{
  T data;
  Node *prev;
  Node *next;

  Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

// Define the double-ended queue
template <typename T>
class Deque
{
private:
  Node<T> *front;
  Node<T> *rear;
  size_t count;

public:
  Deque() : front(nullptr), rear(nullptr), count(0) {}

  // Check if the deque is empty
  bool isEmpty() const
  {
    return (count == 0);
  }

  // Get the size of the deque
  size_t size() const
  {
    return count;
  }

  // Insert an element at the front
  void insertFront(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    if (isEmpty())
    {
      front = rear = newNode;
    }
    else
    {
      newNode->next = front;
      front->prev = newNode;
      front = newNode;
    }
    count++;
  }

  // Insert an element at the rear
  void insertRear(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    if (isEmpty())
    {
      front = rear = newNode;
    }
    else
    {
      rear->next = newNode;
      newNode->prev = rear;
      rear = newNode;
    }
    count++;
  }

  // Delete an element from the front
  void deleteFront()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Deque is empty");
    }
    Node<T> *temp = front;
    front = front->next;
    if (front)
    {
      front->prev = nullptr;
    }
    else
    {
      rear = nullptr;
    }
    delete temp;
    count--;
  }

  // Delete an element from the rear
  void deleteRear()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Deque is empty");
    }
    Node<T> *temp = rear;
    rear = rear->prev;
    if (rear)
    {
      rear->next = nullptr;
    }
    else
    {
      front = nullptr;
    }
    delete temp;
    count--;
  }

  // Get the front element
  T getFront() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Deque is empty");
    }
    return front->data;
  }

  // Get the rear element
  T getRear() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Deque is empty");
    }
    return rear->data;
  }
};

// Example usage
int main()
{
  Deque<int> deque;

  // Insert elements at the front
  deque.insertFront(1);
  deque.insertFront(2);

  // Insert elements at the rear
  deque.insertRear(3);
  deque.insertRear(4);

  // Display the front and rear elements
  std::cout << "Front element: " << deque.getFront() << std::endl;
  std::cout << "Rear element: " << deque.getRear() << std::endl;

  // Delete elements
  deque.deleteFront();
  deque.deleteRear();

  // Display the size of the deque
  std::cout << "Deque size: " << deque.size() << std::endl;

  return 0;
}
```

## C++ STL queue and deque
---
- std::queue

```c++
#include <iostream>
#include <queue>

// Function to display the queue
void showq(std::queue<int> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

int main()
{
  std::queue<int> q;

  // Inserting elements into the queue
  q.push(10);
  q.push(20);
  q.push(30);

  // Displaying the queue
  std::cout << "The queue is: ";
  showq(q);

  // Showing size of the queue
  std::cout << "Size: " << q.size() << std::endl;

  // Showing the front element
  std::cout << "Front: " << q.front() << std::endl;

  // Showing the rear element
  std::cout << "Rear: " << q.back() << std::endl;

  // Removing element from the queue
  q.pop();
  std::cout << "After pop: ";
  showq(q);

  return 0;
}
```

---
- std::deque

```c++
#include <iostream>
#include <deque>

// Function to display the deque
void showdq(std::deque<int> dq)
{
  for (auto it = dq.begin(); it != dq.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

int main()
{
  std::deque<int> dq;

  // Inserting elements at the rear
  dq.push_back(10);
  dq.push_back(20);

  // Inserting elements at the front
  dq.push_front(30);
  dq.push_front(40);

  // Displaying the deque
  std::cout << "The deque is: ";
  showdq(dq);

  // Showing size of the deque
  std::cout << "Size: " << dq.size() << std::endl;

  // Showing the front element
  std::cout << "Front: " << dq.front() << std::endl;

  // Showing the rear element
  std::cout << "Rear: " << dq.back() << std::endl;

  // Removing element from the front
  dq.pop_front();
  std::cout << "After pop_front: ";
  showdq(dq);

  // Removing element from the rear
  dq.pop_back();
  std::cout << "After pop_back: ";
  showdq(dq);

  return 0;
}
```