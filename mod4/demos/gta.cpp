#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

template <typename T>
class Graph
{
public:
  Graph();

  void addEdge(T src, T dest);

  void BFT(T start);
  void DFT(T start);
  void DFT(T start, std::unordered_set<T> &visited);

private:
  std::unordered_map<T, std::list<T>> adjList;
};

template <typename T>
Graph<T>::Graph()
{
  // Empty constructor
}

template <typename T>
void Graph<T>::addEdge(T src, T dest)
{
  adjList[src].push_back(dest);
  adjList[dest].push_back(src); // For undirected graph
}

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

int main()
{
  Graph<std::string> graph;
  std::unordered_set<std::string> visited;

  graph.addEdge("A", "B");
  graph.addEdge("A", "C");
  graph.addEdge("B", "D");
  graph.addEdge("B", "E");
  graph.addEdge("C", "F");
  graph.addEdge("E", "F");

  std::cout << "Breadth-First Traversal (BFT) starting from vertex A:\n";
  graph.BFT("A");

  std::cout << "Depth-First Traversal (DFT) starting from vertex A:\n";
  graph.DFT("A");

  graph.DFT("A", visited);
  std::cout << std::endl;

  return 0;
}
