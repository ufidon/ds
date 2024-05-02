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
