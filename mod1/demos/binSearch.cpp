#include <iostream>
#include <vector>

// Recursive binary search helper function
int binarySearch(const std::vector<int> &arr, int target, int left, int right)
{
  if (left > right)
  {
    return -1; // Base case: element not found
  }

  int mid = left + (right - left) / 2; // Calculate the middle index

  if (arr[mid] == target)
  {
    return mid; // Base case: element found at middle index
  }
  else if (arr[mid] < target)
  {
    // If target is greater, search in the right half
    return binarySearch(arr, target, mid + 1, right);
  }
  else
  {
    // If target is smaller, search in the left half
    return binarySearch(arr, target, left, mid - 1);
  }
}

int binarySearch(const std::vector<int> &arr, int target)
{
  return binarySearch(arr, target, 0, arr.size() - 1);
}

int main()
{
  std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int target = 13;
  std::cout << "Enter the target: ";
  std::cin >> target;

  int index = binarySearch(arr, target, 0, arr.size() - 1);

  if (index != -1)
  {
    std::cout << "Element " << target << " found at index " << index << std::endl;
  }
  else
  {
    std::cout << "Element " << target << " not found in the array" << std::endl;
  }

  return 0;
}
