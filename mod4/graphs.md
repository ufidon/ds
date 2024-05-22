# Graphs and Applications


Objectives
---
- Describe graphs with
  - vertices, edges, simple graphs, weighted/unweighted graphs 
  - directed/undirected graphs
  - visualize graphs
- Design and implement 
  - interface Graph
  - class AbstractGraph and UnweightedGraph
  - class AbstractGraph.Tree representing graph traversal
  - two graph search algorithms
    - depth-first search
    - breadth-first search
- Model and solve real-world problems with graphs
  - Seven Bridges of Königsberg problem
  - connected-circle problem
  - nine-tail problem


Basic Graph Terminologies 
---
| Term    | Definition     |
|-----|---------|
| **Graph (G)**        | A collection of `vertices (nodes)` and `edges (links)` that connect pairs of vertices.      |
| **Vertex (Node)**    | A fundamental unit of which graphs are formed, usually represented as a dot or circle.                     |
| **Edge (Link)**      | A connection between two vertices in a graph.                                                              |
| **Directed Graph**   | A graph in which edges have a direction, going from one vertex to another.                                 |
| **Undirected Graph** | A graph in which edges do not have a direction, meaning they can be traversed both ways.                   |
| **Weighted Graph**   | A graph in which edges have associated weights, typically representing costs, distances, or capacities.     |
| **Adjacency List**   | A way of representing a graph by listing each vertex and its adjacent vertices.                            |
| **Adjacency Matrix** | A 2D array representation of a graph where the cell at row i and column j indicates the presence of an edge.|
| **Degree**           | The number of edges incident to a vertex.                                                                  |
| **In-Degree**        | The number of edges directed into a vertex in a directed graph.                                            |
| **Out-Degree**       | The number of edges directed out of a vertex in a directed graph.                                          |
| **Path**             | A sequence of vertices where each adjacent pair is connected by an edge.                                   |
| **Cycle**            | A path that starts and ends at the same vertex, with all edges and vertices being distinct except for the endpoints. |
| **Connected Graph**  | A graph in which there is a path between every pair of vertices.                                           |
| **Disconnected Graph** | A graph in which at least one pair of vertices does not have a path connecting them.                     |
| **Complete Graph**   | A graph in which there is an edge between every pair of vertices.                                          |
| **Subgraph**         | A graph formed from a subset of the vertices and edges of another graph.                                   |
| **Tree**             | An acyclic connected graph.                                                                                |
| **Forest**           | A collection of disjoint trees.                                                                            |
| **Bipartite Graph**  | A graph whose vertices can be divided into two disjoint sets such that no two graph vertices within the same set are adjacent. |
| **Planar Graph**     | A graph that can be drawn on a plane without any edges crossing.                                           |
| **Graph Isomorphism** | A bijection between the vertex sets of two graphs that preserves the edge-vertex connectivity.            |
| **Eulerian Path**    | A path that visits every edge of a graph exactly once.                                                     |
| **Eulerian Circuit** | A circuit that visits every edge of a graph exactly once and starts and ends at the same vertex.           |
| **Hamiltonian Path** | A path that visits every vertex of a graph exactly once.                                                   |
| **Hamiltonian Circuit** | A circuit that visits every vertex of a graph exactly once and starts and ends at the same vertex.      |
| **Cut**              | A partition of the vertices of a graph into two disjoint subsets.                                          |
| **Clique**           | A subset of vertices of a graph such that every two distinct vertices are adjacent.                        |
| **Independent Set**  | A set of vertices in a graph, no two of which are adjacent.                                                |
| **Minimum Spanning Tree** | A subgraph of a weighted graph that connects all the vertices together without any cycles and with the minimum possible total edge weight. |
| **Shortest Path**    | The path between two vertices in a graph such that the sum of the weights of its constituent edges is minimized. |



Representing Graphs
---
| Feature                       | Adjacency List Representation         | Adjacency Matrix Representation       |
|-------------------------------|---------------------------------------|---------------------------------------|
| **Definition**                | Uses lists to represent which vertices are adjacent to each vertex | Uses a 2D array to represent edges between vertices |
| **Space Complexity**          | 𝐎(V + E)                              | 𝐎(V²)                                |
| **Edge Lookup Time Complexity** | 𝐎(V) in the worst case                | 𝐎(1)                                  |
| **Insertion Time Complexity** | 𝐎(1) to add an edge                   | 𝐎(1) to add an edge                   |
| **Deletion Time Complexity**  | 𝐎(V) to remove an edge                | 𝐎(1) to remove an edge                |
| **Ideal Use Case**            | Sparse graphs                         | Dense graphs                          |
| **Memory Efficiency**         | More efficient for sparse graphs      | Less efficient for sparse graphs      |
| **Implementation Complexity** | Moderate                              | Low                                   |
| **Traversal Efficiency**      | Efficient for iterating over neighbors| Efficient for checking edge existence |
| **Parallel Edge Handling**    | Typically requires additional data structure | Can handle with matrix values         |
| **Directed/Undirected Support** | Both                                  | Both                                  |
| **Weighted Graph Support**    | Supported (using pair/list with weights) | Supported (using matrix values)       |


