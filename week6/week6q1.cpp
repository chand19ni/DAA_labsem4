#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Graph
{
public:
  int vertices;
  list<int> *adjList;
  Graph(int v)
  {
    vertices = v;
    adjList = new list<int>[v];
  }
  void add_edge(int src, int dest)
  {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
  }
  bool find_path(int src, int dest, vector<bool> &visited)
  {
    if (src == dest)
    {
      return true;
    }
    visited[src] = true;
    for (int neighbor : adjList[src])
    {
      if (!visited[neighbor])
      {
        if (find_path(neighbor, dest, visited))
        {
          return true;
        }
      }
    }
    return false;
  }
  bool path(int src, int dest)
  {
    vector<bool> visited(vertices, false);
    return find_path(src, dest, visited);
  }
  /*void print()
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
  }*/
};
int main()
{
  int src, dest;
  Graph g(5);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(1, 4);
  g.add_edge(2, 3);
  g.add_edge(3, 4);
  // g.print();
  cout << "Enter Source vertex: ";
  cin >> src;
  cout << "Enter Destination vertex: ";
  cin >> dest;
  if (g.path(src, dest))
  {
    cout << "Yes Path Exists!" << endl;
  }
  else
  {
    cout << "No such Path Exists!" << endl;
  }
  return 0;
}