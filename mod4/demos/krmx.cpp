#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <utility>

template <typename T>
class Graph
{
public:
  Graph(int vertices);
  void addEdge(const T &src, const T &dest, double weight);
  std::vector<std::pair<T, T>> kruskalMST();

private:
  int find(int i, std::vector<int> &parent);
  void unionSets(int u, int v, std::vector<int> &parent, std::vector<int> &rank);
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
int Graph<T>::find(int i, std::vector<int> &parent)
{
  if (parent[i] != i)
  {
    parent[i] = find(parent[i], parent);
  }
  return parent[i];
}

template <typename T>
void Graph<T>::unionSets(int u, int v, std::vector<int> &parent, std::vector<int> &rank)
{
  int rootU = find(u, parent);
  int rootV = find(v, parent);

  if (rank[rootU] < rank[rootV])
  {
    parent[rootU] = rootV;
  }
  else if (rank[rootU] > rank[rootV])
  {
    parent[rootV] = rootU;
  }
  else
  {
    parent[rootV] = rootU;
    rank[rootU]++;
  }
}

template <typename T>
std::vector<std::pair<T, T>> Graph<T>::kruskalMST()
{
  std::vector<std::tuple<double, int, int>> edges;
  for (int u = 0; u < vertices; ++u)
  {
    for (int v = u + 1; v < vertices; ++v)
    {
      if (adjMatrix[u][v] != std::numeric_limits<double>::infinity())
      {
        edges.emplace_back(adjMatrix[u][v], u, v);
      }
    }
  }

  std::sort(edges.begin(), edges.end());

  std::vector<int> parent(vertices);
  std::vector<int> rank(vertices, 0);
  for (int i = 0; i < vertices; ++i)
  {
    parent[i] = i;
  }

  std::vector<std::pair<T, T>> mst;
  for (const auto &edge : edges)
  {
    double weight;
    int u, v;
    std::tie(weight, u, v) = edge;

    int setU = find(u, parent);
    int setV = find(v, parent);

    if (setU != setV)
    {
      mst.emplace_back(indexVertexMap[u], indexVertexMap[v]);
      unionSets(setU, setV, parent, rank);
    }
  }

  return mst;
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

  auto mst = graph.kruskalMST();

  std::cout << "Edges in the Minimum Spanning Tree (MST):" << std::endl;
  for (const auto &edge : mst)
  {
    std::cout << "Edge: " << edge.first << " - " << edge.second << std::endl;
  }

  return 0;
}
