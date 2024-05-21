#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

template <typename T>
void print(const std::vector<T> v)
{
  for (auto num : v)
  {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
}

// Selection sort function
void selectionSort(std::vector<int> &array)
{
  int n = array.size();
  for (int i = 0; i < n - 1; ++i)
  {
    // Find the minimum element in the right unsorted part
    int min_idx = i;
    for (int j = i + 1; j < n; ++j)
    {
      if (array[j] < array[min_idx])
        min_idx = j;
    }
    // Swap the found minimum element with the first element
    // in the right unsorted part
    std::swap(array[min_idx], array[i]);
  }
}

// Insertion sort function
void insertionSort(std::vector<int> &array)
{
  for (int i = 1; i < array.size(); i++)
  {
    int currentElement = array[i];
    int k;
    for (k = i - 1; k >= 0 && array[k] > currentElement; k--)
    {
      array[k + 1] = array[k];
    }

    array[k + 1] = currentElement;
  }
}

// Bubble sort function
void bubbleSort(std::vector<int> &array)
{
  bool needNextPass = true;

  for (int k = 1; k < array.size() && needNextPass; k++)
  {
    needNextPass = false;
    for (int i = 0; i < array.size() - k; i++)
    {
      if (array[i] > array[i + 1])
      {
        std::swap(array[i], array[i + 1]);
        needNextPass = true;
      }
    }
  }
}

// Merge sort function
template <typename T>
void mergeSort(std::vector<T> &vec)
{
  if (vec.size() > 1)
  {
    std::vector<T> firstHalf(vec.begin(), vec.begin() + vec.size() / 2);
    mergeSort(firstHalf);

    std::vector<T> secondHalf(vec.begin() + vec.size() / 2, vec.end());
    mergeSort(secondHalf);

    merge(firstHalf, secondHalf, vec);
  }
}

template <typename T>
void merge(std::vector<T> &vec1, std::vector<T> &vec2, std::vector<T> &temp)
{
  int current1 = 0;
  int current2 = 0;
  int current3 = 0;

  while (current1 < vec1.size() && current2 < vec2.size())
  {
    if (vec1[current1] < vec2[current2])
      temp[current3++] = vec1[current1++];
    else
      temp[current3++] = vec2[current2++];
  }

  while (current1 < vec1.size())
    temp[current3++] = vec1[current1++];

  while (current2 < vec2.size())
    temp[current3++] = vec2[current2++];
}

// Quick sort function
int partition(std::vector<int> &vec, int first, int last)
{
  int pivot = vec[first];
  int low = first + 1;
  int high = last;

  while (high > low)
  {
    while (low <= high && vec[low] <= pivot)
      low++;

    while (low <= high && vec[high] > pivot)
      high--;

    if (high > low)
      std::swap(vec[low], vec[high]);
  }

  while (high > first && vec[high] >= pivot)
    high--;

  if (pivot > vec[high])
  {
    vec[first] = vec[high];
    vec[high] = pivot;
    return high;
  }
  else
  {
    return first;
  }
}

void quickSort(std::vector<int> &vec, int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(vec, first, last);
    quickSort(vec, first, pivotIndex - 1);
    quickSort(vec, pivotIndex + 1, last);
  }
}

void quickSort(std::vector<int> &vec)
{
  quickSort(vec, 0, vec.size() - 1);
}

// The Heap class
template <typename T>
class Heap
{
public:
  // Create a max heap from a vector
  Heap(const std::vector<T> vec)
  {
    for (size_t i = 0; i < vec.size(); i++)
    {
      insert(vec[i]);
    }
  }
  // Insert an element into the heap
  void insert(const T &value)
  {
    // Add the new element to the end of the vector
    data.push_back(value);
    // Move the new element up to maintain the heap property
    siftUp(data.size() - 1);
  }

  // Extract the maximum element from the heap
  T extractMax()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Heap is empty");
    }
    // Swap the first element with the last element
    std::swap(data[0], data.back());
    // Store the maximum element to return later
    T maxElement = data.back();
    // Remove the last element
    data.pop_back();
    // Move the new first element down to maintain the heap property
    siftDown(0);
    return maxElement;
  }

  // Check if the heap is empty
  bool isEmpty() const
  {
    return data.empty();
  }

  // Get size
  size_t getSize() const
  {
    return data.size();
  }

  // Print heap
  void print() const
  {
    for (auto e : data)
    {
      std::cout << e << " ";
    }
    std::cout << std::endl;
  }

