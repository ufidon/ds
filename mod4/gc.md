# [Graph Coloring](https://en.wikipedia.org/wiki/Graph_coloring)

The graph coloring problem
---
- Assigns colors to the `vertices` of a graph such that `no two adjacent vertices share the same color`
- Key points
  - `Proper Coloring`: a `solution` to the graph coloring problem
  - `Chromatic Number`: the `smallest number of colors` needed to color the graph properly


Types of Graph Coloring
---
- `Vertex Coloring`: Assign colors to `vertices` such that no two adjacent vertices share the same color
- `Edge Coloring`: Assign colors to `edges` such that no two edges sharing a common vertex have the same color
- `Face Coloring`: Assign colors to `regions (faces)` of a planar graph such that no two regions sharing a boundary have the same color


Applications
---
- `Scheduling Problems`: Assigning time slots or resources to tasks, where conflicting tasks (sharing a common resource or time) must be assigned different slots
- `Register Allocation`: In compilers, assigning variables to a limited number of CPU registers
- `Frequency Assignment`: Assigning frequencies to radio stations or cell towers so that neighboring stations/towers do not interfere with each other.
- `Map Coloring`: Coloring regions on a map such that no two adjacent regions share the same color
  - a famous example is `the Four Color Theorem`


Complexity
---
- `NP-Completeness`: The general graph coloring problem is NP-complete, meaning that there is no known polynomial-time algorithm to solve it for all graphs
- `Approximation Algorithms`: Various algorithms exist that provide approximate solutions, especially for specific types of graphs 
  - e.g., planar graphs, bipartite graphs


Examples of Graph Coloring
---
- `Bipartite Graphs`: Can be colored with 2 colors
- `Planar Graphs`: According to the Four Color Theorem, any planar graph can be colored with no more than 4 colors
- `General Graphs`: Require a number of colors equal to the graph's chromatic number, which can vary widely



Algorithms for Graph Coloring
---
- `Greedy Coloring Algorithm`: An iterative algorithm that assigns the smallest possible color to each vertex, often yielding an approximate solution rather than the optimal
- `Backtracking`: An exhaustive search algorithm that tries all possible colorings, backtracking when an invalid coloring is found
- `Heuristic Algorithms`: Algorithms that use various heuristics (e.g., largest degree first) to improve the performance and quality of the coloring


🏃 Implementation
---
- A greedy algorithm for vertex coloring
```c++
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// A class to represent a graph
class Graph
{
  int V;               // No. of vertices
  std::list<int> *adj; // Pointer to an array containing adjacency lists

public:
  Graph(int V);               // Constructor
  void addEdge(int v, int w); // To add an edge to the graph
  void greedyColoring();      // Prints greedy coloring of the graph
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v); // For undirected graph
}

void Graph::greedyColoring()
{
  std::vector<int> result(V, -1); // Assign the first color to first vertex
  result[0] = 0;

  std::vector<bool> available(V, false); // Temporary array to store the available colors

  for (int u = 1; u < V; u++)
  {
    // Process all adjacent vertices and flag their colors as unavailable
    for (auto i : adj[u])
      if (result[i] != -1)
        available[result[i]] = true;

    // Find the first available color
    int cr;
    for (cr = 0; cr < V; cr++)
      if (available[cr] == false)
        break;

    result[u] = cr; // Assign the found color

    // Reset the values back to false for the next iteration
    for (auto i : adj[u])
      if (result[i] != -1)
        available[result[i]] = false;
  }

  // Print the result
  for (int u = 0; u < V; u++)
    std::cout << "Vertex " << u << " --->  Color " << result[u] << std::endl;
}

int main()
{
  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(0, 2);
  g1.addEdge(1, 2);
  g1.addEdge(1, 3);
  g1.addEdge(2, 3);
  g1.addEdge(3, 4);
  std::cout << "Coloring of graph 1\n";
  g1.greedyColoring();

  return 0;
}
```

# References
- [Guide to Graph Coloring: Algorithms and Applications](https://link.springer.com/book/10.1007/978-3-030-81054-2)