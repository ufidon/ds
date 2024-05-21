# Hashing


Objectives
---
- Explain hashing usage, load factor and need for rehashing
- Design hash function to map a key to an index
  - obtain the hash code for an object 
- Handle collisions using 
  - open addressing 
    - linear probing, quadratic probing, and double hashing
  - separate chaining 


Why hashing?
---
| Feature  | Dynamic Array | Balanced Binary Search Tree (BST) | Hash Table |
|-------|---------|-------|-------|
| **Access Time**    | 𝐎(1) (direct index access)  | 𝐎(log n)  | 𝐎(1) (average), 𝐎(n) (worst)      |
| **Insertion Time**  | 𝐎(1) (amortized, end) / 𝐎(n) (middle) | 𝐎(log n)  | 𝐎(1) (average), 𝐎(n) (worst)   |
| **Deletion Time** | 𝐎(n)  | 𝐎(log n)   | 𝐎(1) (average), 𝐎(n) (worst) |
| **Search Time**  | 𝐎(n) / 𝐎(log n) (if sorted)  | 𝐎(log n)| 𝐎(1) (average), 𝐎(n) (worst)  |
| **Memory Usage**   | Efficient (low overhead)   | Moderate (node pointers)    | High (hash table + linked lists or other structures for collisions) |
| **Order Preservation**  | Yes (maintains order) | Yes (in-order traversal)  | No  |
| **Dynamic Size**   | Yes (can resize)  | Yes (grows as needed)  | Yes (grows with rehashing)   |
| **Implementation Complexity** | Low   | High   | Medium  |
| **Cache Performance**  | High (contiguous memory)  | Medium   | Medium to Low (depends on collision resolution) |
| **Use Case Suitability**   | Fixed-size or frequently accessed data | Dynamic datasets, ordered data access | Fast lookups, dynamic datasets   |


❓ Question
---
Compare the advantages and disadvantages of using dynamic array, balanced BST and hash table to save
1. students in a database
   - Assume each student is identified by a SID (student identity number) uniquely
2. products in the database of an e-commerce website
   - Assume each product is identified by a PID (product identity number) uniquely
- In both cases, we want to be able to access any object directly by its ID
  - `ID (key) → Object (value)`


