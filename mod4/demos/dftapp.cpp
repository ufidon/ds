#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;

class Graph
{
private:
  unordered_map<int, vector<int>> adjacencyList;
  int numVertices;

  void dfsUtil(int v, unordered_set<int> &visited, vector<int> &path)
  {
    visited.insert(v);
    path.push_back(v);

    for (int neighbor : adjacencyList[v])
    {
      if (visited.find(neighbor) == visited.end())
      {
        dfsUtil(neighbor, visited, path);
      }
    }
  }

  bool dfsUtilCycle(int v, unordered_set<int> &visited, int parent, vector<int> &cycle)
  {
    visited.insert(v);
    cycle.push_back(v);

    for (int neighbor : adjacencyList[v])
    {
      if (visited.find(neighbor) == visited.end())
      {
        if (dfsUtilCycle(neighbor, visited, v, cycle))
        {
          return true;
        }
      }
      else if (neighbor != parent)
      {
        cycle.push_back(neighbor);
        return true;
      }
    }

    cycle.pop_back();
    return false;
  }

  bool dfsUtilHamiltonian(vector<int> &path, unordered_set<int> &visited)
  {
    if (path.size() == numVertices)
    {
      // Check if it's a cycle (last vertex connected to first)
      if (find(adjacencyList[path.back()].begin(), adjacencyList[path.back()].end(), path.front()) != adjacencyList[path.back()].end())
      {
        path.push_back(path.front()); // Complete the cycle
        return true;
      }
      return path.size() == numVertices; // It's a path but not a cycle
    }

    for (int neighbor : adjacencyList[path.back()])
    {
      if (visited.find(neighbor) == visited.end())
      {
        visited.insert(neighbor);
        path.push_back(neighbor);

        if (dfsUtilHamiltonian(path, visited))
        {
          return true;
        }

        visited.erase(neighbor);
        path.pop_back();
      }
    }

    return false;
  }

public:
  Graph(int vertices) : numVertices(vertices) {}

  void addEdge(int v, int w)
  {
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v);
  }

  bool isConnected()
  {
    if (adjacencyList.empty())
      return true;

    unordered_set<int> visited;
    vector<int> v;
    dfsUtil(adjacencyList.begin()->first, visited, v);

    return visited.size() == adjacencyList.size();
  }

  vector<vector<int>> findConnectedComponents()
  {
    vector<vector<int>> components;
    unordered_set<int> visited;

    for (const auto &entry : adjacencyList)
    {
      int v = entry.first;
      if (visited.find(v) == visited.end())
      {
        vector<int> component;
        dfsUtil(v, visited, component);
        components.push_back(component);
      }
    }

    return components;
  }

  bool hasPath(int start, int end)
  {
    unordered_set<int> visited;
    vector<int> path;
    dfsUtil(start, visited, path);
    return visited.find(end) != visited.end();
  }

  vector<int> findPath(int start, int end)
  {
    unordered_set<int> visited;
    vector<int> path;
    dfsUtil(start, visited, path);

    auto it = find(path.begin(), path.end(), end);
    if (it != path.end())
    {
      return vector<int>(path.begin(), it + 1);
    }
    return vector<int>();
  }

  bool hasCycle()
  {
    unordered_set<int> visited;
    vector<int> cycle;

    for (const auto &entry : adjacencyList)
    {
      int v = entry.first;
      if (visited.find(v) == visited.end())
      {
        if (dfsUtilCycle(v, visited, -1, cycle))
        {
          return true;
        }
      }
    }

    return false;
  }

  vector<int> findCycle()
  {
    unordered_set<int> visited;
    vector<int> cycle;

    for (const auto &entry : adjacencyList)
    {
      int v = entry.first;
      if (visited.find(v) == visited.end())
      {
        if (dfsUtilCycle(v, visited, -1, cycle))
        {
          auto it = find(cycle.begin(), cycle.end(), cycle.back());
          return vector<int>(it, cycle.end());
        }
      }
    }

    return vector<int>();
  }

  vector<int> findHamiltonianPath()
  {
    for (const auto &entry : adjacencyList)
    {
      int start = entry.first;
      vector<int> path = {start};
      unordered_set<int> visited = {start};

      if (dfsUtilHamiltonian(path, visited))
      {
        return path;
      }
    }

    return vector<int>();
  }
};

int main()
{
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  // g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(5, 6);
  // g.addEdge(6, 0);

  cout << "Is the graph connected? " << (g.isConnected() ? "Yes" : "No") << endl;

  cout << "Connected components:" << endl;
  auto components = g.findConnectedComponents();
  for (const auto &component : components)
  {
    for (int v : component)
    {
      cout << v << " ";
    }
    cout << endl;
  }

  cout << "Is there a path between 0 and 5? " << (g.hasPath(0, 5) ? "Yes" : "No") << endl;

  cout << "Path from 0 to 5: ";
  auto path = g.findPath(0, 5);
  for (int v : path)
  {
    cout << v << " ";
  }
  cout << endl;

  cout << "Does the graph have a cycle? " << (g.hasCycle() ? "Yes" : "No") << endl;

  cout << "A cycle in the graph: ";
  auto cycle = g.findCycle();
  for (int v : cycle)
  {
    cout << v << " ";
  }
  cout << endl;

  cout << "Hamiltonian path/cycle: ";
  auto hamiltonianPath = g.findHamiltonianPath();
  for (int v : hamiltonianPath)
  {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}