private:
  std::vector<T> data;

  // Move an element up the heap to maintain the heap property
  void siftUp(size_t index)
  {
    while (index > 0)
    {
      size_t parentIndex = (index - 1) / 2;
      if (data[index] <= data[parentIndex])
      {
        // The heap property is satisfied
        break;
      }
      // Swap the element with its parent
      std::swap(data[index], data[parentIndex]);
      index = parentIndex;
    }
  }

  // Move an element down the heap to maintain the heap property
  void siftDown(size_t index)
  {
    size_t leftChildIndex, rightChildIndex, largerChildIndex;
    while (index < data.size())
    {
      leftChildIndex = 2 * index + 1;
      rightChildIndex = 2 * index + 2;
      largerChildIndex = index;

      // Find the larger of the two children
      if (leftChildIndex < data.size() && data[leftChildIndex] > data[largerChildIndex])
      {
        largerChildIndex = leftChildIndex;
      }
      if (rightChildIndex < data.size() && data[rightChildIndex] > data[largerChildIndex])
      {
        largerChildIndex = rightChildIndex;
      }

      if (largerChildIndex == index)
      {
        // The heap property is satisfied
        break;
      }

      // Swap the element with the larger child
      std::swap(data[index], data[largerChildIndex]);
      index = largerChildIndex;
    }
  }
};

template <typename T>
void heapSort(std::vector<T> &vec)
{
  Heap<T> heap(vec);
  for (size_t i = 0; i < vec.size(); i++)
  {
    vec[i] = heap.extractMax();
  }
}

// bucket sort function
// 1. sorts an array of floating-point numbers ranging from 0 to 1
void bucketSort(std::vector<float> &arr)
{
  int n = arr.size();

  // Create buckets
  std::vector<float> b[n];

  // Put array elements in different buckets
  for (int i = 0; i < n; i++)
  {
    int bi = n * arr[i]; // Index in bucket
    b[bi].push_back(arr[i]);
  }

  // Sort individual buckets
  for (int i = 0; i < n; i++)
  {
    std::sort(b[i].begin(), b[i].end());
  }

  // Concatenate all buckets into arr[]
  int index = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < b[i].size(); j++)
    {
      arr[index++] = b[i][j];
    }
  }
}

// 2. sorts an array of integers ranging from low to high
void bucketSort(std::vector<int> &arr, int low, int high)
{
  int n = arr.size();
  // Create buckets for the range of values
  std::vector<int> b[high - low + 1];

  // Put array elements in different buckets
  for (int i = 0; i < n; i++)
  {
    int bi = arr[i] - low; // Index in bucket, shifted by low to fit the indices
    b[bi].push_back(arr[i]);
  }

  // Sort individual buckets
  for (int i = 0; i < 201; i++)
  {
    std::sort(b[i].begin(), b[i].end());
  }

  // Concatenate all buckets into arr[]
  int index = 0;
  for (int i = 0; i < 201; i++)
  {
    for (int j = 0; j < b[i].size(); j++)
    {
      arr[index++] = b[i][j];
    }
  }
}

// counting sort function
void countingSort(std::vector<int> &arr)
{
  if (arr.empty())
    return; // Handle the empty array case

  // Find the maximum and minimum values in the array
  int maxVal = *std::max_element(arr.begin(), arr.end());
  int minVal = *std::min_element(arr.begin(), arr.end());

  // Calculate the range of the numbers
  int range = maxVal - minVal + 1;

  // Create and initialize the count array
  std::vector<int> count(range, 0);

  // Fill the count array with the frequency of each element
  for (int num : arr)
  {
    count[num - minVal]++;
  }

  // Modify the count array to store the cumulative count
  for (int i = 1; i < range; ++i)
  {
    count[i] += count[i - 1];
  }

  // Create the output array
  std::vector<int> output(arr.size());

  // Build the output array
  for (int i = arr.size() - 1; i >= 0; --i)
  {
    output[count[arr[i] - minVal] - 1] = arr[i];
    count[arr[i] - minVal]--;
  }

  // Copy the sorted elements back into the original array
  arr = output;
}

// Radix sort function
// Function to get the maximum value in the array
int getMax(const std::vector<int> &arr)
{
  return *std::max_element(arr.begin(), arr.end());
}

