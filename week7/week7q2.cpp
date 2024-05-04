#include <bits/stdc++.h>
#define INF INT_MAX
#define vertices 6
using namespace std;

void addEdge(list<vector<int>> adj[vertices], int src, int dest, int weight)
{
  adj[src].push_back({dest, weight});
}

void BellmannFord(list<vector<int>> adj[vertices], int src)
{
  vector<int> distance(vertices, INF);
  distance[src] = 0;
  for (int i = 0; i < vertices - 1; i++)
  {
    for (int u = 0; u < vertices; u++)
    {
      for (auto it : adj[u])
      {
        int v = it[0];
        int wt = it[1];
        if (distance[u] != INT_MAX && distance[u] + wt < distance[v])
        {
          distance[v] = distance[u] + wt;
        }
      }
    }
  }
  cout << "Distance from Source node (" << src << ") -" << endl;
  for (int i = 0; i < vertices; i++)
  {
    cout << i << " - " << distance[i] << endl;
  }
}

int main()
{
  list<vector<int>> adj[vertices];
  addEdge(adj, 3, 2, 6);
  addEdge(adj, 0, 1, 5);
  addEdge(adj, 5, 3, 1);
  addEdge(adj, 1, 5, -3);
  addEdge(adj, 1, 2, -2);
  addEdge(adj, 3, 4, -2);
  addEdge(adj, 2, 4, 3);
  BellmannFord(adj, 0);

  return 0;
}