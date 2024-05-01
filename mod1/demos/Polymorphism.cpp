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
