# C++ STL (standard template libraries)

C++ Generics
---
- allows you to
  - write code that operates on a variety of data types while maintaining type safety
  - create functions and classes that can work with any data type without having to specify them beforehand
- implemented by two ways 
  - template functions and template classes
    - instantiated with specific data types at compile time
    - allowing the compiler to generate specialized code for each usage

💡 Template Functions
---
- parameterized with one or more types
- allow you to write a single function definition that can work with different data types

```c++
#include <iostream>

// Template function to find the maximum of two values
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Max of " << x << " and " << y << " is " << max(x, y) << std::endl;

    double a = 3.14, b = 2.71;
    std::cout << "Max of " << a << " and " << b << " is " << max(a, b) << std::endl;

    return 0;
}
```


💡 Template Classes
---
- allow you to define classes with generic types
- can be used to create classes that work with different data types

```c++
#include <iostream>

// Template class for a simple Pair
template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    T getFirst() const { return first; }
    T getSecond() const { return second; }
};

int main() {
    Pair<int> p1(5, 10);
    std::cout << "First value: " << p1.getFirst() << ", Second value: " << p1.getSecond() << std::endl;

    Pair<double> p2(3.14, 2.71);
    std::cout << "First value: " << p2.getFirst() << ", Second value: " << p2.getSecond() << std::endl;

    return 0;
}
```

🍎 Multiple typenames
---
```c++
#include <iostream>

// Define a template function that accepts two parameters and returns their sum
template <typename T1, typename T2>
T1 add(T1 a, T2 b) {
    return a + b;
}

// Define a template class that accepts two different types as parameters and stores data of these types
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    void print() {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

int main() {
    // Use the template function with type inference
    std::cout << "Sum of 3 and 4: " << add(3, 4) << std::endl;
    
    // Use the template class with specified type parameters
    Pair<int, double> p(3, 4.5);
    p.print();

    return 0;
}
```

🍎 Type parameters and non-type parameters
---
```c++
#include <iostream>

// Class template with a type parameter
template <typename T = int, int N = 5>
class Container {
private:
    T value;
public:
    Container(T val = N) : value(val) {}
    T getValue() { return value; }
};

// Function template with class template and non-type parameters
template <typename T, int N>
void printValue(Container<T> container, int multiplier) {
    std::cout << "Value: " << container.getValue() * multiplier * N << std::endl;
}

int main() {
    // Create a Container with int type and value 5
    Container<int> intContainer(5);

    // Print the value multiplied by 3
    printValue<int,4>(intContainer, 3);

    return 0;
}
```

---

C++ Standard Template Library (STL)
---
A highly efficient and reusable set of classes and functions:
- `Containers`: store objects of a particular type
  - vector, deque, list, forward_list, set, multiset, map, multimap, stack, queue, and priority_queue
- `Iterators`: provide a way to traverse the elements of a container sequentially
  - allow algorithms to operate on containers independently of their underlying structure
- `Algorithms`: perform various operations on containers or other sequences of data
  - sorting, searching, transforming, and numeric algorithms
- `Function Objects (Functors)`: can be called as if they were functions
  - often used as arguments to algorithms to customize their behavior
- `Utilities`: include various helper classes and functions, such as 
  - pair and tuple for representing pairs and tuples of objects
  - smart pointers like unique_ptr and shared_ptr for managing dynamically allocated objects

🍎 Example
---
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

