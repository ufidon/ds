#include <iostream>
#include <vector>

class Resource {
private:
    std::vector<int> data;

public:
    // Constructor
    Resource(int value) : data(std::vector<int>(1, value)) {
        std::cout << "Resource allocated.\n";
    }

    // default destructor, copy/move constructors, or copy/move assignment operators
};

int main() {
    Resource res1(100); // Constructor

    {
        Resource res2(200); // Constructor
    }

    Resource res3(300); // Constructor

    res3 = Resource(400); // Constructor and move assignment

    return 0;
}