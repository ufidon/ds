#include <iostream>
#include <vector>
#include <string>

const int SIZE = 8;
std::vector<int> queens(SIZE, -1);

bool isValid(int row, int column)
{
  for (int i = 1; i <= row; ++i)
  {
    if (queens[row - i] == column ||
        queens[row - i] == column - i ||
        queens[row - i] == column + i)
      return false;
  }
  return true;
}

bool search(int row)
{
  if (row == SIZE)
  {
    return true;
  }

  for (int column = 0; column < SIZE; ++column)
  {
    queens[row] = column;
    if (isValid(row, column) && search(row + 1))
    {
      return true;
    }
  }

  return false;
}

void printBoard()
{
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      std::cout << (queens[i] == j ? "Q" : ".") << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  if (search(0))
  {
    printBoard();
  }
  else
  {
    std::cout << "No solution found." << std::endl;
  }
  return 0;
}
