#include <bits/stdc++.h>
using namespace std;
class Solution
{
  vector<int> size, parent;

public:
  Solution(int v)
  {
    size.resize(v + 1, 1);
    parent.resize(v + 1);
    for (int i = 0; i < v + 1; i++)
    {
      parent[i] = i;
    }
  }

  int findUparent(int node)
  {
    if (node == parent[node])
    {
      return node;
    }
    return parent[node] = findUparent(parent[node]);
  }
  void unionbySize(int u, int v)
  {
    int ult_u = findUparent(u);
    int ult_v = findUparent(v);
    if (ult_v == ult_u)
    {
      return;
    }
    if (size[ult_v] < size[ult_u])
    {
      parent[ult_v] = ult_u;
      size[ult_u] += size[ult_v];
    }
    else
    {
      parent[ult_u] = ult_v;
      size[ult_v] += size[ult_u];
    }
  }

  int spanningTree(int v, vector<vector<int>> adj[])
  {
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < v; i++)
    {
      for (auto it : adj[i])
      {
        int adjnode = it[0];
        int weight = it[1];
        int node = i;
        edges.push_back({weight, {node, adjnode}});
      }
    }
    sort(edges.begin(), edges.end());
    int mst = 0;
    for (auto it : edges)
    {
      int w = it.first;
      int u = it.second.first;
      int v = it.second.second;

      if (findUparent(u) != findUparent(v))
      {
        mst += w;
        unionbySize(u, v);
      }
    }
    return mst;
  }
};

int main()
{
  int v, e;
  cin >> v >> e;
  vector<vector<int>> adj[v];
  int i = 0;
  while (i++ < e)
  {
    int src, dest, w;
    cin >> src >> dest >> w;
    vector<int> t1, t2;
    t1.push_back(dest);
    t1.push_back(w);
    adj[src].push_back(t1);
    t2.push_back(src);
    t2.push_back(w);
    adj[dest].push_back(t2);
  }
  Solution obj(v);
  cout << "MST weight: " << obj.spanningTree(v, adj) << "\n";
  return 0;
}