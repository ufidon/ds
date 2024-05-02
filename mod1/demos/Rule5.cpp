#include <iostream>

class Resource {
private:
    int* data;

public:
    // Constructor
    Resource(int value) : data(new int(value)) {
        std::cout << "Resource allocated.\n";
    }

    // Destructor
    ~Resource() {
        delete data;
        std::cout << "Resource deallocated.\n";
    }

    // Copy constructor
    Resource(const Resource& other) : data(new int(*other.data)) {
        std::cout << "Resource copied.\n";
    }

    // Move constructor
    Resource(Resource&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Resource moved.\n";
    }

    // Copy assignment operator
    Resource& operator=(const Resource& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        std::cout << "= Resource copied.\n";
        return *this;
    }

    // Move assignment operator
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        std::cout << "= Resource moved.\n";
        return *this;
    }
};

int main() {
    Resource res1(100); // Constructor

    Resource res2(res1); // Copy constructor

    Resource res3(200); // Constructor

    res3 = res1; // Copy assignment operator

    Resource res4(std::move(res3)); // Move constructor

    res1 = std::move(res4); // Move assignment operator

    return 0;
}
