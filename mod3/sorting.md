# Sorting

Objectives
---
- Design, implement, and analyze popular sorting algorithms
  - selection sort
  - insertion sort
  - bubble sort
  - merge sort
  - quick sort
  - heap sort
    - binary heap
  - bucket sort
    - radix sort
    - counting sort
  - external sort of large files


Sorting
---
- rearranges data in `ascending` or `descending` order
- Two groups of sorting algorithms:
  - `Comparison` sorting algorithms include
    - selection sort, insertion sort, bubble sort
    - merge sort, quick sort, heap sort, etc.
  - `Non-comparison` sorting algorithms include
    - bucket sort, counting sort, radix sort, etc.


# [Comparison sorting algorithms](https://en.wikipedia.org/wiki/Comparison_sort)
- determine `the order of two elements` in the final sorted list through a single `comparison` operation
  - often a `less than or equal to` operator `≤`
- The only requirement is that the operator forms a `total preorder` over the data, with:
  - `transitivity`: if a ≤ b and b ≤ c then a ≤ c
  - `connexity`: for all a and b, a ≤ b or b ≤ a
- It is possible that both a ≤ b and b ≤ a, so either may come first in the sorted list
  - In a `stable` sort, the `input order` determines the `sorted order` in this case


🍎 Example
---
- Sorting a set of unlabelled weights by weight using only a `balance scale` requires a comparison sort algorithm

![sort weights](./images/balance.jpeg)

- A comparison sort must have an `average-case lower bound` of $𝛀(n\log n)$ comparison operations
  - which is known as `linearithmic` time
  - under the assumption that `the length of each key` is `constant`
    - therefore that all comparisons, swaps and other operations can proceed in constant time


Selection sort
---
- Finds the minimum (or maximum) element from the unsorted part and puts it at the beginning (or end) of the unsorted part
- Not efficient for large data sets
- Involves fewer swaps compared to insertion sort but more comparisons


