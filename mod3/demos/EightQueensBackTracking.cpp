#include <iostream>
#include <vector>
#include <string>

const int SIZE = 8;
std::vector<int> queens(SIZE, -1);

bool isValid(int row, int column, const std::vector<int> &queens)
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

int findPosition(int k, const std::vector<int> &queens)
{
  for (int j = queens[k] + 1; j < SIZE; ++j)
  {
    if (isValid(k, j, queens))
      return j;
  }
  return -1;
}

bool search(std::vector<int> &queens)
{
  int k = 0;
  while (k >= 0 && k < SIZE)
  {
    int j = findPosition(k, queens);
    if (j < 0)
    {
      queens[k] = -1;
      --k;
    }
    else
    {
      queens[k] = j;
      ++k;
    }
  }
  return k != -1;
}

void printBoard(const std::vector<int> &queens)
{
  for (int i = 0; i < SIZE; ++i)
  {
    std::string row(SIZE, '.');
    if (queens[i] != -1)
    {
      row[queens[i]] = 'Q';
    }
    std::cout << row << std::endl;
  }
}

int main()
{
  if (search(queens))
  {
    printBoard(queens);
  }
  else
  {
    std::cout << "No solution found." << std::endl;
  }
  return 0;
}