💡 Intuition
---
- [Explore graph representations](https://csvistool.com/BFS)
  - Adjacency list representation
  - Adjacency matrix representation


🏃 Implementation
---
```c++
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>

template <typename T>
class Graph
{
public:
  Graph(int vertices);

  // Methods for Adjacency List representation
  void addEdgeAdjList(T src, T dest);
  void printAdjList();

  // Methods for Adjacency Matrix representation
  void addEdgeAdjMatrix(T src, T dest);
  void printAdjMatrix();

private:
  int vertices;
  std::vector<std::list<T>> adjList;
  std::vector<std::vector<int>> adjMatrix;
  std::vector<T> vertexLabels;
  int getVertexIndex(T vertex);
};

// Constructor
template <typename T>
Graph<T>::Graph(int vertices) : vertices(vertices)
{
  adjList.resize(vertices);
  adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
  vertexLabels.resize(vertices);
}

// Method to get the index of a vertex
template <typename T>
int Graph<T>::getVertexIndex(T vertex)
{
  auto it = std::find(vertexLabels.begin(), vertexLabels.end(), vertex);
  if (it != vertexLabels.end())
  {
    return std::distance(vertexLabels.begin(), it);
  }
  else
  {
    for (int i = 0; i < vertexLabels.size(); ++i)
    {
      if (vertexLabels[i] == T())
      {
        vertexLabels[i] = vertex;
        return i;
      }
    }
  }
  return -1; // Should never reach here if used correctly
}

// Method to add an edge to the Adjacency List
template <typename T>
void Graph<T>::addEdgeAdjList(T src, T dest)
{
  int srcIndex = getVertexIndex(src);
  int destIndex = getVertexIndex(dest);
  adjList[srcIndex].push_back(dest);
  adjList[destIndex].push_back(src); // For undirected graph
}

// Method to print the Adjacency List
template <typename T>
void Graph<T>::printAdjList()
{
  std::cout << "Adjacency List Representation:\n";
  for (int i = 0; i < vertices; ++i)
  {
    std::cout << vertexLabels[i] << ": ";
    for (T vertex : adjList[i])
    {
      std::cout << vertex << " ";
    }
    std::cout << std::endl;
  }
}

// Method to add an edge to the Adjacency Matrix
template <typename T>
void Graph<T>::addEdgeAdjMatrix(T src, T dest)
{
  int srcIndex = getVertexIndex(src);
  int destIndex = getVertexIndex(dest);
  adjMatrix[srcIndex][destIndex] = 1;
  adjMatrix[destIndex][srcIndex] = 1; // For undirected graph
}

// Method to print the Adjacency Matrix
template <typename T>
void Graph<T>::printAdjMatrix()
{
  std::cout << "Adjacency Matrix Representation:\n";
  for (int i = 0; i < vertices; ++i)
  {
    std::cout << vertexLabels[i] << ": ";
    for (int j = 0; j < vertices; ++j)
    {
      std::cout << std::setw(3) << adjMatrix[i][j];
    }
    std::cout << std::endl;
  }
}

int main()
{
  int vertices = 5; // Number of vertices in the graph
  Graph<std::string> graph(vertices);

  // Adding edges
  graph.addEdgeAdjList("A", "B");
  graph.addEdgeAdjList("A", "E");
  graph.addEdgeAdjList("B", "C");
  graph.addEdgeAdjList("B", "D");
  graph.addEdgeAdjList("B", "E");
  graph.addEdgeAdjList("C", "D");
  graph.addEdgeAdjList("D", "E");

  graph.addEdgeAdjMatrix("A", "B");
  graph.addEdgeAdjMatrix("A", "E");
  graph.addEdgeAdjMatrix("B", "C");
  graph.addEdgeAdjMatrix("B", "D");
  graph.addEdgeAdjMatrix("B", "E");
  graph.addEdgeAdjMatrix("C", "D");
  graph.addEdgeAdjMatrix("D", "E");

  // Printing graph representations
  graph.printAdjList();
  std::cout << std::endl;
  graph.printAdjMatrix();

  return 0;
}
```



Graph Traversals
---
| Feature   | [Breadth-First Traversal (BFT)](https://en.wikipedia.org/wiki/Breadth-first_search)    | [Depth-First Traversal (DFT)](https://en.wikipedia.org/wiki/Depth-first_search)  |
|--------|--------------|------------------|
| **Definition**    | Traverses the graph level by level, exploring all neighbors of a vertex before moving to the next level. | Traverses the graph by exploring as far as possible along each branch before backtracking. |
| **Steps**         | 1. Initialize a queue and mark the start vertex as visited. <br> 2. Enqueue the start vertex. <br> 3. While the queue is not empty: <br> &nbsp;&nbsp;a. Dequeue a vertex. <br> &nbsp;&nbsp;b. Visit all its unvisited neighbors, mark them as visited, and enqueue them. | 1. Initialize a stack and mark the start vertex as visited. <br> 2. Push the start vertex onto the stack. <br> 3. While the stack is not empty: <br> &nbsp;&nbsp;a. Pop a vertex from the stack. <br> &nbsp;&nbsp;b. Visit all its unvisited neighbors, mark them as visited, and push them onto the stack. |
| **Time complexity** | 𝐎(V+E) |  𝐎(V+E) |
| **Applications**  | - Finding the shortest path in an unweighted graph. <br> - Level-order traversal of a tree. <br> - Finding connected components in an undirected graph. | - Topological sorting of a directed graph. <br> - Solving puzzles and games (e.g., maze solving). <br> - Finding strongly connected components in a directed graph.  |



Pseudo-code for recursive  DFT
---
```c++
procedure DFS(G, v) is
    label v as discovered
    for all directed edges from v to w that are in G.adjacentEdges(v) do
        if vertex w is not labeled as discovered then
            recursively call DFS(G, w)
```

🏃 Implementation
---
```c++
template <typename T>
void Graph<T>::DFT(T vertex, std::unordered_set<T> &visited)
{
  visited.insert(vertex);
  std::cout << vertex << " ";

  for (const T &neighbor : adjList[vertex])
  {
    if (visited.find(neighbor) == visited.end())
    {
      DFT(neighbor, visited);
    }
  }
}
```

Pseudo-code for stack-based DFT
---
```c++
procedure DFT_iterative(G, v) is
    let S be a stack
    S.push(v)
    while S is not empty do
        v = S.pop()
        if v is not labeled as discovered then
            label v as discovered
            for all edges from v to w in G.adjacentEdges(v) do 
                S.push(w)
```                

🏃 Implementation
---
```c++
template <typename T>
void Graph<T>::DFT(T start)
{
  std::unordered_set<T> visited;
  std::stack<T> stack;

  stack.push(start);

  while (!stack.empty())
  {
    T vertex = stack.top();
    stack.pop();

    if (visited.find(vertex) == visited.end())
    {
      std::cout << vertex << " ";
      visited.insert(vertex);
    }

    for (const T &neighbor : adjList[vertex])
    {
      if (visited.find(neighbor) == visited.end())
      {
        stack.push(neighbor);
      }
    }
  }
  std::cout << std::endl;
}
```


💡 Intuition
---
- [Graph DFT](https://csvistool.com/DFS)


Applications of DFT
---
- Detecting whether a graph is connected
  - Finding all connected components
- Detecting whether there is a path between two vertices
  - Finding a path between two vertices
- Detecting whether there is a cycle in the graph
  - Finding a cycle in the graph
  - Finding a Hamiltonian path/cycle


Pseudo-code for BFT 
---
```c++
procedure BFS(G, root) is
     let Q be a queue
     label root as explored
     Q.enqueue(root)
     while Q is not empty do
         v := Q.dequeue()
         if v is the goal then
             return v
         for all edges from v to w in G.adjacentEdges(v) do
             if w is not labeled as explored then
                 label w as explored
                 w.parent := v
                 Q.enqueue(w)
```

🏃 Implementation
---
```c++
template <typename T>
void Graph<T>::BFT(T start)
{
  std::unordered_set<T> visited;
  std::queue<T> queue;

  visited.insert(start);
  queue.push(start);

  while (!queue.empty())
  {
    T vertex = queue.front();
    queue.pop();
    std::cout << vertex << " ";

    for (const T &neighbor : adjList[vertex])
    {
      if (visited.find(neighbor) == visited.end())
      {
        visited.insert(neighbor);
        queue.push(neighbor);
      }
    }
  }
  std::cout << std::endl;
}
```


💡 Intuition
---
- [Graph BFT](https://csvistool.com/BFS)


Applications of BFT
---
- Detecting whether a graph is connected
  - Finding all connected components
  - Testing whether a graph is bipartite
- Detecting whether there is a path between two vertices
  - Finding a shortest path between two vertices
- Detecting whether there is a cycle in the graph
  - Finding a cycle in the graph


🏃 Implement BFT and DFT
---
- [Graph is represented with adjacency matrix](./demos/gtm.cpp)
  - [Stack-based DFT](./demos/sgm.cpp)
- [Graph is represented with adjacency list](./demos/gta.cpp)
  - [Stack-based DFT](./demos/sga.cpp)



🏃 Application: Solve The Connected Circles Problem
---
| unconnected | connected |
|:---:|:---:|
| ![unconnected](./images/uc.png) | ![connected](./images/cc.png) |



🏃 Application: Solve The Nine Tail Problem 
---
![nine tail problem](./images/nine.png)

- Nine coins in a 3x3 matrix 
  - some face up and some face down
- legal move
  - reverse a H together with its adjacent neighbors (no diagonally adjacent) 
- goal
  - find the minimum number of moves that lead to all T
- model the problem with a directed graph
  - each state represented by a node
    - all T is the target node $t$
    - starting state node $s$
  - $u\rightarrow v$ means there is a legal move change $u$ to $v$
  - turn the problem to 
    - find the shortest path from $s$ to $t$ in a BFS tree rooted at $t$

![nine tail problem](./images/ng.png)



# Online resources
- [visualgo](https://visualgo.net/)
- [Liang animation](https://liveexample.pearsoncmg.com/liang/animation/animation.html)