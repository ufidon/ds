#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

mp::cpp_int factorial_tail_recursion(int n, const mp::cpp_int &accumulator = 1)
{
  if (n <= 1)
    return accumulator;
  else
    return factorial_tail_recursion(n - 1, n * accumulator);
}

int main()
{
  int num = 100; // Change this value for a different factorial
  mp::cpp_int result = factorial_tail_recursion(num);
  std::cout << "Factorial of " << num << " is: " << result << std::endl;
  return 0;
}
