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