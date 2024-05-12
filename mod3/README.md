# Complexity analysis
- Time and space complexity
  - Best, average and worst case
- Asymptotic analysis
  - Big ${O, Ω, Θ}$ notation


Objectives
---
- Estimate algorithm efficiency using the Big O notation
  -  explain growth rates and 
     -  why constants and nondominating terms can be ignored
  - describe common growth functions 
    - constant, logarithmic, log-linear, quadratic, cubic, and exponential
- Analyze and determine the complexity of various types of algorithms
  -  binary search
  -  selection sort
  -  Tower of Hanoi
- Design efficient algorithms for 
  - finding 
    - Fibonacci numbers using dynamic programming
    - the GCD using Euclid’s algorithm
    - prime numbers using the sieve of Eratosthene
    - the closest pair of point using the divide-and-conquer approach
    - a convex hull for a set of points
  - solving
    -  the Eight Queens problem using the backtracking approach
    -  string matching using Boyer-Moor and KMP algorithms


Executing Time 
---
- can be used to measure the performance of algorithms
  - by profilers
- two problems
  - depends on execution environment
  - depends on specific input


Growth Rate
---
- a theoretical measure of algorithm performance
- find how fast `the time consumed` by a algorithm increases when `the size of input` increases
  - $t=f(inputSize)$, find the function $f$
  - its *order of magnitude* can be denoted by Big ${O, Ω}$ or ${Θ}$
- Constant time: $O(1)$
  - independent from the input size
  - for example, access an element from an array
- provides a good theoretical estimate of algorithm efficiency
- but two algorithms of the same time complexity are not necessarily equally efficient


Big ${O, Ω, Θ}$
---
<table>
  <thead>
    <tr>
      <th>Notation</th>
      <th>Definition</th>
      <th>Representation</th>
      <th>Properties</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Big O (O)</td>
      <td>Describes the upper bound or worst-case scenario of an algorithm's time complexity.</td>
      <td>O(f(n)) represents an upper bound on the growth rate of the function f(n) as n approaches infinity.</td>
      <td>
        <ul>
          <li>Defines the maximum growth rate of a function.</li>
          <li>Formally, f(n) is O(g(n)) if there exist constants c and n0 such that f(n) ≤ c * g(n) for all n ≥ n0.</li>
          <li>Commonly used to analyze the worst-case performance of algorithms.</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>Big Omega (Ω)</td>
      <td>Describes the lower bound or best-case scenario of an algorithm's time complexity.</td>
      <td>Ω(f(n)) represents a lower bound on the growth rate of the function f(n) as n approaches infinity.</td>
      <td>
        <ul>
          <li>Defines the minimum growth rate of a function.</li>
          <li>Formally, f(n) is Ω(g(n)) if there exist constants c and n0 such that f(n) ≥ c * g(n) for all n ≥ n0.</li>
          <li>Commonly used to analyze the best-case performance of algorithms.</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>Big Theta (Θ)</td>
      <td>Describes the tight bound or average-case scenario of an algorithm's time complexity.</td>
      <td>Θ(f(n)) represents a proportional bound on the growth rate of the function f(n) as n approaches infinity.</td>
      <td>
        <ul>
          <li>Defines both the maximum and minimum growth rates of a function.</li>
          <li>Formally, f(n) is Θ(g(n)) if there exist constants c1, c2, and n0 such that c1 * g(n) ≤ f(n) ≤ c2 * g(n) for all n ≥ n0.</li>
          <li>Commonly used to analyze the average-case performance of algorithms.</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>



Best, Worst, and Average Cases 
---
- an analysis of inputs
- best-case: results in the shortest execution time
- worst-case: results in the longest execution time 
  - determines the lower bound of performance
  - easier to obtain and commonly used
- average-case: 
  - attempts to determine the average amount of time among all possible input of the same size
  - ideal, but difficult to perform
    - hard to determine the relative probabilities and distributions of various input instances for many problems


<table>
  <thead>
    <tr>
      <th>Data Structure</th>
      <th>Operation</th>
      <th>Worst Case</th>
      <th>Average Case</th>
      <th>Best Case</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="3">Array</td>
      <td>Insertion (at end)</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Deletion (at end)</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Search</td>
      <td>O(n)</td>
      <td>O(n)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td rowspan="3">Linked List</td>
      <td>Insertion (at beginning)</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Deletion (at beginning)</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Search</td>
      <td>O(n)</td>
      <td>O(n)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td rowspan="3">Stack</td>
      <td>Push</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Pop</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Peek</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td rowspan="3">Queue</td>
      <td>Enqueue</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Dequeue</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
    <tr>
      <td>Peek</td>
      <td>O(1)</td>
      <td>O(1)</td>
      <td>O(1)</td>
    </tr>
  </tbody>
