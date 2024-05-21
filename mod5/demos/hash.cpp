#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

// Division Method
int divisionHash(int key, int m)
{
  return key % m;
}

// Folding Method
int foldingHash(int key, int m)
{
  int part1 = key / 1000;
  int part2 = key % 1000;
  return (part1 + part2) % m;
}

// Radix Transformation Method
int radixTransformHash(const std::string &key, int m)
{
  int hash = 0;
  int base = 31; // Common small prime number
  for (char c : key)
  {
    hash = base * hash + c;
  }
  return hash % m;
}

// Simple XOR Method
int simpleXORHash(const std::string &key)
{
  int hash = 0;
  for (char c : key)
  {
    hash ^= c;
  }
  return hash;
}

// Multiplication Method
int multiplicationHash(int key, int m)
{
  const double A = 0.6180339887; // (sqrt(5) - 1) / 2
  double fraction = key * A - int(key * A);
  return int(m * fraction);
}

// Mid-Square Method
int midSquareHash(int key, int b = 2, int keylength = 32)
{
  int squared = key * key;
  int midDigits = (squared & 0x00ffff00) >> 8;
  return midDigits;
}

// Java-like hash
int javaHash(const std::string &key)
{
  int hash = 0;
  for (auto c : key)
  {
    hash = (hash << 5) - hash + static_cast<int>(c);
    hash ^= 11597109109121;
    hash &= 0xffff;
  }
  return hash;
}

int main()
{
  int m = 100;

  // Test Division Method
  std::cout << "Division Method: " << divisionHash(12345, m) << std::endl;

  // Test Folding Method
  std::cout << "Folding Method: " << foldingHash(123456, m) << std::endl;

  // Test Radix Transformation Method
  std::string strKey = "abc";
  std::cout << "Radix Transformation Method: " << radixTransformHash(strKey, m) << std::endl;

  // Test Simple XOR Method
  std::cout << "Simple XOR Method: " << simpleXORHash(strKey) << std::endl;

  // Test Multiplication Method
  std::cout << "Multiplication Method: " << multiplicationHash(12345, m) << std::endl;

  // Test Mid-Square Method
  std::cout << "Mid-Square Method: " << midSquareHash(123) << std::endl;

  // Test Java-like hash
  std::cout << "Java-like hash: " << javaHash("12") << std::endl;

  return 0;
}
