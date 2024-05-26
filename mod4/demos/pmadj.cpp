#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <utility>

template <typename T>
class Graph
{
public:
  void addEdge(const T &src, const T &dest, double weight);
  std::vector<std::pair<T, T>> primMST(const T &start);

private:
  std::unordered_map<T, std::vector<std::pair<T, double>>> adjList;
};

template <typename T>
void Graph<T>::addEdge(const T &src, const T &dest, double weight)
{
  adjList[src].emplace_back(dest, weight);
  adjList[dest].emplace_back(src, weight); // If the graph is undirected
}

template <typename T>
std::vector<std::pair<T, T>> Graph<T>::primMST(const T &start)
{
  std::unordered_map<T, double> key;
  std::unordered_map<T, T> parent;
  std::unordered_map<T, bool> inMST;
  std::vector<std::pair<T, T>> result;

  for (const auto &pair : adjList)
  {
    key[pair.first] = std::numeric_limits<double>::infinity();
    inMST[pair.first] = false;
  }

  using P = std::pair<double, T>;
  std::priority_queue<P, std::vector<P>, std::greater<>> pq;

  key[start] = 0;
  pq.emplace(0, start);

  while (!pq.empty())
  {
    T u = pq.top().second;
    pq.pop();

    inMST[u] = true;

    for (const auto &neighbor : adjList[u])
    {
      T v = neighbor.first;
      double weight = neighbor.second;

      if (!inMST[v] && key[v] > weight)
      {
        key[v] = weight;
        pq.emplace(key[v], v);
        parent[v] = u;
      }
    }
  }

  for (const auto &pair : adjList)
  {
    T v = pair.first;
    if (v != start && parent.find(v) != parent.end())
    {
      result.emplace_back(parent[v], v);
    }
  }

  return result;
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

  auto mst = graph.primMST("A");

  std::cout << "Edges in the Minimum Spanning Tree (MST):" << std::endl;
  for (const auto &edge : mst)
  {
    std::cout << "Edge: " << edge.first << " - " << edge.second << std::endl;
  }

  return 0;
}