</table>



Example 💡: find the growth rate of linear search
---
```c++
int linearSearch(int arr[], int n, int x)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == x)
    {
      return i; // Element found at index i
    }
  }
  return -1; // Element not found
}
```

- The execution time of Linear search is proportional to the size of the array
  - so it has an order of $n$
  - denoted as $O(n)$
- analysis
  - ignore multiplicative constants
  - ignore non-dominating terms


Practice 📝 : determine Big-O
---
- Repetition
- Sequence 
- Selection
- Logarithm


Repetition: simple loops
---
```c++
for(i=1; i<=n; i++){
  s += i;
}
```
- Time complexity: $T(n) = cn = O(n)$


Repetition: nested loops
---
- matrix multiplication: $C=A\times B$
  ```c++
  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++){
      for(k=1; k<=n; k++){
        c[i][j] += a[i][k]*b[k][j];
      }
    }
  }
  ```
- Time complexity: $T(n) = cn^3 = O(n^3)$

- partial sum: ${\displaystyle S[i] = \sum_{k=1}^{i} k}$
  ```c++
  for(i=1; i<=n; i++){
    for(k=1; k<=i; k++){
      S[i] += k;
    }
  }
  ```
- Time complexity: ${\displaystyle T(n) = c\frac{n(n+1)}{2} = O(n^2)}$  

- print a table: n rows x K columns
  ```c++
  for(i=1; i<=n; i++){
    for(k=1; k<=K; k++){
      cout << T[i][k];
    }
    cout<<endl;
  }
  ```
- Time complexity: $T(n) = cKn = c'n = O(n)$ 


Sequence
---
- print a table with a header: n rows x K columns
  ```c++
  for(k=1; k<= K; k++){
    cout << H[k];
  }

  for(i=1; i<=n; i++){
    for(k=1; k<=K; k++){
      cout << T[i][k];
    }
    cout<<endl;
  }
  ```
- Time complexity: $T(n) = cK + cKn \approx  c'n = O(n)$ 


Selection
---
- Linear search for e in list
  ```c++
  bool found = false;
  for(auto& o: list){
    if (o == e){
      found = true;
      cout<<e<<endl;
    }     
  }

  if(!found) {
    for(auto& o: list){
      cout << o;
    }
  }
  ```
- Time complexity: $T(n)=O(n)+O(n)=O(n)$
  - An algorithm with the  $O( n)$ time complexity is called a *linear algorithm*

- Logarithm time: Binary search in an ordered array
  ```c++
  int bsearch(int a[], int t, int left, int right){
    while(left < right){
      int m = (left+right)/2;
      if(a[m] == t)
        return m;
      else if(a[m] < t)
        return bsearch(a, t, m+1, right);
      else
        return bsearch(a, t, left, m-1);
    }
  }
  ```
- Time complexity: $T(n)=T(\frac{n}{2})+c = O(\log n)$ 
  - An algorithm with the  $O(\log n)$ time complexity is called a *logarithmic algorithm*

Selection sort
---
- Find the minimum from the unsorted part and append it to the sorted part
  ```c++
  for(i=1; i<=n-1; i++){
    int min = a[i+1];
    int minIndex = i+1;
    for(j=i+1; j<=n; j++){
      if(a[j] < min){
        minIndex = j; 
        min = a[j];        
      }
    }
    swap(a[i], a[minIndex]);
  }
  ```
- Time complexity: ${\displaystyle T(n) = (n-1) + c + (n-2) + c + \cdots + 1+c=\frac{(n-1)n}{2}+(n-1)c = O(n^2)}$
  - An algorithm with the $O(n^2)$ time complexity is called a *quadratic algorithm*


Tower of Hanoi
---
- moves n disks from tower A to tower B via tower C recursively as follows:
  - Move the first n – 1 disks from A to C via B
  - Move disk n from A to B
  - Move n - 1 disks from C to B via A
- no larger disk is put on smaller one at each move

```c++
void Hanoi(n, A, B, C){
  Hanoi(n-1, A, C, B);
  cout << "Disk " << n << ":" << A <<"->" << B;
  Hanoi(n-1, C,B,A);
}
```
- Time complexity: $T(n) = T(n-1)+c+T(n-1) \Rightarrow T(n) = O(2^n)$