int main() {
    // 1. Containers
    std::vector<int> vec = {5, 2, 8, 1, 9};

    // 2. Algorithms
    std::sort(vec.begin(), vec.end());

    // 3. Iterators
    std::ostream_iterator<int> out_it(std::cout, " ");
    std::copy(vec.begin(), vec.end(), out_it);
    std::cout << std::endl;

    // 4. Function Objects (Functors)
    struct greater_than {
        int val;
        greater_than(int v) : val(v) {}
        bool operator()(int x) const { return x > val; }
    };
    int count_greater_than_5 = std::count_if(vec.begin(), vec.end(), greater_than(5));
    std::cout << "Count of elements greater than 5: " << count_greater_than_5 << std::endl;

    // 5. Utilities
    std::pair<int, std::string> my_pair = std::make_pair(42, "hello");
    std::cout << "Pair: " << my_pair.first << ", " << my_pair.second << std::endl;

    return 0;
}
```


[C++ STL containers](https://en.cppreference.com/w/cpp/container)
---

| Container        | Description                              | Header            | Common Applications                                            |
|------------------|------------------------------------------|-------------------|----------------------------------------------------------------|
| Vector           | Dynamic array with contiguous storage    | `<vector>`        | Arrays, dynamic lists, linear search, binary search            |
| Deque            | Double-ended queue with dynamic resizing | `<deque>`         | Double-ended queues, FIFO buffer, general queue                |
| List             | Doubly linked list                       | `<list>`          | Linked lists, insertions and deletions, no random access       |
| Stack            | LIFO (Last In, First Out) container      | `<stack>`         | Expression evaluation, backtracking, syntax parsing            |
| Queue            | FIFO (First In, First Out) container     | `<queue>`         | Task scheduling, network buffers, printer queues               |
| Priority Queue   | Priority queue with elements ordered     | `<queue>`         | Task scheduling, Dijkstra's algorithm, Huffman encoding        |
| Set              | Ordered set (no duplicate elements)      | `<set>`           | Maintaining unique elements, intersection, union              |
| Map              | Ordered map (key-value pairs)            | `<map>`           | Dictionary, key-value storage, range queries                  |
| Unordered Set    | Unordered set (no duplicate elements)    | `<unordered_set>` | Fast membership testing, hash join, bloom filters             |
| Unordered Map    | Unordered map (key-value pairs)          | `<unordered_map>` | Fast dictionary, hash join, caching                           |


🍎 Example
---
```c++
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>

