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


C++ Standard Template Library (STL)
---
A highly efficient and reusable set of classes and functions:
- `Containers`: store objects of a particular type
  - vector, deque, list, forward_list, set, multiset, map, multimap, stack, queue, and priority_queue
- `Algorithms`: perform various operations on containers or other sequences of data
  - sorting, searching, transforming, and numeric algorithms
- `Iterators`: provide a way to traverse the elements of a container sequentially
  - allow algorithms to operate on containers independently of their underlying structure
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
