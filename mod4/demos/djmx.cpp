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
  std::unordered_map<T, double> dijkstra(const T &start);

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
std::unordered_map<T, double> Graph<T>::dijkstra(const T &start)
{
  std::vector<double> distances(vertices, std::numeric_limits<double>::infinity());
  std::vector<bool> visited(vertices, false);
  std::unordered_map<T, double> result;

  int startIndex = getIndex(start);
  distances[startIndex] = 0;

  for (int i = 0; i < vertices; ++i)
  {
    int u = -1;
    for (int j = 0; j < vertices; ++j)
    {
      if (!visited[j] && (u == -1 || distances[j] < distances[u]))
      {
        u = j;
      }
    }

    if (distances[u] == std::numeric_limits<double>::infinity())
    {
      break;
    }

    visited[u] = true;

    for (int v = 0; v < vertices; ++v)
    {
      if (!visited[v] && adjMatrix[u][v] != std::numeric_limits<double>::infinity())
      {
        double alt = distances[u] + adjMatrix[u][v];
        if (alt < distances[v])
        {
          distances[v] = alt;
        }
      }
    }
  }

  for (const auto &pair : vertexIndexMap)
  {
    result[pair.first] = distances[pair.second];
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

  auto distances = graph.dijkstra("A");

  std::cout << "Shortest distances from vertex A:" << std::endl;
  for (const auto &pair : distances)
  {
    std::cout << "Vertex " << pair.first << " is at distance " << pair.second << std::endl;
  }

  return 0;
}