int main() {
    // Vector
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // List
    std::list<int> lst = {6, 7, 8, 9, 10};

    // Deque
    std::deque<int> deq = {11, 12, 13, 14, 15};

    // Stack
    std::stack<int> stk;
    for (int i = 16; i <= 20; ++i)
        stk.push(i);

    // Queue
    std::queue<int> que;
    for (int i = 21; i <= 25; ++i)
        que.push(i);

    // Priority Queue
    std::priority_queue<int> pq;
    for (int i = 26; i <= 30; ++i)
        pq.push(i);

    // Set
    std::set<int> st;
    for (int i = 31; i <= 35; ++i)
        st.insert(i);

    // MultiSet
    std::multiset<int> mst;
    for (int i = 31; i <= 35; ++i)
        mst.insert(i);

    // Map
    std::map<int, std::string> mp;
    mp[36] = "thirty-six";
    mp[37] = "thirty-seven";
    mp[38] = "thirty-eight";
    mp[39] = "thirty-nine";
    mp[40] = "forty";

    // MultiMap
    std::multimap<int, std::string> mmp;
    mmp.insert({41, "forty-one"});
    mmp.insert({42, "forty-two"});
    mmp.insert({42, "another forty-two"});
    mmp.insert({43, "forty-three"});
    mmp.insert({44, "forty-four"});

    // Output elements
    std::cout << "Vector: ";
    for (const auto& v : vec) std::cout << v << " ";
    std::cout << "\nList: ";
    for (const auto& l : lst) std::cout << l << " ";
    std::cout << "\nDeque: ";
    for (const auto& d : deq) std::cout << d << " ";
    std::cout << "\nStack: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << "\nQueue: ";
    while (!que.empty()) {
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << "\nPriority Queue: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\nSet: ";
    for (const auto& s : st) std::cout << s << " ";
    std::cout << "\nMultiSet: ";
    for (const auto& ms : mst) std::cout << ms << " ";
    std::cout << "\nMap: ";
    for (const auto& m : mp) std::cout << m.first << ":" << m.second << " ";
    std::cout << "\nMultiMap: ";
    for (const auto& mm : mmp) std::cout << mm.first << ":" << mm.second << " ";
    std::cout << std::endl;

    return 0;
}
```

Popular C++ containers' member functions
---
| Container  | Member Function    | Description                                                                                                    |
|------------|--------------------|----------------------------------------------------------------------------------------------------------------|
| vector     | `push_back()`      | Adds an element to the end of the vector.                                                                      |
|            | `pop_back()`       | Removes the last element from the vector.                                                                      |
|            | `size()`           | Returns the number of elements in the vector.                                                                  |
|            | `empty()`          | Checks if the vector is empty.                                                                                 |
| list       | `push_front()`     | Adds an element to the front of the list.                                                                      |
|            | `pop_front()`      | Removes the first element from the list.                                                                       |
|            | `size()`           | Returns the number of elements in the list.                                                                    |
|            | `empty()`          | Checks if the list is empty.                                                                                   |
| deque      | `push_back()`      | Adds an element to the end of the deque.                                                                       |
|            | `pop_back()`       | Removes the last element from the deque.                                                                       |
|            | `push_front()`     | Adds an element to the front of the deque.                                                                     |
|            | `pop_front()`      | Removes the first element from the deque.                                                                      |
|            | `size()`           | Returns the number of elements in the deque.                                                                   |
|            | `empty()`          | Checks if the deque is empty.                                                                                  |
| map        | `insert()`         | Inserts a key-value pair into the map.                                                                         |
|            | `erase()`          | Removes an element with a specified key from the map.                                                          |
|            | `find()`           | Searches for an element with a specified key in the map.                                                       |
|            | `size()`           | Returns the number of elements in the map.                                                                     |
|            | `empty()`          | Checks if the map is empty.                                                                                    |
| set        | `insert()`         | Inserts an element into the set.                                                                               |
|            | `erase()`          | Removes an element from the set.                                                                               |
|            | `find()`           | Searches for an element in the set.                                                                            |
|            | `size()`           | Returns the number of elements in the set.                                                                     |
|            | `empty()`          | Checks if the set is empty.                                                                                    |


🍎 Example
---
```c++
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

int main() {
    // Vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    std::cout << "Vector size: " << vec.size() << std::endl;

    // List
    std::list<int> li;
    li.push_front(3);
    li.push_front(4);
    std::cout << "List size: " << li.size() << std::endl;

    // Deque
    std::deque<int> deq;
    deq.push_back(5);
    deq.push_front(6);
    std::cout << "Deque size: " << deq.size() << std::endl;

    // Map
    std::map<int, std::string> mp;
    mp.insert({1, "one"});
    mp.insert({2, "two"});
    std::cout << "Map size: " << mp.size() << std::endl;

    // Set
    std::set<int> st;
    st.insert(1);
    st.insert(2);
    std::cout << "Set size: " << st.size() << std::endl;

    return 0;
}
```

Sequential Containers vs. Associative Containers
---
| Aspect            | Sequential Containers        | Associative Containers          |
|-------------------|------------------------------|---------------------------------|
| Data Organization    | Elements stored in a linear sequence        | Elements stored in a sorted order based on keys |
| Access            | Access by `position`         | Access by `key`                 |
| Access Time          | Access time depends on the position of the element | Access time depends on the key value (logarithmic time) |
| Iteration            | Easy iteration using iterators               | Iteration might be slower due to tree traversal |
| Search Efficiency | Linear (𝐎(n))                      | Logarithmic (binary search)  (𝐎(log n))   |
| Insertion/Deletion   | Fast insertion/deletion at the beginning or end (𝐎(1)) | Might be slower due to maintaining order (𝐎(log n)) |
| Memory Usage         | Generally more memory-efficient              | Might require more memory due to tree structure |
| Examples          | Vector, List, Deque          | Map, Set, Multimap, Multiset    |


Container adapters
---
- provide different ways of accessing and manipulating the underlying data structures
  - allowing for convenient usage in various scenarios
- These underlying data structures provide efficient insertion, removal, and access operations

| Container Adapter | Description                               | Underlying Data Structure |
|-------------------|-------------------------------------------|---------------------------|
| Stack             | LIFO (Last-In-First-Out) data structure   | Deque or List             |
| Queue             | FIFO (First-In-First-Out) data structure  | Deque or List             |
| Priority Queue    | Container where elements are removed based on priority | Binary Heap  |


Relational operators for containers
---
| Operator                 | Description                                                                                   |
|--------------------------|-----------------------------------------------------------------------------------------------|
| Equality (`==`)          | Checks if two containers have the `same size` and contain the `same elements` in the `same order`.  |
| Inequality (`!=`)        | Returns `true` if the containers are not equal.                                             |
| Less Than (`<`)          | Compares two containers `lexicographically`. Returns `true` if the first is less than the second.|
| Less Than or Equal To (`<=`) | Returns `true` if the first container is less than or equal to the second.                    |
| Greater Than (`>`)       | Compares two containers `lexicographically`. Returns `true` if the first is greater than the second. |
| Greater Than or Equal To (`>=`) | Returns `true` if the first container is greater than or equal to the second.              |


🍎 Example
---
```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> vec3 = {1, 2, 3, 4};

    // Equality check
    if (vec1 == vec2) {
        std::cout << "vec1 and vec2 are equal" << std::endl;
    } else {
        std::cout << "vec1 and vec2 are not equal" << std::endl;
    }

    // Inequality check
    if (vec1 != vec3) {
        std::cout << "vec1 and vec3 are not equal" << std::endl;
    } else {
        std::cout << "vec1 and vec3 are equal" << std::endl;
    }

    // Less than check
    if (vec1 < vec3) {
        std::cout << "vec1 is less than vec3" << std::endl;
    } else {
        std::cout << "vec1 is not less than vec3" << std::endl;
    }

    return 0;
}
```


[Iterators](https://en.cppreference.com/w/cpp/iterator)
---
- `Traversal`: 
  - traverse the elements of a container sequentially
- `Uniform Interface`: 
  - access elements across different container types
- `Abstraction`: 
  - hide the specific implementation details of containers
  - allow algorithms to work independently of the underlying data structure
- `Operations`: 
  - dereference or access the element at the current position 
  - increment (move to the next element) and compare (compare two iterators)
- `Range-based Looping`: 
  - allow concise and readable code for iterating over container elements


Iterator classes
---
| Iterator Class        | Description                                            | Supported Containers                     |
|-----------------------|--------------------------------------------------------|-----------------------------------------|
| `Input` Iterator        | Used for `read-only traversal` of a sequence, supports only forward iteration | vector, deque, list, set, map, etc.   |
| `Output` Iterator       | Used for `write-only traversal` of a sequence, supports only forward iteration | vector, deque, list, set, map, etc.   |
| `Forward` Iterator      | supports `both read and write traversal`, but can `only move forward` by one element | list, forward_list, vector, deque, etc. |
| `Bidirectional` Iterator | supports `both forward and backward traversal`, supports `read and write` operations | list, forward_list, deque, etc.       |
| `Random` Access Iterator | supports read and write operations `at any position`, and allows `constant time access` in a jump-like fashion | vector, deque, array, etc.            |


Iterator operators
---
| Iterator Category     | Arithmetic Operators                                   | Comparison Operators                              |
|------------------------|--------------------------------------------------------|----------------------------------------------------|
| Input Iterator         | None                                                   | `==`, `!=`, `<`, `<=`, `>`, `>=`                  |
| Output Iterator        | None                                                   | None                                               |
| Forward Iterator       | `++`, `*`, `->`                                        | `==`, `!=`, `<`, `<=`, `>`, `>=`                  |
| Bidirectional Iterator | `++`, `--`, `*`, `->`                                  | `==`, `!=`, `<`, `<=`, `>`, `>=`                  |
| Random Access Iterator | `++`, `--`, `*`, `->`, `+`, `-`, `[]`, `+=`, `-=`     | `==`, `!=`, `<`, `<=`, `>`, `>=`                  |


| Operator | Description                                                |
|----------|------------------------------------------------------------|
| `++`     | Prefix and postfix increment operators, used to advance the iterator position and return the iterator before or after the increment. |
| `--`     | Prefix and postfix decrement operators, used to move the iterator position backward and return the iterator before or after the decrement. |
| `*`      | Dereference operator, used to access the object pointed to by the iterator. |
| `->`     | Member access operator, used to access the members of the object pointed to by the iterator. |
| `+`      | Addition operator, used to implement relative movement between iterators. |
| `-`      | Subtraction operator, used to calculate the relative distance between iterators. |
| `[]`     | Subscript operator, used to access elements in a container using iterator indexing. |
| `+=`     | Addition assignment operator, used to move the iterator forward by a specified distance. |
| `-=`     | Subtraction assignment operator, used to move the iterator backward by a specified distance. |
| `==`     | Equality operator, used to compare if two iterators point to the same element. |
| `!=`     | Inequality operator, used to compare if two iterators point to different elements. |
| `<`      | Less than operator, used to determine if the iterator on the left points to an element before the iterator on the right. |
| `<=`     | Less than or equal to operator, used to determine if the iterator on the left points to an element before or at the same position as the iterator on the right. |
| `>`      | Greater than operator, used to determine if the iterator on the left points to an element after the iterator on the right. |
| `>=`     | Greater than or equal to operator, used to determine if the iterator on the left points to an element after or at the same position as the iterator on the right. |




🍎 Example
---
```c++
#include <iostream>
#include <vector>
#include <forward_list>
#include <list>

