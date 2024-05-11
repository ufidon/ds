# [Linked list](https://en.wikipedia.org/wiki/Linked_list)

<table>
  <thead>
    <tr>
      <th>Aspect</th>
      <th>Linked Lists</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Definition</td>
      <td>▶️ A linear data structure consisting of nodes. <br> ▶️Each node consists of two fields: data and links to other nodes<br> ▶️These nodes  usually scatter in the memory</td>
    </tr>
    <tr>
      <td>Types</td>
      <td>Singly Linked List, Doubly Linked List, Circular Linked List</td>
    </tr>
    <tr>
      <td>Features</td>
      <td>Dynamic memory allocation, Flexibility, Efficient insertion and deletion, No contiguous memory requirement</td>
    </tr>
    <tr>
      <td>Operations</td>
      <td>Insertion (beginning, end, specific position), Deletion (beginning, end, specific position), Traversal, Searching</td>
    </tr>
    <tr>
      <td>Applications</td>
      <td>Stacks and queues, Dynamic memory allocation, Task management in operating systems, Polynomial representation</td>
    </tr>
    <tr>
      <td>Example</td>
      <td>Consider a singly linked list with elements [10, 20, 30, 40]:<br>
          <code>Head -> [10] -> [20] -> [30] -> [40] -> NULL</code><br>
          Each node contains data (10, 20, 30, 40) and a `reference or pointer` to the next node.
      </td>
    </tr>
  </tbody>
</table>

