#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
  int vertices;
  vector<vector<int>> adj;
  Graph(int v) : vertices(v), adj(v, vector<int>())
  {
  }
  void addEdge(int src, int dest)
  {
    adj[src].push_back(dest);
  }
  bool DFScheck(int node, vector<bool> &visited, vector<bool> &pathVisited)
  {
    visited[node] = true;
    pathVisited[node] = true;
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        if (DFScheck(it, visited, pathVisited))
          return true;
      }
      else if (pathVisited[it])
      {
        return true;
      }
    }
    pathVisited[node] = false;
    return false;
  }

  bool iscyclic()
  {
    vector<bool> visited(vertices, false);
    vector<bool> pathVisited(vertices, false);
    for (int i = 0; i < vertices; i++)
    {
      if (!visited[i])
        if (DFScheck(i, visited, pathVisited) == true)
          return true;
    }
    return false;
  }
};
int main()
{
  Graph g(10);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(2, 6);
  g.addEdge(6, 4);
  g.addEdge(7, 1);
  g.addEdge(7, 8);
  g.addEdge(8, 9);
  g.addEdge(9, 7);
  if (g.iscyclic())
  {
    cout << "Yes Cycle Exists.";
  }
  else
  {
    cout << "No Cycle Exists.";
  }

  return 0;
}