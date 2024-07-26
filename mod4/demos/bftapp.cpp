#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Graph
{
private:
  unordered_map<int, vector<int>> adjacencyList;

  vector<int> bft(int start)
  {
    vector<int> result;
    unordered_set<int> visited;
    queue<int> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      result.push_back(v);

      for (int neighbor : adjacencyList[v])
      {
        if (visited.find(neighbor) == visited.end())
        {
          visited.insert(neighbor);
          q.push(neighbor);
        }
      }
    }

    return result;
  }

public:
  void addEdge(int v, int w)
  {
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v);
  }

  bool isConnected()
  {
    if (adjacencyList.empty())
      return true;

    vector<int> traversal = bft(adjacencyList.begin()->first);
    return traversal.size() == adjacencyList.size();
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
        vector<int> component = bft(v);
        for (int vertex : component)
        {
          visited.insert(vertex);
        }
        components.push_back(component);
      }
    }

    return components;
  }

  bool isBipartite()
  {
    if (adjacencyList.empty())
      return true;

    unordered_map<int, int> color;
    queue<int> q;

    for (const auto &entry : adjacencyList)
    {
      int start = entry.first;
      if (color.find(start) == color.end())
      {
        color[start] = 0;
        q.push(start);

        while (!q.empty())
        {
          int v = q.front();
          q.pop();

          for (int neighbor : adjacencyList[v])
          {
            if (color.find(neighbor) == color.end())
            {
              color[neighbor] = 1 - color[v];
              q.push(neighbor);
            }
            else if (color[neighbor] == color[v])
            {
              return false;
            }
          }
        }
      }
    }

    return true;
  }

  bool hasPath(int start, int end)
  {
    vector<int> traversal = bft(start);
    return find(traversal.begin(), traversal.end(), end) != traversal.end();
  }

  vector<int> shortestPath(int start, int end)
  {
    unordered_map<int, int> parent;
    queue<int> q;
    unordered_set<int> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
      int v = q.front();
      q.pop();

      if (v == end)
        break;

      for (int neighbor : adjacencyList[v])
      {
        if (visited.find(neighbor) == visited.end())
        {
          visited.insert(neighbor);
          parent[neighbor] = v;
          q.push(neighbor);
        }
      }
    }

    if (visited.find(end) == visited.end())
    {
      return vector<int>();
    }

    vector<int> path;
    for (int v = end; v != start; v = parent[v])
    {
      path.push_back(v);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return path;
  }

  bool hasCycle()
  {
    unordered_set<int> visited;
    unordered_map<int, int> parent;

    for (const auto &entry : adjacencyList)
    {
      int start = entry.first;
      if (visited.find(start) == visited.end())
      {
        queue<int> q;
        q.push(start);
        visited.insert(start);

        while (!q.empty())
        {
          int v = q.front();
          q.pop();

          for (int neighbor : adjacencyList[v])
          {
            if (visited.find(neighbor) == visited.end())
            {
              visited.insert(neighbor);
              parent[neighbor] = v;
              q.push(neighbor);
            }
            else if (parent[v] != neighbor)
            {
              return true;
            }
          }
        }
      }
    }

    return false;
  }

  vector<int> findCycle()
  {
    unordered_set<int> visited;
    unordered_map<int, int> parent;

    for (const auto &entry : adjacencyList)
    {
      int start = entry.first;
      if (visited.find(start) == visited.end())
      {
        queue<int> q;
        q.push(start);
        visited.insert(start);

        while (!q.empty())
        {
          int v = q.front();
          q.pop();

          for (int neighbor : adjacencyList[v])
          {
            if (visited.find(neighbor) == visited.end())
            {
              visited.insert(neighbor);
              parent[neighbor] = v;
              q.push(neighbor);
            }
            else if (parent[v] != neighbor)
            {
              // Cycle found
              vector<int> cycle;
              int current = v;
              while (current != neighbor)
              {
                cycle.push_back(current);
                if (parent.count(current))
                  current = parent[current];
                else
                  break;
              }

              reverse(cycle.begin(), cycle.end());
              while (find(cycle.begin(), cycle.end(), neighbor) == cycle.end())
              {
                cycle.push_back(neighbor);
                if (parent.count(neighbor))
                  neighbor = parent[neighbor];
                else
                  break;
              }
              return cycle;
            }
          }
        }
      }
    }

    return vector<int>();
  }
};

int main()
{
  Graph g;
  g.addEdge(5, 6);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  // g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 1);

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

  cout << "Is the graph bipartite? " << (g.isBipartite() ? "Yes" : "No") << endl;

  cout << "Is there a path between 0 and 5? " << (g.hasPath(0, 5) ? "Yes" : "No") << endl;

  cout << "Shortest path from 0 to 4: ";
  auto path = g.shortestPath(0, 4);
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

  return 0;
}