int main() {
    // Input Iterator
    std::vector<int> vec{1, 2, 3, 4, 5};
    auto it_input = vec.begin();
    std::cout << "Input Iterator: " << *it_input << std::endl;

    // Output Iterator
    std::vector<int> vec_out(5);
    auto it_output = vec_out.begin();
    *it_output = 10;
    std::cout << "Output Iterator: " << *it_output << std::endl;

    // Forward Iterator
    std::forward_list<int> flist{1, 2, 3, 4, 5};
    auto it_forward = flist.begin();
    std::cout << "Forward Iterator: ";
    while (it_forward != flist.end()) {
        std::cout << *it_forward << " ";
        ++it_forward;
    }
    std::cout << std::endl;

    // Bidirectional Iterator
    std::list<int> llist{1, 2, 3, 4, 5};
    auto it_bidirectional = llist.begin();
    std::cout << "Bidirectional Iterator (reverse): ";
    while (it_bidirectional != llist.end()) {
        std::cout << *it_bidirectional << " ";
        --it_bidirectional;
    }
    std::cout << std::endl;

    // Random Access Iterator
    std::vector<int> vec_random{1, 2, 3, 4, 5};
    auto it_random = vec_random.begin();
    std::cout << "Random Access Iterator: ";
    std::cout << *(it_random + 2) << std::endl;

    return 0;
}
```

Iterators vs. pointers
---
| Feature        | Pointers                                                    | Iterators                                             |
|----------------|------------------------------------------------------------|-------------------------------------------------------|
| Definition     | Variables pointing to memory addresses                      | Objects used to traverse containers                    |
| Language       | C, C++, etc.                                                | Mainly used in C++ Standard Library, but similar concepts exist in other languages |
| Functionality  | Direct access to data in memory                              | Provides access to and traversal of container elements |
| Operations     | Arithmetic operations, comparison between pointers, dereferencing | Comparison between iterators, dereferencing, traversal of container elements, movement, etc. |
| Nullability    | Can be null, pointers can point to nullptr or NULL           | Can be null, sometimes points to end() or other termination positions |
| Type safety    | Lack of type safety, prone to memory leaks and illegal memory access | More type-safe, typically associated with specific container types, offering safer iteration operations |
| Memory management | Manual memory management, including allocation and deallocation | Typically no need for manual memory management, used together with containers, which handle memory management |
| Reference syntax | Uses `*` for dereferencing operations                        | Uses `*` for dereferencing operations                   |
| Movement       | Supports movement operations for pointers                    | Supports moving to the next or previous element in a container, as well as moving to specific positions |
| Applicability  | Can be used with any data type and memory address            | Mainly used with STL containers and other iterable objects |

---

[STL (Standard Template Library) algorithms](https://en.cppreference.com/w/cpp/algorithm)
---
- `Genericity`: 
  - applied to various data structures, including arrays, linked lists, sets, maps, and more
- `Reusability`: 
  - reusable in different scenarios without modification
- `Template-based`: 
  - able to handle different types of data without the need to rewrite the algorithms for specific types
- `Iterator-based`: 
  - abstract operations on containers to operations on iterators
- `Separation of algorithm and data structure`:
  - enable the same algorithms to be applied to different types of data structures
- `Performance optimization`: 
  - exhibit high execution efficiency and low memory usage
- `Rich types of algorithms`: 
  - searching, sorting, copying, replacing, merging, counting, transformation, numeric computation, and more

🍎 Example
---
```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector of integers
    std::vector<int> numbers = {5, 2, 8, 3, 1, 9, 4, 7, 6};

    // Print the original vector
    std::cout << "Original vector:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Print the sorted vector
    std::cout << "Sorted vector:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Find the minimum and maximum elements in the vector
    auto min_element = std::min_element(numbers.begin(), numbers.end());
    auto max_element = std::max_element(numbers.begin(), numbers.end());
    std::cout << "Minimum element: " << *min_element << std::endl;
    std::cout << "Maximum element: " << *max_element << std::endl;

    // Reverse the vector
    std::reverse(numbers.begin(), numbers.end());

    // Print the reversed vector
    std::cout << "Reversed vector:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Remove duplicates from the vector
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    // Print the vector with duplicates removed
    std::cout << "Vector with duplicates removed:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
