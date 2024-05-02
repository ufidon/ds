#include <iostream>

// Function to calculate factorial
int factorial(int n)
{
  if (n == 0 || n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

// Function to calculate partial sum
int partialSum(int n)
{
  if (n==0)
    return 0;
  else
    return n + partialSum(n-1);
}

// Function to calculate Fibonacci sequence
int fibonacci(int n)
{
  if (n <= 1)
    return n;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  // Calculate and output factorial
  std::cout << "Factorial of " << n << " is: " << factorial(n) << std::endl;

  // Calculate and output partial sum
  std::cout << "Partial sum of " << n << " is: " << partialSum(n) << std::endl;

  // Calculate and output Fibonacci sequence up to n terms
  std::cout << "Fibonacci sequence up to " << n << " terms: ";
  for (int i = 0; i < n; ++i)
  {
    std::cout << fibonacci(i) << " ";
  }
  std::cout << std::endl;

  return 0;
}