💡 Intuition
---
- [Singly Linked List animation](https://liveexample.pearsoncmg.com/liang/animation/web/LinkedList.html): 
  - ![sll](https://upload.wikimedia.org/wikipedia/commons/6/6d/Singly-linked-list.svg) 
- [Doubly Linked List animation](https://web.eecs.utk.edu/~czheng4/viz/animations/linked_data_structures/dlist/dlist.html): 
  - ![dll](https://upload.wikimedia.org/wikipedia/commons/5/5e/Doubly-linked-list.svg)
- Circularly linked list: 
  - ![cll](https://upload.wikimedia.org/wikipedia/commons/d/df/Circularly-linked-list.svg)


🍎 Implementation
---
- Singly linked list

```c++
#include <iostream>

// Define the Node structure
struct Node
{
  int data;
  Node *next;

  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

// Define the SinglyLinkedList class
class SinglyLinkedList
{
private:
  Node *head;

public:
  // Constructor
  SinglyLinkedList() : head(nullptr) {}

  // Destructor to free the list
  ~SinglyLinkedList()
  {
    Node *current = head;
    while (current != nullptr)
    {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }

  // Add a new node to the front of the list
  void pushFront(int value)
  {
    Node *newNode = new Node(value, head);
    head = newNode;
  }

  // Search for a node with the given value
  Node *search(int value)
  {
    Node *current = head;
    while (current != nullptr)
    {
      if (current->data == value)
      {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

  // Insert a new node after a node with the given value
  bool insertAfter(int value, int newValue)
  {
    Node *node = search(value);
    if (node == nullptr)
    {
      return false;
    }
    Node *newNode = new Node(newValue, node->next);
    node->next = newNode;
    return true;
  }

  // Delete the first node with the given value
  bool deleteValue(int value)
  {
    if (head == nullptr)
      return false;
    if (head->data == value)
    {
      return popFront();
    }
    Node *current = head;
    while (current->next != nullptr)
    {
      if (current->next->data == value)
      {
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
      }
      current = current->next;
    }
    return false;
  }

  // Remove the first node of the list
  bool popFront()
  {
    if (head == nullptr)
      return false;
    Node *temp = head;
    head = head->next;
    delete temp;
    return true;
  }

  // Print the list
  void printList() const
  {
    Node *current = head;
    while (current != nullptr)
    {
      std::cout << current->data << " -> ";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }
};

// Example usage
int main()
{
  SinglyLinkedList list;
  list.pushFront(3);
  list.pushFront(2);
  list.pushFront(1);

  std::cout << "The list contains: ";
  list.printList();

  if (list.insertAfter(2, 4))
  {
    std::cout << "After inserting 4 after 2: ";
    list.printList();
  }

  if (list.deleteValue(3))
  {
    std::cout << "After deleting 3: ";
    list.printList();
  }

  Node *found = list.search(4);
  if (found)
  {
    std::cout << "Found node with value 4." << std::endl;
  }
  else
  {
    std::cout << "Node with value 4 not found." << std::endl;
  }

  return 0;
}
```

---
- Doubly linked list

```c++
#include <iostream>

// Define the Node structure for a doubly linked list
struct Node
{
  int data;
  Node *prev;
  Node *next;

  Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

// Define the DoublyLinkedList class
class DoublyLinkedList
{
private:
  Node *head;
  Node *tail;

public:
  // Constructor
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  // Destructor to free the list
  ~DoublyLinkedList()
  {
    while (head != nullptr)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  // Add a new node to the front of the list
  void pushFront(int value)
  {
    Node *newNode = new Node(value);
    newNode->next = head;
    if (head != nullptr)
    {
      head->prev = newNode;
    }
    else
    {
      tail = newNode;
    }
    head = newNode;
  }

  // Add a new node to the end of the list
  void pushBack(int value)
  {
    Node *newNode = new Node(value);
    newNode->prev = tail;
    if (tail != nullptr)
    {
      tail->next = newNode;
    }
    else
    {
      head = newNode;
    }
    tail = newNode;
  }

  // Insert a new node after a node with the given value
  bool insertAfter(int searchValue, int newValue)
  {
    Node *current = head;
    while (current != nullptr && current->data != searchValue)
    {
      current = current->next;
    }
    if (current == nullptr)
    {
      return false;
    }
    Node *newNode = new Node(newValue);
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr)
    {
      current->next->prev = newNode;
    }
    else
    {
      tail = newNode;
    }
    current->next = newNode;
    return true;
  }

  // Search for a node with the given value
  Node *search(int value)
  {
    Node *current = head;
    while (current != nullptr)
    {
      if (current->data == value)
      {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

  // Delete the first node with the given value
  bool deleteValue(int value)
  {
    Node *current = search(value);
    if (current == nullptr)
    {
      return false;
    }
    if (current->prev != nullptr)
    {
      current->prev->next = current->next;
    }
    else
    {
      head = current->next;
    }
    if (current->next != nullptr)
    {
      current->next->prev = current->prev;
    }
    else
    {
      tail = current->prev;
    }
    delete current;
    return true;
  }

  // Print the list from head to tail
  void printForward() const
  {
    Node *current = head;
    while (current != nullptr)
    {
      std::cout << current->data << " <-> ";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  // Print the list from tail to head
  void printBackward() const
  {
    Node *current = tail;
    while (current != nullptr)
    {
      std::cout << current->data << " <-> ";
      current = current->prev;
    }
    std::cout << "nullptr" << std::endl;
  }
};

// Example usage
int main()
{
  DoublyLinkedList list;
  list.pushFront(1);
  list.pushBack(3);
  list.insertAfter(1, 2);

  std::cout << "List printed forward: ";
  list.printForward();

  std::cout << "List printed backward: ";
  list.printBackward();

  if (list.deleteValue(2))
  {
    std::cout << "After deleting 2: ";
    list.printForward();
  }

  return 0;
}
```
---

- Rewrite in template
  - 🏃 compare it with the non-template version

```c++
#include <iostream>

// Define the Node structure for a doubly linked list
template <typename T>
struct Node
{
  T data;
  Node *prev;
  Node *next;

  Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
};

// Define the DoublyLinkedList class
template <typename T>
class DoublyLinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;

public:
  // Constructor
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  // Destructor to free the list
  ~DoublyLinkedList()
  {
    while (head != nullptr)
    {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
    }
  }

  // Add a new node to the front of the list
  void pushFront(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head;
    if (head != nullptr)
    {
      head->prev = newNode;
    }
    else
    {
      tail = newNode;
    }
    head = newNode;
  }

  // Add a new node to the end of the list
  void pushBack(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    newNode->prev = tail;
    if (tail != nullptr)
    {
      tail->next = newNode;
    }
    else
    {
      head = newNode;
    }
    tail = newNode;
  }

  // Insert a new node after a node with the given value
  bool insertAfter(const T &searchValue, const T &newValue)
  {
    Node<T> *current = head;
    while (current != nullptr && current->data != searchValue)
    {
      current = current->next;
    }
    if (current == nullptr)
    {
      return false;
    }
    Node<T> *newNode = new Node<T>(newValue);
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr)
    {
      current->next->prev = newNode;
    }
    else
    {
      tail = newNode;
    }
    current->next = newNode;
    return true;
  }

  // Search for a node with the given value
  Node<T> *search(const T &value)
  {
    Node<T> *current = head;
    while (current != nullptr)
    {
      if (current->data == value)
      {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

  // Delete the first node with the given value
  bool deleteValue(const T &value)
  {
    Node<T> *current = search(value);
    if (current == nullptr)
    {
      return false;
    }
    if (current->prev != nullptr)
    {
      current->prev->next = current->next;
    }
    else
    {
      head = current->next;
    }
    if (current->next != nullptr)
    {
      current->next->prev = current->prev;
    }
    else
    {
      tail = current->prev;
    }
    delete current;
    return true;
  }

  // Print the list from head to tail
  void printForward() const
  {
    Node<T> *current = head;
    while (current != nullptr)
    {
      std::cout << current->data << " <-> ";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  // Print the list from tail to head
  void printBackward() const
  {
    Node<T> *current = tail;
    while (current != nullptr)
    {
      std::cout << current->data << " <-> ";
      current = current->prev;
    }
    std::cout << "nullptr" << std::endl;
  }
};

// Example usage
int main()
{
  DoublyLinkedList<int> list;
  list.pushFront(1);
  list.pushBack(3);
  list.insertAfter(1, 2);

  std::cout << "List printed forward: ";
  list.printForward();

  std::cout << "List printed backward: ";
  list.printBackward();

  if (list.deleteValue(2))
  {
    std::cout << "After deleting 2: ";
    list.printForward();
  }

  return 0;
}
```

---
- Circularly linked list

```c++
#include <iostream>

// Define the Node structure for a circular linked list
template <typename T>
struct Node
{
  T data;
  Node *next;

  Node(const T &value, Node *nextNode = nullptr) : data(value), next(nextNode) {}
};

// Define the CircularLinkedList class
template <typename T>
class CircularLinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;

public:
  // Constructor
  CircularLinkedList() : head(nullptr), tail(nullptr) {}

  // Destructor to free the list
  ~CircularLinkedList()
  {
    if (head)
    {
      Node<T> *current = head;
      while (current->next != head)
      {
        Node<T> *next = current->next;
        delete current;
        current = next;
      }
      delete current;
    }
  }

  // Add a new node to the front of the list
  void pushFront(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    if (!head)
    {
      head = newNode;
      tail = newNode;
      newNode->next = head;
    }
    else
    {
      newNode->next = head;
      tail->next = newNode;
      head = newNode;
    }
  }

  // Add a new node to the end of the list
  void pushBack(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    if (!head)
    {
      head = newNode;
      tail = newNode;
      newNode->next = head;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
      tail->next = head;
    }
  }

  // Search for a node with the given value
  Node<T> *search(const T &value)
  {
    if (!head)
      return nullptr;
    Node<T> *current = head;
    do
    {
      if (current->data == value)
      {
        return current;
      }
      current = current->next;
    } while (current != head);
    return nullptr;
  }

  // Delete the first node with the given value
  bool deleteValue(const T &value)
  {
    if (!head)
      return false;
    Node<T> *current = head;
    Node<T> *prev = tail;
    do
    {
      if (current->data == value)
      {
        if (current == head)
        {
          head = head->next;
          tail->next = head;
        }
        else
        {
          prev->next = current->next;
        }
        if (current == tail)
        {
          tail = prev;
        }
        delete current;
        return true;
      }
      prev = current;
      current = current->next;
    } while (current != head);
    return false;
  }

  // Print the list
  void printList() const
  {
    if (!head)
      return;
    Node<T> *current = head;
    do
    {
      std::cout << current->data << " -> ";
      current = current->next;
    } while (current != head);
    std::cout << "(head)" << std::endl;
  }
};

// Example usage
int main()
{
  CircularLinkedList<int> list;
  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);

  std::cout << "The circular list contains: ";
  list.printList();

  if (list.deleteValue(2))
  {
    std::cout << "After deleting 2: ";
    list.printList();
  }

  Node<int> *found = list.search(3);
  if (found)
  {
    std::cout << "Found node with value 3." << std::endl;
  }
  else
  {
    std::cout << "Node with value 3 not found." << std::endl;
  }

  return 0;
}
```
---
- Add a sentinel node

```c++
#include <iostream>

// Define the Node structure for a circular doubly linked list
template <typename T>
struct Node
{
  T data;
  Node *prev;
  Node *next;

  Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
};

// Define the CircularDoublyLinkedList class
template <typename T>
class CircularDoublyLinkedList
{
private:
  Node<T> *sentinel; // Sentinel node

public:
  // Constructor
  CircularDoublyLinkedList()
  {
    sentinel = new Node<T>(T()); // Create a sentinel node with default value
    sentinel->next = sentinel;   // Initialize circular link
    sentinel->prev = sentinel;
  }

  // Destructor
  ~CircularDoublyLinkedList()
  {
    while (sentinel->next != sentinel)
    {
      Node<T> *temp = sentinel->next;
      sentinel->next = temp->next;
      delete temp;
    }
    delete sentinel;
  }

  // Add a new node to the front of the list
  void pushFront(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = sentinel->next;
    newNode->prev = sentinel;
    sentinel->next->prev = newNode;
    sentinel->next = newNode;
  }

  // Add a new node to the end of the list
  void pushBack(const T &value)
  {
    Node<T> *newNode = new Node<T>(value);
    newNode->prev = sentinel->prev;
    newNode->next = sentinel;
    sentinel->prev->next = newNode;
    sentinel->prev = newNode;
  }

  // Search for a node with the given value
  Node<T> *search(const T &value)
  {
    Node<T> *current = sentinel->next;
    while (current != sentinel)
    {
      if (current->data == value)
      {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

  // Delete the first node with the given value
  bool deleteValue(const T &value)
  {
    Node<T> *current = search(value);
    if (current == nullptr)
    {
      return false;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    return true;
  }

  // Print the list
  void printList() const
  {
    Node<T> *current = sentinel->next;
    while (current != sentinel)
    {
      std::cout << current->data << " <-> ";
      current = current->next;
    }
    std::cout << "nullptr" << std::endl;
  }
};

// Example usage
int main()
{
  CircularDoublyLinkedList<int> list;
  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);

  std::cout << "The circular doubly linked list contains: ";
  list.printList();

  if (list.deleteValue(2))
  {
    std::cout << "After deleting 2: ";
    list.printList();
  }

  Node<int> *found = list.search(3);
  if (found)
  {
    std::cout << "Found node with value 3." << std::endl;
  }
  else
  {
    std::cout << "Node with value 3 not found." << std::endl;
  }

  return 0;
}
```

C++ STL [list](https://en.cppreference.com/w/cpp/header/list)
---
<table border="1">
    <tr>
        <th>Feature</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>Type</td>
        <td><code>std::list<T></code> where <code>T</code> is the data type</td>
    </tr>
    <tr>
        <td>Underlying Structure</td>
        <td>Doubly linked list</td>
    </tr>
    <tr>
        <td>Element Access</td>
        <td>Provides access to the first (<code>front()</code>) and last (<code>back()</code>) elements</td>
    </tr>
    <tr>
        <td>Modifiers</td>
        <td>Includes functions like <code>push_front()</code>, <code>push_back()</code>, <code>pop_front()</code>, <code>pop_back()</code>, <code>insert()</code>, <code>erase()</code>, <code>clear()</code>, etc.</td>
    </tr>
    <tr>
        <td>Capacity</td>
        <td>Can dynamically grow or shrink as elements are added or removed</td>
    </tr>
    <tr>
        <td>Iterators</td>
        <td>Provides bidirectional iterators (<code>begin()</code>, <code>end()</code>, <code>rbegin()</code>, <code>rend()</code>)</td>
    </tr>
    <tr>
        <td>Operations</td>
        <td>Supports operations like <code>merge()</code>, <code>splice()</code>, <code>remove()</code>, <code>reverse()</code>, <code>sort()</code>, etc.</td>
    </tr>
    <tr>
        <td>Complexity</td>
        <td>Insertion and deletion: O(1) at beginning or end, O(n) at specific position. Traversal: O(n).</td>
    </tr>
</table>

🍎 C++ STL list
---
```c++
#include <list>
#include <iostream>

int main()
{
  std::list<int> myList{1, 2, 3, 4, 5};

  // Adding elements
  myList.push_front(0);
  myList.push_back(6);

  // Iterating over the list
  for (const auto &value : myList)
  {
    std::cout << value << ' ';
  }
  std::cout << std::endl;

  // Removing elements
  myList.pop_front();
  myList.pop_back();

  return 0;
}
```