```


🍎 Example
---
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    // Source vector
    std::vector<int> source = {1, 2, 3, 4, 5};

    // Destination vector
    std::vector<int> destination(source.size());

    // Copy elements from source to destination
    std::copy(source.begin(), source.end(), destination.begin());

    // Print the destination vector
    std::cout << "Copied vector:";
    for (int num : destination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Replace elements in destination vector
    std::replace(destination.begin(), destination.end(), 3, 10);

    // Print the destination vector after replacing
    std::cout << "After replacing 3 with 10:";
    for (int num : destination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Merge two sorted vectors
    std::vector<int> sorted1 = {1, 3, 5};
    std::vector<int> sorted2 = {2, 4, 6};
    std::vector<int> merged(6);
    std::merge(sorted1.begin(), sorted1.end(), sorted2.begin(), sorted2.end(), merged.begin());

    // Print the merged vector
    std::cout << "Merged vector:";
    for (int num : merged) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Count the number of occurrences of a value
    int count = std::count(source.begin(), source.end(), 3);
    std::cout << "Number of occurrences of 3 in source vector: " << count << std::endl;

    // Transform each element in source vector
    std::vector<int> transformed(source.size());
    std::transform(source.begin(), source.end(), transformed.begin(), [](int x) { return x * 2; });

    // Print the transformed vector
    std::cout << "Transformed vector:";
    for (int num : transformed) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // Perform numeric computation
    int sum = std::accumulate(source.begin(), source.end(), 0);
    std::cout << "Sum of elements in source vector: " << sum << std::endl;

    return 0;
}
```

