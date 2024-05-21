#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // For std::sort
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <exception>


const int MAX_ARRAY_SIZE = 43;
const int BUFFER_SIZE = 1000;

// Function prototypes
void xsort(const std::string &sourcefile, const std::string &targetfile);
int initializeSegments(int segmentSize, const std::string &originalFile, const std::string &f1);
void xmerge(int numberOfSegments, int segmentSize, const std::string &f1, const std::string &f2, const std::string &f3, const std::string &targetfile);
void mergeOneStep(int numberOfSegments, int segmentSize, const std::string &f1, const std::string &f2, const std::string &f3);
void copyHalfToF2(int numberOfSegments, int segmentSize, std::ifstream &f1, std::ofstream &f2);
void mergeSegments(int numberOfSegments, int segmentSize, std::ifstream &f1, std::ifstream &f2, std::ofstream &f3);
void mergeTwoSegments(int segmentSize, std::ifstream &f1, std::ifstream &f2, std::ofstream &f3);
void displayFile(const std::string &filename);

int main()
{
  try
  {
    xsort("largedata.dat", "sortedfile.dat");
    displayFile("sortedfile.dat");
  }
  catch (const std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}

// Sorts the large file
void xsort(const std::string &sourcefile, const std::string &targetfile)
{
  int numberOfSegments = initializeSegments(MAX_ARRAY_SIZE, sourcefile, "f1.dat");
  xmerge(numberOfSegments, MAX_ARRAY_SIZE, "f1.dat", "f2.dat", "f3.dat", targetfile);
}

// Initializes segments by dividing the original file into smaller runs
int initializeSegments(int segmentSize, const std::string &originalFile, const std::string &f1)
{
  std::vector<int> list(segmentSize);
  std::ifstream input(originalFile, std::ios::binary);
  std::ofstream output(f1, std::ios::binary);

  int numberOfSegments = 0;
  while (input)
  {
    numberOfSegments++;
    int i = 0;
    for (; input && i < segmentSize; i++)
    {
      input.read(reinterpret_cast<char *>(&list[i]), sizeof(int));
    }

    std::sort(list.begin(), list.begin() + i);

    for (int j = 0; j < i; j++)
    {
      output.write(reinterpret_cast<const char *>(&list[j]), sizeof(int));
    }
  }
  input.close();
  output.close();
  return numberOfSegments;
}

// Merges segments recursively
void xmerge(int numberOfSegments, int segmentSize, const std::string &f1, const std::string &f2, const std::string &f3, const std::string &targetfile)
{
  if (numberOfSegments > 1)
  {
    mergeOneStep(numberOfSegments, segmentSize, f1, f2, f3);
    xmerge((numberOfSegments + 1) / 2, segmentSize * 2, f3, f1, f2, targetfile);
  }
  else
  {
    std::remove(targetfile.c_str());
    std::rename(f1.c_str(), targetfile.c_str());
  }
}

// Merges two segments in one step
void mergeOneStep(int numberOfSegments, int segmentSize, const std::string &f1, const std::string &f2, const std::string &f3)
{
  std::ifstream f1Input(f1, std::ios::binary);
  std::ofstream f2Output(f2, std::ios::binary);

  copyHalfToF2(numberOfSegments, segmentSize, f1Input, f2Output);
  f2Output.close();

  std::ifstream f2Input(f2, std::ios::binary);
  std::ofstream f3Output(f3, std::ios::binary);

  mergeSegments(numberOfSegments / 2, segmentSize, f1Input, f2Input, f3Output);

  f1Input.close();
  f2Input.close();
  f3Output.close();
}

// Copies half of the data from f1 to f2
void copyHalfToF2(int numberOfSegments, int segmentSize, std::ifstream &f1, std::ofstream &f2)
{
  for (int i = 0; i < (numberOfSegments / 2) * segmentSize; i++)
  {
    int value;
    f1.read(reinterpret_cast<char *>(&value), sizeof(int));
    f2.write(reinterpret_cast<const char *>(&value), sizeof(int));
  }
}

// Merges segments from f1 and f2 into f3
void mergeSegments(int numberOfSegments, int segmentSize, std::ifstream &f1, std::ifstream &f2, std::ofstream &f3)
{
  for (int i = 0; i < numberOfSegments; i++)
  {
    mergeTwoSegments(segmentSize, f1, f2, f3);
  }

  while (f1)
  {
    int value;
    f1.read(reinterpret_cast<char *>(&value), sizeof(int));
    f3.write(reinterpret_cast<const char *>(&value), sizeof(int));
  }
}

// Merges two segments
void mergeTwoSegments(int segmentSize, std::ifstream& f1, std::ifstream& f2, std::ofstream& f3) {
  int intFromF1, intFromF2;
  int f1Count = 1, f2Count = 1;

  // Read the first elements from each file
  f1.read(reinterpret_cast<char*>(&intFromF1), sizeof(int));
  f2.read(reinterpret_cast<char*>(&intFromF2), sizeof(int));

  // Merge segments while data available in both files
  while (true) {
    if (intFromF1 < intFromF2) {
      f3.write(reinterpret_cast<char*>(&intFromF1), sizeof(int));
      f1Count++;
      if (f1Count >= segmentSize || f1.peek() == EOF) {
        f3.write(reinterpret_cast<char*>(&intFromF2), sizeof(int));
        break;
      }else
        f1.read(reinterpret_cast<char*>(&intFromF1), sizeof(int));
    } else {
      f3.write(reinterpret_cast<char*>(&intFromF2), sizeof(int));
      f2Count++;
      if (f2Count >= segmentSize || f2.peek() == EOF) {
        f3.write(reinterpret_cast<char*>(&intFromF1), sizeof(int));
        break;
      }else
        f2.read(reinterpret_cast<char*>(&intFromF2), sizeof(int));
    }
  }

  // Write remaining elements from f1 (if any)
  while (f1Count < segmentSize && f1.peek() != EOF) {
    f1.read(reinterpret_cast<char*>(&intFromF1), sizeof(int));
    f3.write(reinterpret_cast<char*>(&intFromF1), sizeof(int));
    f1Count++;
  }

  // Write remaining elements from f2 (if any)
  while (f2Count < segmentSize && f2.peek() != EOF) {
    f2.read(reinterpret_cast<char*>(&intFromF2), sizeof(int));
    f3.write(reinterpret_cast<char*>(&intFromF2), sizeof(int));
    f2Count++;
  }
}


// Displays the first 100 numbers from the sorted file
void displayFile(const std::string &filename)
{
  std::ifstream input(filename, std::ios::binary);
  if (!input)
  {
    std::cerr << "Error opening " << filename << std::endl;
    return;
  }

  int value;
  for (int i = 0; i < 100; i++)
  {
    if (input.read(reinterpret_cast<char *>(&value), sizeof(int)))
    {
      std::cout << value << " ";
    }
  }
  input.close();
}
