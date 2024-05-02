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