Popular STL algorithms
---
| Functionality          | Algorithms                                                                                   |
|------------------------|----------------------------------------------------------------------------------------------|
| Non-modifying sequence operations | `all_of`, `any_of`, `none_of`, `for_each`, `count`, `count_if`, `mismatch`, `equal`, `find`, `find_if`, `find_if_not`, `find_end`, `find_first_of`, `adjacent_find` |
| Modifying sequence operations     | `copy`, `copy_n`, `copy_if`, `copy_backward`, `move`, `move_backward`, `fill`, `fill_n`, `generate`, `generate_n`, `remove`, `remove_if`, `remove_copy`, `remove_copy_if`, `replace`, `replace_if`, `replace_copy`, `replace_copy_if`, `swap`, `swap_ranges`, `iter_swap`, `reverse`, `reverse_copy`, `rotate`, `rotate_copy`, `random_shuffle`, `shuffle`, `unique`, `unique_copy` |
| Partition operations               | `is_partitioned`, `partition`, `partition_copy`, `stable_partition`, `partition_point`          |
| Sorting operations                 | `sort`, `stable_sort`, `partial_sort`, `partial_sort_copy`, `is_sorted`, `is_sorted_until`     |
| Binary search                      | `lower_bound`, `upper_bound`, `binary_search`, `equal_range`                                    |
| Merge operations                   | `merge`, `inplace_merge`, `includes`, `set_union`, `set_intersection`, `set_difference`, `set_symmetric_difference` |
| Heap operations                    | `push_heap`, `pop_heap`, `make_heap`, `sort_heap`, `is_heap`, `is_heap_until`                   |
| Min/max operations                 | `min`, `max`, `minmax`, `min_element`, `max_element`, `minmax_element`                          |
| Permutations                       | `next_permutation`, `prev_permutation`                                                         |
| Numeric operations                 | `accumulate`, `inner_product`, `partial_sum`, `adjacent_difference`, `iota`                     |

