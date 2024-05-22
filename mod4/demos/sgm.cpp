#include <iostream>
#include <vector>
#include <stack>

// Define the maximum number of vertices in the graph
const int MAX_VERTICES = 100;

// Graph represented by an adjacency matrix
class Graph
{
private:
  int vertices;
  std::vector<std::vector<int>> adjMatrix;

public:
  Graph(int v) : vertices(v), adjMatrix(v, std::vector<int>(v, 0)) {}

  void addEdge(int u, int v)
  {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // Assuming an undirected graph
  }

  void dft(int startVertex)
  {
    std::vector<bool> visited(vertices, false);
    std::stack<int> stack;

    stack.push(startVertex);
    visited[startVertex] = true;

    while (!stack.empty())
    {
      int currentVertex = stack.top();
      stack.pop();
      std::cout << currentVertex << " "; // Process the current vertex

      // Visit adjacent vertices
      for (int neighbor = 0; neighbor < vertices; ++neighbor)
      {
        if (adjMatrix[currentVertex][neighbor] && !visited[neighbor])
        {
          stack.push(neighbor);
          visited[neighbor] = true;
        }
      }
    }
  }
};

int main()
{
  int vertices = 5; // Example: 5 vertices
  Graph g(vertices);

  // Example edges (modify as needed)
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);

  std::cout << "Depth-First Traversal (starting from vertex 0): ";
  g.dft(0);

  return 0;
}
