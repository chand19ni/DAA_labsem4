#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
public:
  int vertices;
  list<int> *adj_list;

  Graph(int v)
  {
    vertices = v;
    adj_list = new list<int>[v];
  }
  void addDirectedEdge(int src, int dest)
  {
    adj_list[src].push_back(dest);
  }
  void addEdge(int src, int dest)
  {
    adj_list[src].push_back(dest);
    adj_list[dest].push_back(src);
  }

  bool findPath(int src, int dest, vector<bool> &visited)
  {
    if (src == dest)
    {
      return true;
    }
    visited[src] = true;
    for (int neighbor : adj_list[src])
    {
      if (!visited[neighbor])
      {
        if (findPath(neighbor, dest, visited))
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  int src, dest;
  Graph g(5);
  g.addDirectedEdge(0, 1);
  g.addDirectedEdge(0, 2);
  g.addDirectedEdge(2, 1);
  g.addDirectedEdge(2, 3);
  g.addDirectedEdge(4, 3);
  g.addDirectedEdge(4, 2);
  g.addDirectedEdge(1, 3);

  cout << "Enter source node: ";
  cin >> src;
  cout << "Enter destination node: ";
  cin >> dest;
  vector<bool> visited(g.vertices, false);

  if (g.findPath(src, dest, visited))
  {
    cout << "Yes Path Exists.";
  }
  else
  {
    cout << "No Such Path Exists.";
  }
  return 0;
}