// Function to perform counting sort based on a specific digit represented by exp (10^i)
void countingSort(std::vector<int> &arr, int exp)
{
  int n = arr.size();
  std::vector<int> output(n);    // Output array
  std::vector<int> count(10, 0); // Count array

  // Store count of occurrences in count[]
  for (int i = 0; i < n; ++i)
  {
    int index = (arr[i] / exp) % 10;
    count[index]++;
  }

  // Change count[i] so that count[i] contains the actual position of this digit in output[]
  for (int i = 1; i < 10; ++i)
  {
    count[i] += count[i - 1];
  }

  // Build the output array
  for (int i = n - 1; i >= 0; --i)
  {
    int index = (arr[i] / exp) % 10;
    output[count[index] - 1] = arr[i];
    count[index]--;
  }

  // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
  for (int i = 0; i < n; ++i)
  {
    arr[i] = output[i];
  }
}

// Main function to implement Radix Sort
void radixSort(std::vector<int> &arr)
{
  // Find the maximum number to know the number of digits
  int maxVal = getMax(arr);

  // Do counting sort for every digit. Note that exp is 10^i where i is the current digit number
  for (int exp = 1; maxVal / exp > 0; exp *= 10)
  {
    countingSort(arr, exp);
  }
}

// String radix sort
// Function to get the maximum length of strings in the array
int getMaxLength(const std::vector<std::string> &arr)
{
  size_t maxLen = 0;
  for (const auto &str : arr)
  {
    if (str.length() > maxLen)
    {
      maxLen = str.length();
    }
  }
  return maxLen;
}

// Function to perform counting sort based on a specific character position
void countingSort(std::vector<std::string> &arr, int charPos)
{
  int n = arr.size();
  const int ALPHABET_SIZE = 256;            // ASCII character set size
  std::vector<std::string> output(n);       // Output array
  std::vector<int> count(ALPHABET_SIZE, 0); // Count array

  // Store count of occurrences in count[]
  for (int i = 0; i < n; ++i)
  {
    char currentChar = charPos < arr[i].length() ? arr[i][charPos] : '\0'; // Handle variable length strings
    count[currentChar]++;
  }

  // Change count[i] so that count[i] contains the actual position of this character in output[]
  for (int i = 1; i < ALPHABET_SIZE; ++i)
  {
    count[i] += count[i - 1];
  }

  // Build the output array
  for (int i = n - 1; i >= 0; --i)
  {
    char currentChar = charPos < arr[i].length() ? arr[i][charPos] : '\0';
    output[count[currentChar] - 1] = arr[i];
    count[currentChar]--;
  }

  // Copy the output array to arr[], so that arr[] now contains sorted strings according to the current character position
  for (int i = 0; i < n; ++i)
  {
    arr[i] = output[i];
  }
}

// Main function to implement Radix Sort for strings
void radixSort(std::vector<std::string> &arr)
{
  // Find the maximum length of the strings
  int maxLen = getMaxLength(arr);

  // Do counting sort for every character position from right to left
  for (int charPos = maxLen - 1; charPos >= 0; --charPos)
  {
    countingSort(arr, charPos);
  }
}

int main()
{
  // comparison sort algorithms
  std::vector<int> vec = {4, 2, 5, 3, 1};

  std::vector<int> v1 = vec;
  selectionSort(v1);
  print(v1);

  std::vector<int> v2 = vec;
  insertionSort(v2);
  print(v2);

  std::vector<int> v3 = vec;
  bubbleSort(v3);
  print(v3);

  std::vector<int> v4 = vec;
  bubbleSort(v4);
  print(v4);

  std::vector<int> v5 = vec;
  quickSort(v5);
  print(v5);

  std::vector<int> v6 = vec;
  heapSort(v6);
  print(v6);

  // non-comparison sort algorithms
  std::vector<float> n1 = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
  bucketSort(n1);
  print(n1);

  std::vector<int> n2 = {-4, -1, 0, 3, 10, -2, 100, -99, 2, 3};
  int a = -100, b = 100;
  bucketSort(n2, a, b);
  print(n2);

  std::vector<int> n3 = {4, 2, 2, 8, 3, 3, 1};
  countingSort(n3);
  print(n3);

  std::vector<int> n4 = {170, 45, 75, 90, 802, 24, 2, 66};
  radixSort(n4);
  print(n4);

  std::vector<std::string> n5 = {"word", "category", "apple", "orange", "banana", "grape", "kiwi"};
  radixSort(n5);
  print(n5);

  return 0;
}