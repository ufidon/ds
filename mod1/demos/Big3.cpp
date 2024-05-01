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
