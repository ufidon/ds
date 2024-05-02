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