---

**Non-modifying sequence operations:**

| Algorithm      | Description                                                   |
|----------------|---------------------------------------------------------------|
| `all_of`       | Tests if all elements satisfy the predicate.                  |
| `any_of`       | Tests if any element satisfies the predicate.                 |
| `none_of`      | Tests if no elements satisfy the predicate.                   |
| `for_each`     | Applies a function to each element.                           |
| `count`        | Counts the number of elements satisfying the predicate.       |
| `count_if`     | Counts the number of elements satisfying the given condition. |
| `mismatch`     | Finds the first position where two ranges differ.             |
| `equal`        | Checks if the elements in two ranges are equal.               |
| `find`         | Finds the first occurrence of a value in a range.             |
| `find_if`      | Finds the first element satisfying a condition.               |
| `find_if_not`  | Finds the first element not satisfying a condition.           |
| `find_end`     | Searches for the last occurrence of a sequence in another.    |
| `find_first_of`| Finds the first occurrence of any element from a set.         |
| `adjacent_find`| Finds the first occurrence of adjacent equal elements.        |

---

**Modifying sequence operations:**

| Algorithm      | Description                                                   |
|----------------|---------------------------------------------------------------|
| `copy`         | Copies elements from one range to another.                     |
| `copy_if`      | Copies elements from one range to another if a condition is met.|
| `copy_n`       | Copies a specified number of elements from one range to another.|
| `copy_backward`| Copies elements from one range to another in reverse order.    |
| `move`         | Moves elements from one range to another.                      |
| `move_backward`| Moves elements from one range to another in reverse order.     |
| `swap`         | Swaps the values of two elements.                              |
| `swap_ranges`  | Swaps elements between two ranges.                             |
| `iter_swap`    | Swaps the elements pointed to by two iterators.                |
| `transform`    | Applies a function to each element and stores the result.      |
| `replace`      | Replaces all occurrences of a value in a range with another.   |
| `replace_if`   | Replaces elements in a range that satisfy a condition.         |
| `replace_copy` | Copies a range, replacing elements that satisfy a condition.   |
| `replace_copy_if` | Copies a range, replacing elements that satisfy a condition.|
| `fill`         | Assigns a value to all elements in a range.                   |
| `fill_n`       | Assigns a value to a specified number of elements.             |
| `generate`     | Assigns the results of a function call to each element.        |
| `generate_n`   | Assigns the results of a function call to a number of elements.|
| `remove`       | Removes elements equal to a certain value from a range.        |
| `remove_if`    | Removes elements satisfying a certain condition from a range.  |
| `remove_copy`  | Copies elements from a range, omitting certain values.         |
| `remove_copy_if` | Copies elements from a range, omitting elements that satisfy a condition.|
| `unique`       | Removes consecutive duplicate elements from a range.          |
| `unique_copy`  | Copies a range, removing consecutive duplicate elements.      |
| `reverse`      | Reverses the order of elements in a range.                    |
| `reverse_copy` | Copies a range, reversing the order of elements.              |
| `rotate`       | Rotates the order of elements in a range.                     |
| `rotate_copy`  | Copies a range, rotating the order of elements.               |
| `random_shuffle` | Randomly shuffles elements in a range.                        |
| `shuffle`      | Shuffles elements in a range using a random number generator. |

---

**Partition operations**

| Algorithm           | Description                                                                                                     |
|---------------------|-----------------------------------------------------------------------------------------------------------------|
| `is_partitioned`    | Determines whether a range is partitioned by a given predicate.                                                 |
| `partition`         | Divides a range into two groups based on a predicate, with elements that satisfy the predicate appearing before those that don't. |
| `partition_copy`    | Copies the elements of a range into two different ranges based on a predicate, with elements that satisfy the predicate being copied to one range and the rest to another. |
| `stable_partition`  | Similar to `partition`, but maintains the relative order of elements within each group.                         |
| `partition_point`   | Finds the partition point of a partitioned range, which is the first element that fails to satisfy the partitioning predicate. |

---

**Sorting operations**

