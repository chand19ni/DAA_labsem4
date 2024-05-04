#include <bits/stdc++.h>
using namespace std;

int prims(vector<vector<int>> adj[], int vertices)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> vis(vertices, 0);
  int sum = 0;
  pq.push({0, 0});
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    int weight = it.first;
    int node = it.second;

    if (vis[node] == 1)
    {
      continue;
    }
    vis[node] = 1;
    sum += weight;
    for (auto it : adj[node])
    {
      int adjnode = it[0];
      int adjweight = it[1];
      if (!vis[adjnode])
      {
        pq.push({adjweight, adjnode});
      }
    }
  }
  return sum;
}

void addedge(vector<vector<int>> adj[], int src, int dest, int weight)
{
  adj[src].push_back({dest, weight});
  adj[dest].push_back({src, weight});
}

int main()
{
  int mst, v = 5;
  vector<vector<int>> adj[v];
  addedge(adj, 0, 1, 2);
  addedge(adj, 0, 2, 1);
  addedge(adj, 2, 1, 1);
  addedge(adj, 2, 3, 2);
  addedge(adj, 2, 3, 2);
  addedge(adj, 3, 4, 1);
  mst = prims(adj, v);
  cout << "MST weight: " << mst;
}