Common Recurrence Relations
---
| Recurrence relation | Result | Example |
| --- | --- | --- |
| $T(n)=T(\frac{n}{2})+O(1)$ | $T(n)=O(\log n)$ | Binary search, Euclid's GCD |
| $T(n)=T(n-1)+O(1)$ | $T(n)=O(n)$ | Linear search |
| $T(n)=2T(\frac{n}{2})+O(1)$ | $T(n)=O(n)$ |  |
| $T(n)=2T(\frac{n}{2})+O(n)$ | $T(n)=O(n\log n)$ | Merge sort |
| $T(n)=2T(\frac{n}{2})+O(n\log n)$ | $T(n)=O(n\log^2 n)$ |  |
| $T(n)=T(n-1)+O(n)$ | $T(n)=O(n^2)$ | Selection sort, insertion sort|
| $T(n)=2T(n-1)+O(1)$ | $T(n)=O(n^2)$ | Tower of Hanoi |
| $T(n)=T(n-1) + T(n-2) +O(1)$ | $T(n)=O(n^2)$ | Recursive Fibonacci algorithm |

- Order of common growth functions
  - a ≺ b means b dominates a so a in O(a+b) can be omitted

$$O(1) ≺ O(\log n) ≺ O(n) ≺ O(n\log n) ≺ O(n^2) ≺ O(n^3) ≺ O(2^n) ≺ O(3^n)$$