| Algorithm           | Description                                                                                                   |
|---------------------|---------------------------------------------------------------------------------------------------------------|
| `sort`              | Sorts a range into ascending order.                                                                           |
| `stable_sort`       | Sorts a range into ascending order, maintaining the relative order of equal elements.                         |
| `partial_sort`      | Sorts the first `N` elements of a range, leaving the remaining elements in unspecified order.                 |
| `partial_sort_copy` | Copies and partially sorts elements from one range into another, leaving the original range unchanged.       |
| `is_sorted`         | Checks if a range is sorted in ascending order.                                                               |
| `is_sorted_until`   | Finds the last position where elements are not sorted in ascending order within a range.                     |

---

**Binary search**

| Algorithm        | Description                                                                                               |
|------------------|-----------------------------------------------------------------------------------------------------------|
| `lower_bound`    | Finds the first element not less than a given value in a sorted range.                                   |
| `upper_bound`    | Finds the first element greater than a given value in a sorted range.                                     |
| `binary_search`  | Determines if an element exists in a sorted range.                                                         |
| `equal_range`    | Finds the subrange of elements that are equal to a given value in a sorted range.                         |

---

**Merge operations**

| Algorithm                   | Description                                                                                                      |
|-----------------------------|------------------------------------------------------------------------------------------------------------------|
| `merge`                     | Merges two sorted ranges into a single sorted range.                                                             |
| `inplace_merge`             | Merges two consecutive sorted ranges into a single sorted range in place.                                        |
| `includes`                  | Determines if one sorted range includes another sorted range.                                                     |
| `set_union`                 | Computes the union of two sorted ranges.                                                                         |
| `set_intersection`          | Computes the intersection of two sorted ranges.                                                                  |
| `set_difference`            | Computes the difference between two sorted ranges.                                                               |
| `set_symmetric_difference`  | Computes the symmetric difference between two sorted ranges.                                                     |

---

**Heap operations**

| Algorithm    | Description                                                                                       |
|--------------|---------------------------------------------------------------------------------------------------|
| `push_heap`  | Inserts an element into a heap and ensures that the heap property is maintained.                 |
| `pop_heap`   | Removes the largest element from the heap and reorganizes the remaining elements into a heap.    |
| `make_heap`  | Converts a range into a heap, rearranging elements so that they satisfy the heap property.       |
| `sort_heap`  | Sorts the elements in a heap into non-decreasing order.                                          |
| `is_heap`    | Checks if a range satisfies the heap property.                                                    |
| `is_heap_until` | Finds the largest subrange that satisfies the heap property.                                     |

---

**Min/max operations**

| Algorithm         | Description                                                                                         |
|-------------------|-----------------------------------------------------------------------------------------------------|
| `min`             | Returns the smaller of two values.                                                                  |
| `max`             | Returns the larger of two values.                                                                   |
| `minmax`          | Returns both the smallest and largest of two values.                                                |
| `min_element`     | Finds the smallest element in a range.                                                              |
| `max_element`     | Finds the largest element in a range.                                                               |
| `minmax_element`  | Finds both the smallest and largest elements in a range.                                             |

---

**Permutations and Combinations operations**

| Algorithm      | Description                                                                                          |
|----------------|------------------------------------------------------------------------------------------------------|
| `next_permutation` | Generates the next lexicographically greater permutation of a sequence.                              |
| `prev_permutation` | Generates the next lexicographically smaller permutation of a sequence.                               |
| `rotate`           | Rotates the elements in the range so that the element at the middle becomes the new first element.   |
| `random_shuffle`   | Randomly shuffles the elements in the range.                                                         |
| `shuffle`          | Randomly shuffles the elements in the range using a provided random number generator.                 |
| `permutation`      | Generates all possible permutations of a sequence.                                                    |
| `combination`      | Generates all possible combinations of a sequence.                                                    |

---

**Numeric operations**

| Algorithm            | Description                                                                                          |
|----------------------|------------------------------------------------------------------------------------------------------|
| `accumulate`         | Computes the sum of the elements in the range, optionally starting with an initial value.            |
| `inner_product`      | Computes the inner product of two ranges.                                                            |
| `partial_sum`        | Computes the partial sums of the elements in the range.                                              |
| `adjacent_difference`| Computes the differences between adjacent elements in the range.                                     |
| `iota`               | Assigns consecutive values to a range.                                                               |
