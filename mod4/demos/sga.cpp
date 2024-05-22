#include <iostream>
#include <list>
#include <stack>
#include <vector>

template <typename T>
class Graph
{
  std::vector<std::list<T>> adjLists;
  std::vector<bool> visited;

public:
  Graph(T vertices)
      : adjLists(vertices), visited(vertices, false) {}

  void addEdge(T src, T dest)
  {
    adjLists[src].push_back(dest);
  }

  void DFT(T startVertex)
  {
    std::stack<T> stack;

    stack.push(startVertex);

    while (!stack.empty())
    {
      T currentVertex = stack.top();
      stack.pop();

      if (!visited[currentVertex])
      {
        visited[currentVertex] = true;
        std::cout << currentVertex << " ";

        for (auto it = adjLists[currentVertex].rbegin(); it != adjLists[currentVertex].rend(); ++it)
        {
          if (!visited[*it])
          {
            stack.push(*it);
          }
        }
      }
    }
  }
};

int main()
{
  Graph<int> g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  std::cout << "Depth First Traversal starting from vertex 0:\n";
  g.DFT(0);

  return 0;
}
