#include <iostream>

// 递归模板函数，计算斐波那契数列的第n项
template <int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// 特化模板函数，定义斐波那契数列的前两项
template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

// 模板元函数，计算阶乘
template <int N>
constexpr int factorial() {
    return N * factorial<N - 1>();
}

template <>
constexpr int factorial<0>() {
    return 1;
}

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    std::cout << "Fibonacci(10) = " << Fibonacci<10>::value << std::endl;
    std::cout << "Factorial(5) = " << factorial<5>() << std::endl;

    constexpr int result = factorial(5); // 编译期计算
    std::cout << "Factorial(5) = " << result << std::endl;
    
    int n;
    std::cin >> n;
    int dynamic_result = factorial(n); // 运行时计算
    std::cout << "Factorial(" << n << ") = " << dynamic_result << std::endl;
    
    return 0;
}
