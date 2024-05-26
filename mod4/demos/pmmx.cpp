#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <utility>

template <typename T>
class Graph
{
public:
  Graph(int vertices);
  void addEdge(const T &src, const T &dest, double weight);
  std::vector<std::pair<T, T>> primMST(const T &start);

private:
  int getIndex(const T &vertex);
  int vertices;
  std::vector<std::vector<double>> adjMatrix;
  std::unordered_map<T, int> vertexIndexMap;
  std::vector<T> indexVertexMap;
};

template <typename T>
Graph<T>::Graph(int vertices) : vertices(vertices)
{
  adjMatrix.resize(vertices, std::vector<double>(vertices, std::numeric_limits<double>::infinity()));
  for (int i = 0; i < vertices; ++i)
  {
    adjMatrix[i][i] = 0;
  }
}

template <typename T>
void Graph<T>::addEdge(const T &src, const T &dest, double weight)
{
  int srcIndex = getIndex(src);
  int destIndex = getIndex(dest);
  adjMatrix[srcIndex][destIndex] = weight;
  adjMatrix[destIndex][srcIndex] = weight; // If the graph is undirected
}

template <typename T>
int Graph<T>::getIndex(const T &vertex)
{
  if (vertexIndexMap.find(vertex) == vertexIndexMap.end())
  {
    int index = vertexIndexMap.size();
    vertexIndexMap[vertex] = index;
    indexVertexMap.push_back(vertex);
  }
  return vertexIndexMap[vertex];
}

template <typename T>
std::vector<std::pair<T, T>> Graph<T>::primMST(const T &start)
{
  std::vector<double> key(vertices, std::numeric_limits<double>::infinity());
  std::vector<int> parent(vertices, -1);
  std::vector<bool> inMST(vertices, false);
  std::vector<std::pair<T, T>> result;

  int startIndex = getIndex(start);
  key[startIndex] = 0;

  for (int count = 0; count < vertices - 1; ++count)
  {
    double minKey = std::numeric_limits<double>::infinity();
    int u = -1;

    for (int v = 0; v < vertices; ++v)
    {
      if (!inMST[v] && key[v] < minKey)
      {
        minKey = key[v];
        u = v;
      }
    }

    if (u == -1)
      break;

    inMST[u] = true;

    for (int v = 0; v < vertices; ++v)
    {
      if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v])
      {
        parent[v] = u;
        key[v] = adjMatrix[u][v];
      }
    }
  }

  for (int i = 0; i < vertices; ++i)
  {
    if (parent[i] != -1)
    {
      result.emplace_back(indexVertexMap[parent[i]], indexVertexMap[i]);
    }
  }

  return result;
}

int main()
{
  Graph<std::string> graph(6);

  graph.addEdge("A", "B", 4);
  graph.addEdge("A", "C", 2);
  graph.addEdge("B", "C", 5);
  graph.addEdge("B", "D", 10);
  graph.addEdge("C", "E", 3);
  graph.addEdge("E", "D", 4);
  graph.addEdge("D", "F", 11);

  auto mst = graph.primMST("A");

  std::cout << "Edges in the Minimum Spanning Tree (MST):" << std::endl;
  for (const auto &edge : mst)
  {
    std::cout << "Edge: " << edge.first << " - " << edge.second << std::endl;
  }

  return 0;
}
