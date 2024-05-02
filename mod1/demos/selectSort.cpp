#include <iostream>
#include <vector>

// Helper function to find the minimum element in a vector
int findMinIndex(const std::vector<int> &arr, int start = 0)
{
  int minIndex = start;
  for (int i = start + 1; i < arr.size(); ++i)
  {
    if (arr[i] < arr[minIndex])
    {
      minIndex = i;
    }
  }
  return minIndex;
}

// Recursive helper function to perform selection sort
void selectionSortRecursive(std::vector<int> &arr, int start = 0)
{
  if (start >= arr.size() - 1)
  {
    return;
  }
  int minIndex = findMinIndex(arr, start);
  if (minIndex != start)
  {
    std::swap(arr[start], arr[minIndex]);
  }
  selectionSortRecursive(arr, start + 1);
}

// Selection sort
void selectionSort(std::vector<int> &arr)
{
  selectionSortRecursive(arr);
}

int main()
{
  std::vector<int> arr = {64, 25, 12, 22, 11};
  std::cout << "Original array: ";
  for (int num : arr)
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  selectionSort(arr);

  std::cout << "Sorted array: ";
  for (int num : arr)
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
