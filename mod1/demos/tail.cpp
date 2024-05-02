#include <iostream>

// Helper function for factorial
unsigned long long factorialHelper(unsigned long long n, unsigned long long accumulator)
{
  if (n == 0)
  {
    return accumulator;
  }
  return factorialHelper(n - 1, n * accumulator);
}

// Function to calculate factorial using tail recursion
unsigned long long factorial(unsigned long long n)
{
  return factorialHelper(n, 1);
}

int main()
{
  unsigned long long num = 20; // Change this value for a different factorial
  std::cout << "Factorial of " << num << " is: " << factorial(num) << std::endl;
  return 0;
}
