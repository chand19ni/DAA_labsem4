#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Graph
{
  int vertices;
  list<int> *adjList;

public:
  Graph(int v)
  {
    vertices = v;
    adjList = new list<int>[v];
  }
  void add_edge(int src, int dest)
  {
    adjList[src].push_back(dest);
  }
  void print()
  {
    for (int i = 0; i < vertices; i++)
    {
      cout << i << " -> ";
      for (int j : adjList[i])
      {
        cout << j << " ";
      }
      cout << endl;
    }
  }
  bool iscyclic(int v, vector<bool> &visited, vector<bool> recStack)
  {
    if (!visited[v])
    {
      recStack[v] = true;
      visited[v] = true;
      for (int i : adjList[v])
      {
        if (iscyclic(i, visited, recStack) && !visited[i])
        {
        }
        else if (recStack[i])
        {
          return true;
        }
      }
    }
    recStack[v] = false;
    return false;
  }
  bool cycle()
  {
    vector<bool> visited(vertices, false);
    vector<bool> recStack(vertices, false);
    for (int i = 0; i < vertices; i++)
    {
      if (iscyclic(i, visited, recStack))
      {
        return true;
      }
    }
    return false;
  }
};
int main()
{
  Graph g(5);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(3, 1);
  g.add_edge(1, 4);
  g.add_edge(3, 2);
  g.add_edge(4, 3);
  g.print();
  if (g.cycle())
  {
    cout << "Yes cyclic Graph!" << endl;
  }
  else
  {
    cout << "NO cyclic Graph!" << endl;
  }
  return 0;
}