Recursive [Fibonacci](https://en.wikipedia.org/wiki/Fibonacci_sequence) algorithm
---
- $F_0=0, F_1=1, F_n=F_{n-1}+F_{n-2}$
```c++
long fib(long n){
  if(n==0) return 0;
  if(n==1) return 1;
  return fib(n-1)+fib(n-2);
}
```
- Time complexity: $T(n) = T(n-1)+T(n-2) +c \Rightarrow T(n) = O(2^n)$


Fibonacci sequence by *dynamic programming*
---
- recursive problems can be solved in two popular ways
  - top-down: divide and conquer (recursive algorithm)
    - inefficient due to repeatedly computing subproblems
  - bottom-up: dynamic programming
    - solve each subprogram only once 
    - store the results for later use to avoid repeated computing
    - solve subproblems first, then combine the solutions to obtain the overall solution

```c++
long fib(long n){
  long f0=0, f1=1, f2=1;
  if(n==0) return f0;
  else if(n==1) return f1;
  else if (n==2) return f2;

  for(int i=3; i<= n; i++){
    f0=f1;
    f1=f2;
    f2= f0+f1;
  }
  return f2;
}
```
  - Time complexity: $O(n)$


Practice 📝: find the *greatest common divisor (gcd)* of two integers
---
- Analyze the following algorithms and find their time complexities
- suppose $m\ge n$
- GCD algorithm version 1: brute force
  - check all possible divisors
  ```c++
  int gcd(int m, int n){
    int gcd = 1;
    for(int d=2; d<=m && d<=n; d++){
      if(m%k==0 && n%k==0) gcd = k;
    }
    return gcd;
  }
  ```
  - Time complexity: $O(n)$
- GCD algorithm version 2: brute force
  - check half of all possible divisors
  ```c++
  int gcd(int m, int n){
    int gcd = 1;
    for(int d=min(m,n); d>=1; d--){
      if(m%k==0 && n%k==0){
        gcd = k;
        break;
      } 
    }
    return gcd;
  }
  ```
  - Time complexity: $O(n)$


[Euclid's algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)
---
- Let gcd(m, n) denote the gcd for integers m and n:
  - If m % n is 0, gcd (m, n) is n
  - Otherwise, gcd(m, n) is gcd(n, m % n)

  ```c++
  int gcd(int m, int n){
    if(m%n == 0)
      return n;
    else
      return gcd(n, m%n);
  }
  ```
  - Time complexity: $O(\log n)$


Find all prime numbers no larger than n
---
- divide each integer i from 2 to ${\displaystyle \frac{i}{2}}$
  - check all possible divisors
  ```c++
  for(int i=2; i<= n; ++i){
    boolean isprime = true;
    for(int d=2; d<= i/2; ++d){
      if(i%d == 0){
        isprime = false;
        break;
      }
    }
    if(isprime) cout<<i<<endl;
  }
  ```
  - Time complexity: $O( n^2)$
- divide each integer i  from 2 to $\sqrt{i}$
  - check divisors up to $\sqrt{n}$
  ```c++
  for(int i=2; i<= n; ++i){
    boolean isprime = true;
    for(int d=2; d<= Math.sqrt(i); ++d){
      if(i%d == 0){
        isprime = false;
        break;
      }
    }
    if(isprime) cout<<i<<endl;
  }
  ```
  - Time complexity: $O(n\sqrt{n})$
- Improved: divide each prime integer i  from 2 to $\sqrt{i}$
  - check prime divisors up to $\sqrt{n}$
  ```c++
  #include <iostream>
  #include <vector>

  int main()
  {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<int> primes;
    for (int i = 2, squareRoot = 1; i <= n; ++i)
    {
      bool isPrime = true;
      if (squareRoot * squareRoot < i)
        ++squareRoot;

      for (size_t k = 0; k < primes.size() && primes[k] <= squareRoot; k++)
      {
        if (i % primes[k] == 0)
        {
          isPrime = false;
          break;
        }
      }

      if (isPrime)
      {
        primes.push_back(i);
        std::cout << i << std::endl;
      }
    }

    return 0;
  }
  ```
  - Time complexity: ${\displaystyle O(\frac{n\sqrt{n}}{\log n})}$
    - derive with ${\displaystyle \pi(n) \approx \frac{n}{\log n}}$
    - where $\pi(n)$ denotes the number of prime numbers no larger than $n$ 
- [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
  ```c++
  #include <iostream>
  #include <vector>

  int main()
  {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<bool> primes(n + 1, true);

    for (int k = 2; k * k <= n; ++k)
    {
      if (primes[k])
      {
        for (int i = k; k * i <= n; i++)
        {
          primes[k * i] = false;
        }
      }
    }

    for (int k = 2; k <= n; ++k)
    {
      if (primes[k])
      {
        std::cout << k << std::endl;
      }
    }

    return 0;
  }
  ```
  - Time complexity: ${\displaystyle O(\frac{n\sqrt{n}}{\log n})}$



Practice 📝: solve the [Closest-pair problem](https://en.wikipedia.org/wiki/Closest_pair_of_points_problem) with divide-and-conquer
---
- Given a set of points, find the two points that are nearest to each other
- brute force: computes the distances between all pairs of points and finds the one with the minimum distance
  - Time complexity: ${\displaystyle T(n)={n \choose 2} = \frac{n(n-1)}{2} = O(\frac{n\sqrt{n}}{\log n})}$
- divide-and-conquer
  - Step 1: sort the points in increasing order of x-coordinates then y-coordinates into a sorted list $S$ of points
    - Time complexity with mergesort: ${\displaystyle T(n) = O(n\log n)}$
  - Step 2: Divide $S$ into two subsets $S_1$ and $S_2$ with its midpoint $m$
    - let $m$ in $S_1$, recursively find the closest pair $p_1$ and $p_2$ recursively
  - Step 3: Find the closest pair $p_3$ between $S_1$ and $S_2$. Then the closest pair is the closest one from $(p_1,p_2,p_3)$
    - Time complexity of Step 2 and Step 3: 
      - $`{\displaystyle T(n)=\underbrace{2T(\frac{n}{2})}_{Step\ 2} + \underbrace{O(n)}_{Step 3} = O(n\log n)}`$


Practice 📝: solve the [eight queens problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle) with backtracking
---
-  place a queen in each row on a chessboard such that no two queens can attack each other
   -  many solutions
- algorithm 1: recursion
  - [source code](./demos/EightQueensRecursion.cpp)
  - extend it to find all solutions
- algorithm 2: backtracking
  - [source code](./demos/EightQueensBackTracking.cpp)
  - extend it to find all solutions
- generalize 8-queens problem to n-queens problem


Practice 📝: Computational Geometry: the [convex hull problem](https://en.wikipedia.org/wiki/Convex_hull) with backtracking
---
- Given a set of $n$ points, a convex hull of size $h$ is the smallest convex polygon that encloses all these
points
  - every line connecting two vertices is inside the polygon
- [algorithms to be discussed](https://en.wikipedia.org/wiki/Convex_hull_algorithms)
  - Gift wrapping algorithm
    - [source code](./demos/ConvexHullbyGiftWrapping.cpp)
    - Time complexity: ${\displaystyle O(nh)}$
  - Graham's algorithm
    - [source code](./demos/ConvexHullbyGraham.cpp)
    - Time complexity: ${\displaystyle O(n\log n)}$


Practice 📝: the [string search problem](https://en.wikipedia.org/wiki/String-searching_algorithm) 
---
- Find a substring or pattern of length $m$ in a given string or text of length $n$
  - two methods in the String class
    - contains(pattern) tests if a pattern is in the string
    - indexOf(pattern) returns the index of the first matching of the pattern in the string
- algorithms to be discussed
  -  brute force
     -  [source code](./demos/StringMatch.cpp)
     -  Time complexity: $O(nm)$
  -  Boyer-Moore algorithm
     -  [source code](./demos/StringMatchBoyerMoore.cpp)
     -  Time complexity: $O(nm)$
  -  Knuth-Morris-Pratt  algorithm
     -  [source code](./demos/StringMatchKMP.cpp)
     -  Time complexity: $O(n + m)$



# Math appendix
- ${\displaystyle \sum_{k=1}^n k = \frac{n(n+1)}{2}}$
- ${\displaystyle \sum_{k=0}^n a^k = \frac{a^{n+1}-1}{a-1}}$
- ${\displaystyle \sum_{k=0}^n 2^k = \frac{2^{n+1}-1}{2-1}=2^{n+1}-1}$

# References
