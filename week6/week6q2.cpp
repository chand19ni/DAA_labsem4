#include <iostream>
#include <list>
#include <queue>
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
  bool bipartite(int src, vector<int> &color)
  {
    queue<int> q;
    q.push(src);
    color[src] = 0;

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      for (auto it : adj_list[node])
      {
        if (color[it] == -1)
        {
          color[it] = !color[node];
          q.push(it);
        }
        else if (color[it] == color[node])
        {
          return false;
        }
      }
    }
    return true;
  }
  bool check()
  {
    vector<int> color(vertices, -1);
    for (int i = 0; i < vertices; i++)
    {
      if (color[i] == -1)
      {
        if (bipartite(i, color) == false)
          return false;
      }
    }
    return true;
  }
};

int main()
{
  int src, dest;
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(2, 3);
  g.addEdge(4, 3);
  g.addEdge(4, 2);
  g.addEdge(1, 3);

  if (g.check())
  {
    cout << "Yes Bipartite.";
  }
  else
  {
    cout << "Not Bipartite.";
  }
  return 0;
}