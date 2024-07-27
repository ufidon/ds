#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <utility>
#include <tuple>

template <typename T>
struct PairHash {
    std::size_t operator()(const std::pair<T, T>& p) const {
        // Implement a suitable hash function here
        // For example:
        return std::hash<T>()(p.first) ^ std::hash<T>()(p.second);
    }
};

template <typename T>
class Graph
{
public:
  void addEdge(const T &src, const T &dest, double weight);
  std::vector<std::tuple<T, T, double>> kruskalMST();
  std::unordered_map<std::pair<T, T>, double, PairHash<T>> edges;

private:
  int find(int i, std::vector<int> &parent);
  void unionSets(int u, int v, std::vector<int> &parent, std::vector<int> &rank);

  std::unordered_map<T, std::vector<std::pair<T, double>>> adjList;
  std::unordered_map<T, int> vertexIndexMap;
  std::vector<T> indexVertexMap;
};

template <typename T>
void Graph<T>::addEdge(const T &src, const T &dest, double weight)
{
  adjList[src].emplace_back(dest, weight);
  adjList[dest].emplace_back(src, weight); // If the graph is undirected
  edges[{src, dest}] = weight;
  edges[{dest, src}] = weight;

  if (vertexIndexMap.find(src) == vertexIndexMap.end())
  {
    int index = vertexIndexMap.size();
    vertexIndexMap[src] = index;
    indexVertexMap.push_back(src);
  }

  if (vertexIndexMap.find(dest) == vertexIndexMap.end())
  {
    int index = vertexIndexMap.size();
    vertexIndexMap[dest] = index;
    indexVertexMap.push_back(dest);
  }
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
std::vector<std::tuple<T, T, double>> Graph<T>::kruskalMST()
{
  std::vector<std::tuple<double, int, int>> edges;
  for (const auto &pair : adjList)
  {
    int u = vertexIndexMap[pair.first];
    for (const auto &neighbor : pair.second)
    {
      int v = vertexIndexMap[neighbor.first];
      if (u < v)
      { // Ensure each edge is added only once
        edges.emplace_back(neighbor.second, u, v);
      }
    }
  }

  std::sort(edges.begin(), edges.end());

  std::vector<int> parent(vertexIndexMap.size());
  std::vector<int> rank(vertexIndexMap.size(), 0);
  for (int i = 0; i < vertexIndexMap.size(); ++i)
  {
    parent[i] = i;
  }

  std::vector<std::tuple<T, T, double>> mst;
  for (const auto &edge : edges)
  {
    double weight;
    int u, v;
    std::tie(weight, u, v) = edge;

    int setU = find(u, parent);
    int setV = find(v, parent);

    if (setU != setV)
    {
      mst.emplace_back(indexVertexMap[u], indexVertexMap[v], this->edges[{indexVertexMap[u], indexVertexMap[v]}]);
      unionSets(setU, setV, parent, rank);
    }
  }

  return mst;
}

int main()
{
  Graph<std::string> graph;

  graph.addEdge("A", "B", 4);
  graph.addEdge("A", "C", 2);
  graph.addEdge("B", "C", 5);
  graph.addEdge("B", "D", 10);
  graph.addEdge("C", "E", 3);
  graph.addEdge("E", "D", 4);
  graph.addEdge("D", "F", 11);

  auto mst = graph.kruskalMST();

  std::cout << "Edges in the Minimum Spanning Tree (MST):" << std::endl;
  double total = 0;
  for (const auto &edge : mst)
  {
    std::cout << "Edge: " << std::get<0>(edge) << " - " << std::get<1>(edge) << "(" << std::get<2>(edge) << ")" << std::endl;
    total += std::get<2>(edge);
  }
  std::cout << "MST Total weight: " << total << std::endl;

  return 0;
}