[Hash table](https://en.wikipedia.org/wiki/Hash_table)
---
- A table of elements (entries), each contains two parts: 
  - key,  also called a search key
  - value
- Also called dictionary, map, or associative array


What is Hashing? 
---
- In an array, an element can be retrieved using its index in 𝐎(1) time
- Hashing is to
  - `store map entries in an array named hash table`
    - each entry saved in a cell
    - a cell has `three` possible states: `occupied, marked (for deletion), or empty`
  - `use its key to access a value` directly
    - no search is needed
    - by mapping a key to an index using a `hash function`


Hash Function and Hash Code
---
- $i=h(k)$
  - $i$, index, an integer, also called hash code
  - $k$, key, such as SSN, SID, PID, etc.
  - $h$, hash function
- A `perfect` hash function maps different search key to different index
- Two or more keys are mapped to the same hash value is called a `collision`
- Hash functions are designed to be `fast and easy-to-compute in 𝐎(1) time`


[Popular simple hash functions](https://en.wikipedia.org/wiki/Hash_function)
---
| Hash Function  | Description    | Mathematical Formula| Example Calculation  |
|---------|----|---|----|
| **Division Method**    | Uses modulo operation to compute the hash value.  | $\displaystyle h(k) = k \mod m$  | $h(12345) = 12345 \mod 100 = 45$ |
| **Folding Method**   | Breaks the key into parts, adds the parts, and then applies modulo operation. | $\displaystyle h(k) = \left( \sum_{i=1}^n p_i \right) \mod m$ <br>  ▶️ $p_i$ are parts of the key | $h(123456) = (123 + 456) \mod 100 = 579 \mod 100 = 79$ |
| **Radix Transformation** | Converts key to a string and uses a polynomial accumulation.   | $\displaystyle h(k) = \left( \sum_{i=0}^{n-1} k_i \cdot b^i \right) \mod m$ <br> ▶️ $b$ is the base (commonly a small prime number) and $k_i$ are the characters of the string | $h(\text{"abc"}) = (97 \cdot 31^2 + 98 \cdot 31 + 99) \mod 100 = 54$ |
| **Simple XOR**  | XORs all the bytes of the key.  | $\displaystyle h(k) = k_1 \oplus k_2 \oplus \cdots \oplus k_n$ | $h(\text{"abc"}) = 97 \oplus 98 \oplus 99 = 96$ |
| **Multiplication Method** | Multiplies the key by a constant fraction and takes the fractional part. | $\displaystyle h(k) = \lfloor m (k A \mod 1) \rfloor$ <br>▶️ $0 < A < 1$, $k A \mod 1$ means the fractional part of $kA$, that is, $kA-⌊kA⌋$ | $h(12345) = \lfloor 100 (12345 × 0.6180339887 \mod 1) \rfloor = 62$ |
| **Mid-Square Method**  | Squares the key and extracts middle digits.  | $\displaystyle h(k) = \left( \frac{k^2}{b^r} \mod b^d \right)$ <br>▶️ $b$ is the the base of the number system representing $k$, $r$ is the right shift amount and $d$ is the number of digits extracted <br>▶️ `Special case`:<br> $`h(k) = (k^2\ \&\ 0x00FFFF00) ≫ 8`$ <br>▶️ $k$ is a 32 bits binary integer | $h(123) = (123^2 / 10^2) \mod 10^2 = 51$ |


🏃 Implementation
---
```c++
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
```


Compressing hash codes
---
- A hash table of length $L$ has only indexes from $0$ to $L-1$
  - $L$ is usually chosen to be a `prime number`
  - $L$ is also called the `number of buckets (cells)` of the hash table
- Hash code compressing: $hashCode \mod L$
- `Collision` occurred when `two or more keys` are mapped to the `same hash value`


Handling Collisions Using Open Addressing
---
- finds an `open location` in the hash table
- open addressing: 
  - linear probing
  - quadratic probing
  - double hashing
- separate chaining


Linear probing
---
- finds the next available location `sequentially`
  - $hashTable[(h(key)+i)\mod L]$, increment $i$ from zero until an available cell is found
- may cause groups of consecutive cells to be occupied
  - such a group is called a `cluster`
-  `guarantees` an available cell can be found for insertion in `non-full table`


Quadratic probing
---
- finds the next available location by $hashTable[(h(key)+i^2)\mod L]$
  - increment $i$ from zero until an available cell is found
- can avoid the clustering problem from linear probing
- may cause `secondary clustering problem`
  - the entries that collide with an occupied cell use the same probe sequence
- available cell is `not guaranteed` in non-full table


Double hashing
---
- finds the next available location by $hashTable[(h_1(key)+i×h_2(key))\mod L]$
  - increment  $i$ from zero until an available cell is found
  - $h_2(key)$ is the second hash function
    -  should never produce a zero value
- probing functions should be designed to produce a probe sequence that reaches the entire table


💡 Intuition
---
- [Hash table with open addressing simulation](https://csvistool.com/OpenHash)
  - insert, search and delete an element



Handling Collisions Using separate chaining
---
- chains the entries with the same hash index in a bucket
  - a bucket can be implemented as an array, vector, or linked list
- each cell in the hash table can be viewed as the reference to its bucket


Load Factor and Rehashing
---
- `Load factor` is the ratio of the number of `occupied` cells to the `total` number of cells
- A threshold is maintained in a hash table, typically
  - 0.5 for open addressing
  - 0.9 for separate chaining
- If the threshold is exceeded, `rehashing` is needed
  - `increase` the hash table size, typically double it
  - `reload and rehash` the entries into the new table
    - a new hash function is needed since the table size is changed



💡 Intuition
---
- [Hash table with separate chaining simulation](https://csvistool.com/ClosedHash)
  - insert, search and delete an element


🏃 Exercise
---
Analyze and supplement the code:
- [Handling collisions with rehashing](./demos/hashopen.cpp)
- [Handling collisions with chaining](./demos/hashchain.cpp)


C++ STL set, map, unordered_set, and unordered_map
---
| Feature   | `std::set` | `std::map` | `std::unordered_set`  | `std::unordered_map`  |
|------|-------|-----|------|-----|
| **Underlying Data Structure** | Self-balancing binary search tree (typically Red-Black Tree) | Self-balancing binary search tree (typically Red-Black Tree) | Hash table| Hash table   |
| **Key Order**   | Ordered   | Ordered   | Unordered  | Unordered    |
| **Duplicate Keys**  | No   | No  | No  | No  |
| **Access Time Complexity** | 𝐎(log n)  | 𝐎(log n)   | Average: 𝐎(1), Worst-case: 𝐎(n)   | Average: 𝐎(1), Worst-case: 𝐎(n)  |
| **Insertion Time Complexity** | 𝐎(log n)   | 𝐎(log n)   | Average: 𝐎(1), Worst-case: 𝐎(n)   | Average: 𝐎(1), Worst-case: 𝐎(n)  |
| **Deletion Time Complexity** | 𝐎(log n)   | 𝐎(log n)   | Average: 𝐎(1), Worst-case: 𝐎(n)    | Average: 𝐎(1), Worst-case: 𝐎(n)   |
| **Memory Usage**   | More (due to tree structure) | More (due to tree structure)| Less (hash table overhead)  | Less (hash table overhead)  |
| **Iterator Validity After Insert/Delete** | Invalidate only the erased element | Invalidate only the erased element | All iterators remain valid except for the erased element | All iterators remain valid except for the erased element |
| **Use Case**  | Ordered collection of unique elements | Ordered collection of key-value pairs | Unordered collection of unique elements | Unordered collection of key-value pairs |

- To store duplicate keys, C++ STL provides `std::multiset, std::multimap, std::unordered_multiset, and std::unordered_multimap` respectively


## Online resources
- [visualgo - visualize algorithms](https://visualgo.net/)
- [Liang animation](https://liveexample.pearsoncmg.com/liang/animation/animation.html)