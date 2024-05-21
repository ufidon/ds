#include <fstream>
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
  // Create and open a binary file
  std::ofstream output("largedata.dat", std::ios::binary);

  // Seed the random number generator
  srand(time(0));

  // Write random numbers to the file
  for (int i = 0; i < 20000; i++) {
    int number = rand() % 1000000;
    if(i < 100)
      std::cout << number << " ";
    output.write(reinterpret_cast<const char*>(&number), sizeof(number));
  }
  std::cout << std::endl;

  // Close the file
  output.close();

  // Open the file for reading
  std::ifstream input("largedata.dat", std::ios::binary);

  // Read and display the first 100 numbers
  for (int i = 0; i < 100; i++) {
    int number;
    input.read(reinterpret_cast<char*>(&number), sizeof(number));
    std::cout << number << " ";
  }
  std::cout << std::endl;

  // Close the file
  input.close();

  return 0;
}
