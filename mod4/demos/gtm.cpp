#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

template <typename T>
class Graph
{
public:
  Graph(int vertices);

  void addEdge(T src, T dest);

  void BFT(T start, std::vector<int> &vn, std::vector<int> &vp);
  void DFT(T start, std::vector<int> &vn, std::vector<int> &vp);

  void print();

  int vertices;
  std::vector<std::vector<int>> adjMatrix;
  std::unordered_map<T, int> vertexIndexMap;
  std::vector<T> indexVertexMap;
  int currentIndex;

  int getVertexIndex(T vertex);
};

template <typename T>
Graph<T>::Graph(int vertices) : vertices(vertices), currentIndex(0)
{
  adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
  indexVertexMap.resize(vertices);
}

template <typename T>
int Graph<T>::getVertexIndex(T vertex)
{
  if (vertexIndexMap.find(vertex) == vertexIndexMap.end())
  {
    vertexIndexMap[vertex] = currentIndex;
    indexVertexMap[currentIndex] = vertex;
    currentIndex++;
  }
  return vertexIndexMap[vertex];
}

template <typename T>
void Graph<T>::addEdge(T src, T dest)
{
  int srcIndex = getVertexIndex(src);
  int destIndex = getVertexIndex(dest);
  adjMatrix[srcIndex][destIndex] = 1;
  adjMatrix[destIndex][srcIndex] = 1; // For undirected graph
}

template <typename T>
void Graph<T>::BFT(T start, std::vector<int> &vn, std::vector<int> &vp)
{
  std::vector<bool> visited(vertices, false);
  vn = std::vector<int>(vertices, 0);
  std::queue<int> queue;

  int startIndex = getVertexIndex(start);
  visited[startIndex] = true;
  vp.push_back(startIndex);
  queue.push(startIndex);
  vn[startIndex]++;

  while (!queue.empty())
  {
    int vertexIndex = queue.front();
    queue.pop();
    std::cout << indexVertexMap[vertexIndex] << " ";

    for (int i = 0; i < vertices; ++i)
    {
      if (adjMatrix[vertexIndex][i] == 1)
      {
        vn[i]++;
        vp.push_back(i);
      }

      if (adjMatrix[vertexIndex][i] == 1 && !visited[i])
      {
        visited[i] = true;
        queue.push(i);
      }
    }
  }
  std::cout << std::endl;
}

template <typename T>
void Graph<T>::DFT(T start, std::vector<int> &vn, std::vector<int> &vp)
{
  std::vector<bool> visited(vertices, false);
  vn = std::vector<int>(vertices, 0);
  std::stack<int> stack;

  int startIndex = getVertexIndex(start);
  stack.push(startIndex);

  while (!stack.empty())
  {
    int vertexIndex = stack.top();
    stack.pop();

    if (!visited[vertexIndex])
    {
      std::cout << indexVertexMap[vertexIndex] << " ";
      visited[vertexIndex] = true;
      vp.push_back(vertexIndex);
      vn[vertexIndex]++;
    }

    for (int i = 0; i < vertices; ++i)
    {
      if (adjMatrix[vertexIndex][i] == 1)
      {
        vp.push_back(i);
        vn[i]++;
      }
      if (adjMatrix[vertexIndex][i] == 1 && !visited[i])
      {
        stack.push(i);
      }
    }
  }
  std::cout << std::endl;
}

template <typename T>
void Graph<T>::print()
{
  for (size_t i = 0; i < vertices; i++)
  {
    for (size_t j = 0; j < vertices; j++)
    {
      std::cout << adjMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main()
{
  int nvertices = 6;
  Graph<std::string> graph(nvertices);

  graph.addEdge("A", "B");
  graph.addEdge("A", "C");
  graph.addEdge("B", "D");
  graph.addEdge("B", "E");
  graph.addEdge("C", "F");
  // graph.addEdge("E", "F");
  graph.print();

  std::cout << "Breadth-First Traversal (BFT) starting from vertex A:\n";
  std::vector<int> vn, vp, vn2, vp2;
  graph.BFT("A", vn, vp);
  for (size_t i = 0; i < nvertices; i++)
  {
    std::cout << graph.indexVertexMap[i] << "(" << vn[i] << ") ";
  }
  std::cout << std::endl;

  for (auto p : vp)
  {
    std::cout << graph.indexVertexMap[p] << " ";
  }
  std::cout << std::endl;

  std::cout << "Depth-First Traversal (DFT) starting from vertex A:\n";
  graph.DFT("A", vn2, vp2);
  for (size_t i = 0; i < nvertices; i++)
  {
    std::cout << graph.indexVertexMap[i] << "(" << vn2[i] << ") ";
  }
  std::cout << std::endl;

  for (auto p : vp2)
  {
    std::cout << graph.indexVertexMap[p] << " ";
  }
  std::cout << std::endl;

  return 0;
}