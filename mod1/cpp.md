# Core ideas of C++

Core concepts of C++ 
---
- `Syntax and Language Basics`: 
  - data types, variables, operators, control flow structures (such as loops and conditional statements) and functions
- `Object-Oriented Programming (OOP)`: classes, objects, encapsulation, inheritance, and polymorphism
  - `classes` are used to define `blueprints` for objects
  - `objects` are `instances` of classes
  - `encapsulation` refers to the `bundling` of data and methods within a class
  - `inheritance` allows a class to `inherit` properties and methods from another class
  - `polymorphism` enables objects of different classes to be treated as objects of a `common base class`
- `Templates and Generic Programming`: 
  - generic functions and classes that can operate on `different data types`
    - enabled by templates
- `Standard Template Library (STL)`: 
  - containers such as vectors, lists, and maps
    - iterators for traversing containers
  - algorithms such as sorting and searching
- `Memory Management`:  
  - dynamic memory allocation using `new` and `delete` operators 
  - `normal pointers` and `smart pointers` such as std::shared_ptr and std::unique_ptr
  - Proper memory management is important to `avoid memory leaks` and `optimize program performance`
- `Exception Handling`: 
  - deals with `runtime errors and exceptional situations` gracefully
  - by `try, catch, and throw` keywords to handle exceptions and `propagate` them up the call stack
- `IO Streams`: std::cin, std::cout, std::cerr, std::fstream, etc.
  -  read from and write to files and consoles
- `Concurrency`: 
  - `multithreading` and concurrency through features like `std::thread, std::mutex, std::condition_variable, and atomic operations`
  - necessary for writing `concurrent and parallel programs`


💡 A C++ class
---
```c++
#include <iostream>
using namespace std;

// Class declaration
class Rectangle {
private:
    int length;
    int width;

public:
    // Constructor
    Rectangle(int l=3, int w=4) {
        length = l;
        width = w;
    }

    // Member function to calculate area
    int area() {
        return length * width;
    }

    // Member function to calculate perimeter
    int perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    // Creating objects of the Rectangle class
    Rectangle rect1(5, 4);
    Rectangle rect2(3, 6);

    // Using member functions
    cout << "Area of rect1: " << rect1.area() << endl;
    cout << "Perimeter of rect2: " << rect2.perimeter() << endl;

    return 0;
}
```

💡 Inheritance and polymorphism
---
```c++
#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {
        cout << "Drawing shape" << endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing circle" << endl;
    }
};

// Derived class 2
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing rectangle" << endl;
    }
};

// Derived class 3
class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing triangle" << endl;
    }
};

int main() {
    // Creating objects of the derived classes
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    // Calling the virtual function for polymorphic behavior
    Shape* shapes[] = {&circle, &rectangle, &triangle};
    for (Shape* shape : shapes) {
        shape->draw();
    }

    return 0;
}
```

"Big Three" in C++
---
- three important member functions that need to be defined when dealing with 
  - dynamic memory allocation and deallocation
  - and resource management in classes
- `Destructor`
  - cleanups any dynamically allocated memory or other resources
- `Copy Constructor`
  - ensures that the new object has its own copy of the resources
- `Copy Assignment Operator`
  - ensures proper resource management when objects are assigned to each other
- complemented or replaced by 
  - the `Rule of Five` which includes move constructor and move assignment operator 
  - or the `Rule of Zero` which eliminates the need to define these functions altogether 
    - through the use of `smart pointers` and RAII principles


💡 Big three in C++
```c++
#include <iostream>

class Resource {
private:
    int* data;
public:
    // Constructor
    Resource(int value) {
        std::cout << "Resource constructor\n";
        data = new int(value);
    }

    // Destructor
    ~Resource() {
        std::cout << "Resource destructor\n";
        delete data;
    }

    // Copy constructor
    Resource(const Resource& other) {
        std::cout << "Resource copy constructor\n";
        data = new int(*other.data);
    }

    // Copy assignment operator
    Resource& operator=(const Resource& other) {
        std::cout << "Resource copy assignment operator\n";
        if (this != &other) {
            delete data; // Release existing resource
            data = new int(*other.data);
        }
        return *this;
    }

    // Getter method
    int getValue() const {
        return *data;
    }
};

int main() {
    // Create an object using constructor
    Resource r1(10);
    std::cout << "Value of r1: " << r1.getValue() << std::endl;

    // Create a second object using copy constructor
    Resource r2(r1);
    std::cout << "Value of r2: " << r2.getValue() << std::endl;

    // Create a third object and assign value using copy assignment operator
    Resource r3(20);
    r3 = r1;
    std::cout << "Value of r3: " << r3.getValue() << std::endl;

    return 0;
}
```



# References
- [clangd 找不到 c++ 头文件](https://zhuanlan.zhihu.com/p/531422156)