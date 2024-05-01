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