💡 Intuition
---
- [selection sort animation](https://csvistool.com/SelectionSort)


🏃 Implementation
---
```c++
void selectionSort(std::vector<int>& array)
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
```

- Time complexity: $𝐎(n^2)$ in all cases


Insertion sort
---
- Inserts an unsorted element into a sorted sublist until the whole array is sorted
- Builds the final sorted array one item at a time
- Efficient for small data sets or nearly sorted data
- Involves shifting elements to make room for the inserted element
- Generally performs better than selection sort on partially sorted arrays

💡 Intuition
---
- [insertion sort animation](https://csvistool.com/InsertionSort)


🏃 Implementation
---
```c++
void insertionSort(std::vector<int>& array) {
  for (int i = 1; i < array.size(); i++) {
    int currentElement = array[i];
    int k;
    for (k = i - 1; k >= 0 && array[k] > currentElement; k--) {
      array[k + 1] = array[k];
    }

    array[k + 1] = currentElement;
  }
}
```
- time complexity: 
  - best case: $𝐎(n)$
  - average and worst cases: $`\displaystyle (n-1)+(n-2)+\cdots+1=\frac{(n-1)n}{2}=𝐎(n^2)`$


Selection sort vs. insertion sort
---
- The main difference lies in how they `select and place elements` in a sorted sequence
  - `Selection` sort scans the `unsorted` part to find the `minimum/maximum` element
  - `Insertion` sort scans the `sorted` part to find the `correct position` to place the element
- Both algorithms are simple and easy to understand, but their efficiency can vary depending on the characteristics of the input data
  - Insertion sort is generally preferred when the array is already partially sorted
    - as it can be more efficient in such cases


Bubble sort
---
- sorts the array in multiple passes
- each pass successively swaps unordered adjacent elements

💡 Intuition
---
- [bubble sort animation](https://csvistool.com/BubbleSort)


🏃 Implementation
---
```c++
void bubbleSort(std::vector<int>& array) {
  bool needNextPass = true;
  
  for (int k = 1; k < array.size() && needNextPass; k++) {
    needNextPass = false;
    for (int i = 0; i < array.size() - k; i++) {
      if (array[i] > array[i + 1]) {
        std::swap(array[i], array[i+1]);
        needNextPass = true;
      }
    }
  }
}
```
- time complexity: 
  - best case: $𝐎(n)$
  - average and worst cases: $`\displaystyle (n-1)+(n-2)+\cdots+1=\frac{(n-1)n}{2}=𝐎(n^2)`$


Merge sort
---
- based on `divide and conquer` approach with steps:
- `Divide`: The original array is divided into two halves, and this process continues `recursively` until each subarray contains fewer than two elements
- `Conquer`: Each subarray is sorted individually using the merge sort algorithm
- `Merge`: The sorted subarrays are merged back together to obtain the final sorted array


💡 Intuition
---
- [merge sort animation](https://csvistool.com/MergeSort)


🏃 Implementation
---
```c++
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
```
- Time complexity: $\displaystyle T(n) = T(\frac{n}{2})+T(\frac{n}{2})+2n-1=𝐎(n\log n)$ for all cases


Quicksort
---
- based on `divide and conquer` approach with steps:
- `Divide`:
  - Choose any element in the array as the `pivot`
  - Rearrange the elements so that all elements `less than or equal to the pivot` are on its `left`, and all elements `greater than the pivot` are on its `right`
    - This process is called `partitioning`
  - The pivot is now in its correct position
- `Conquer`:
  - Recursively sort the subarrays to the left and right of the pivot
- `Combine`:
  - No explicit combining step is needed
  - The sorted subarrays are already in place
- `Pivot Selection` with various strategies:
  - Always picking the `first or last` element
  - Choosing the `middle` element
  - Selecting a `random` element


💡 Intuition
---
- [quick sort animation](https://csvistool.com/Quicksort)


🏃 Implementation
---
```c++
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
```
- Time complexity: 
  - worst-case: $𝐎(n^2)$
    - when every time we picked a `bad` pivot such as the `mininum` or `maximum` element
    - Then, one partition will be empty and the other will have all of the remaining data, causing Quicksort to `degenerate into a Selection Sort`
  - best-case:  $T(n) = T(\frac{n}{2})+T(\frac{n}{2})+n=𝐎(n\log n)$
    - When a `perfect` pivot, the `median` element, is chosen as every time
    - then each partition will have half of the remaining data
  - average case: $𝐎(n\log n)$


Heap sort
---
- sorts using a `binary heap`
- Binary heap properties
  - Shape property: It is a `complete binary tree`
     - each non-last level is full
     - the `last level` may not be full and all its leaves are `placed leftmost`
  - Heap property: 
    - Max heap: each node is `greater than or equal to` any of its children
    - Min heap: each node is `less than or equal to` any of its children
- A binary heap can be stored in a vector or an array if the heap size is known in advance
  - The `root` is at position `0`, 
    - its two children are at positions 1 and 2 
  - For a node at position `i` 
    - its `left` child is at position `2i + 1`
    - its `right` child is at position `2i + 2` 
    - its `parent` is at `⌊(i - 1)/2⌋`


💡 Intuition
---
- [Heap animation](https://csvistool.com/Heap)
- If the underlying array `indexes from 1`, then
  - The `root` is at position `1`, 
    - its two children are at positions 2 and 3 
  - For a node at position `k` 
    - its `left` child is at position `2k`
    - its `right` child is at position `2k + 1` 
    - its `parent` is at `⌊k/2⌋`


The heap class
---
- The `void insert(const T &value)` method `bubbles up the new node`
  - appends the the new node with value to the tree 
  - swaps the node with its parent if the node is greater than its parent
  - This process continues until 
    - the new node becomes the root or 
    - is not greater than its parent
- The `T extractMax()` method `sinks down the last node`
  - removes and returns the root, To maintain the heap property, 
    - moves the last node to the root position 
    - swaps it with its larger child if it is less than the larger child 
  - This process continues until the last node becomes a leaf or is not less than its children


🏃 Implementation
---
```c++
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
```


Heap sort
---
- creates a heap and add all the elements from the vector
- removes all the elements from the heap and put back to the vector

```c++
template <typename T>
void heapSort(std::vector<T> &vec)
{
  Heap<T> heap(vec);
  for (size_t i = 0; i < vec.size(); i++)
  {
    vec[i] = heap.extractMax();
  }
}
```  
- Time complexity: $𝐎(n\log n)$ for all cases


🏃 Exercise
---
- Compare merge sort, quick sort and heap sort


# Non-comparison sorting algorithms

[Bucket Sort](https://en.wikipedia.org/wiki/Bucket_sort)
---
- works for keys of small integers `without comparing the keys`
  - also called `index sort`
- a `distribution sort` that can be implemented with comparisons
  - making it a comparison sort algorithm
- bucket sort is `stable`, i.e
  - the order of two unsorted elements with the same key value is not changed in the sorted array
- Steps
  - `Scatter`: The input array is divided into `sorted buckets` based on the `range of values`
    - Each element $e$ is placed in its corresponding bucket $b[i]$
    - Number of buckets = range of values `(high - low)`
    - The index $i$ of the target bucket for $e$ is determined by: $e-low$
  - `Sort`: The elements within each non-empty bucket are sorted using a `stable` sorting algorithm
    - such as insertion sort
  - `Gather`: The sorted elements from each bucket are combined to form the final sorted array


💡 Intuition
---
| Distribute elements into buckets | Sort each non-empty bucket |
| --- | --- |
| ![tobucket](./images/tobucket.png) | ![sortbucket](./images/sortbucket.png) |

- [bucket sort animation](https://www.cs.usfca.edu/~galles/visualization/BucketSort.html)


🏃 Implementation
---
```c++
// 2. sorts a vector of integers ranging from low to high
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
```
- Time complexity: 
  - Worst case: when all elements are put in the same bucket
    - then the time complexity is bounded by the sorting algorithm used to sort the elements in the single bucket: ex. $𝐎(n^2)$ for insertion sort, $𝐎(n\log n)$ for merge sort.
  - Best case: $𝐎(n)$
    - when each bucket contains at most 1 element
  - Average case: ${\displaystyle 𝐎\left(n+{\frac {n^{2}}{k}}+k\right)}$
    - $n$ is the number of elements, $k$ is the number of buckets


Counting sort
---
- sorts integers within a specific range efficiently
- determines `the frequency of each distinct element` in the input list
  - then uses this frequency information to place each element in its correct position in the output list
- Steps
  - `Finding the Range`: 
    - determines the minimum and maximum values in the input array to calculate the range
    - $r$: range = maximum - minimum + 1
  - `Count Array Initialization`: 
    - The count array is created with a size equal to the range of the input values 
    - All elements are initialized to zero
  - `Counting Frequencies`: 
    - Each element in the input array is mapped to the count array
    - which stores the `frequency of each element`
  - `Cumulative Count`: 
    - The count array is modified to store the `cumulative count of elements`
    - This helps in placing elements in the correct positions in the output array
  - `Building the Output Array`: 
    - The input array is traversed in `reverse order` to maintain stability
    - Elements are placed in their correct positions in the output array
  - `Copying Back to Original Array`: 
    - The sorted elements from the output array are copied back to the original array


💡 Intuition
---
- [counting sort animation](https://www.cs.usfca.edu/~galles/visualization/CountingSort.html)


🏃 Implementation
---
```c++
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
```
- Time complexity: $𝐎(n+r)$


[Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
---
- sorts elements, such as `integers or strings`, by processing them `digit by digit` or `character by character`
  - groups elements based on their individual digits (place value) and sorts them by repeatedly considering each significant digit
- Two variations
  - `Least Significant Digit (LSD) Radix Sort`: Sorts from the `rightmost` (least significant) digit `to` the `leftmost`.
  - `Most Significant Digit (MSD) Radix Sort`: Sorts from the `leftmost` (most significant) digit `to` the `rightmost`
- uses a `stable sorting` algorithm (commonly counting sort) as a subroutine to sort the digits
  - This ensures that the relative order of numbers with the same digit value is preserved
- performs `multiple passes` over the data
  - each pass sorting based on a single digit position
  - The number of passes depends on the number of digits in the largest number
- The `base (radix)` of the numbering system `determines the number of buckets` used in each pass
  - Commonly used bases include 10 (decimal system) and 2 (binary system)
- highly efficient for large datasets with `fixed-length` elements


💡 Intuition
---
- [LSD Radix Sort simulation](https://csvistool.com/LSDRadix)
- *other simulators*
  - [Radix Sort 2](https://cmps-people.ok.ubc.ca/ylucet/DS/RadixSort.html)
  - [Radix sort 3](https://liveexample.pearsoncmg.com/dsanimation13ejava/RadixSorteBook.html)


🏃 Implementation of LSD radix sort
---
```c++
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
```


- Time complexity: $𝐎(d(n + k))$ for the worst case
  - $d$ is the number of digits, $n$ is the number of elements
  - $k$ is the range of the digit values 
    - for base 10, k = 10



Sort algorithm summary: Comparison Sort vs. Non-Comparison Sort
---
| Feature | Comparison Sort | Non-Comparison Sort |
|---------|-----------------|---------------------|
| Method | Uses `comparisons` to determine the order of elements | Uses `operations other than comparisons` to sort |
| Examples | Selection sort, Insertion sort, Bubble sort<br>Quicksort, Heapsort, Merge sort | Radix sort, Bucket sort |
| Performance | Average-case lower bound of $\Omega(n \log n)$ comparisons | Can achieve $𝐎(n)$ performance assuming elements are constant-sized |
| Adaptability | Easily adapts to complex orders and data types | Typically requires specialized versions for each data type |
| Stability | Depends on the algorithm (e.g., Merge sort is stable) | Not inherently related to the sorting method |



---
# Optional topics

[External sort](https://en.wikipedia.org/wiki/External_sorting)
---
- sort data in a large external file with $n$ elements using a variation of merge sort
  - suppose internal sort can handle $N$ elements each time
  - read a part of size $N$, sort it, and save the sorted part until done
    - denote the sorted parts as $S_1, S_2, \cdots, S_n$
  - merge the sorted parts pairwise into $S_{(1,2)}, S_{(3,4)}, \cdots, S_{(n-1,n)}$
    - keep merging until done
- time complexity: $𝐎(n\log n)$


📝 Practice on external sort
---
- [create a large data file](./demos/createLargeFile.cpp)
- [sort the large data file](./demos/sortLageFiles.cpp)



C++ STL sorting algorithms
---
- C++ STL `std::sort` function 
  - used to sort elements in a container that supports `random access` such as arrays and vectors
- **Syntax**: std::sort(start, end, comparator)
  - **start**: Pointer or iterator to the beginning of the array or vector
  - **end**: Pointer or iterator to the end of the array or vector
  - **comparator**: (Optional) A comparison function that determines the sort order
    - defines custom sorting behavior, such as `descending` order using std::greater<>()
    - by default std::sort arranges elements in `ascending` order
- **Average time complexity**:  $𝐎(n\log n)$
  - $n$ is the number of elements to be sorted
- `Containers without random access` have their own sort functions
  - ex. `std::list::sort(Compare comp)` for `std::list`
    - **Syntax**:
      - `template<typename Compare> void sort(Compare comp)` sorts the elements in `ascending` order using the default comparison operator<
      - allows custom sorting using a comparison function comp
    - **Average time complexity**:  $𝐎(n\log n)$

🍎 Example
---
```c++
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
void printvec(const std::vector<T> vec)
{
  for (auto num : vec)
  {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
}

template <typename T>
void printlist(const std::list<T> lst)
{
  for (auto num : lst)
  {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> vec = {4, 2, 5, 3, 1};
  // Ascending order
  std::sort(vec.begin(), vec.end());
  printvec(vec);
  // Descending order
  std::sort(vec.begin(), vec.end(), std::greater<int>());
  printvec(vec);

  std::list<int> myList = {8,6,7,9,10};
  myList.sort(); // Ascending order
  printlist(myList);
  myList.sort(std::greater<int>()); // Descending order
  printlist(myList);
  return 0;
}
```

C++ STL heap functions
---
- C++ STL does not have a dedicated heap class
  - but it provides `a set of functions` that allow you to work with heaps using `any random access container`, like std::vector
- The relevant functions are found in the <algorithm> header and include:
  - `std::make_heap`: Converts a range into a max heap.
  - `std::push_heap`: Adds an element to the heap and reorders it to maintain the heap property
  - `std::pop_heap`: Removes the largest element from the heap and reorders it
  - `std::sort_heap`: Turns a heap into a sorted range
  - `std::is_heap`: Checks if a range is a max heap
  - `std::is_heap_until`: Finds the largest subrange that is a max heap
- The `std::priority_queue` container adaptor implements a `max heap` internally


🍎 Example
```c++
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {10, 20, 30, 5, 15};
    std::make_heap(v.begin(), v.end());

    std::cout << "The maximum element of heap is : " << v.front() << std::endl;

    v.push_back(40);
    std::push_heap(v.begin(), v.end());

    std::cout << "After adding one more element : " << v.front() << std::endl;

    std::pop_heap(v.begin(), v.end());
    v.pop_back();

    std::cout << "After removing the largest element : " << v.front() << std::endl;

    return 0;
}
```

# References
- [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
  - [Comparison of Sorting Algorithms](https://coderslegacy.com/comparison-of-sorting-algorithms/)
- [visualgo](https://visualgo.net/)


