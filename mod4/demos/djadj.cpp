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
  std::unordered_map<T, double> dijkstra(const T &start);

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
std::unordered_map<T, double> Graph<T>::dijkstra(const T &start)
{
  std::unordered_map<T, double> distances;
  for (const auto &pair : adjList)
  {
    distances[pair.first] = std::numeric_limits<double>::infinity();
  }
  distances[start] = 0;

  using P = std::pair<double, T>;
  std::priority_queue<P, std::vector<P>, std::greater<>> pq;
  pq.emplace(0, start);

  while (!pq.empty())
  {
    double currentDist = pq.top().first;
    T currentVertex = pq.top().second;
    pq.pop();

    if (currentDist > distances[currentVertex])
    {
      continue;
    }

    for (const auto &neighbor : adjList[currentVertex])
    {
      T neighborVertex = neighbor.first;
      double weight = neighbor.second;
      double distanceThroughCurrent = currentDist + weight;

      if (distanceThroughCurrent < distances[neighborVertex])
      {
        distances[neighborVertex] = distanceThroughCurrent;
        pq.emplace(distanceThroughCurrent, neighborVertex);
      }
    }
  }

  return distances;
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

  auto distances = graph.dijkstra("A");

  std::cout << "Shortest distances from vertex A:" << std::endl;
  for (const auto &pair : distances)
  {
    std::cout << "Vertex " << pair.first << " is at distance " << pair.second << std::endl;
  }

  return 0;
}
