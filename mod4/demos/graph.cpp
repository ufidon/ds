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
