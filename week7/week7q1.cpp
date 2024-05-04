#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

void addEdge(vector<vector<int>> adj[], int src, int dest, int weight)
{
  adj[src].push_back({dest, weight});
  adj[dest].push_back({src, weight});
}

void Dijkstras(vector<vector<int>> adj[], int src, int v)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> distance(v, INF);
  distance[src] = 0;
  pq.push({0, src});
  while (!pq.empty())
  {
    int dist = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto it : adj[node])
    {
      int adjNode = it[0];
      int weight = it[1];
      if (dist + weight < distance[adjNode])
      {
        distance[adjNode] = dist + weight;
        pq.push({distance[adjNode], adjNode});
      }
    }
  }
  cout << "Distance from Source node (" << src << ") -" << endl;
  for (int i = 0; i < v; i++)
  {
    cout << i << " - " << distance[i] << endl;
  }
}

int main()
{
  int v = 6;
  vector<vector<int>> adj[v];
  addEdge(adj, 0, 1, 4);
  addEdge(adj, 0, 2, 4);
  addEdge(adj, 1, 2, 2);
  addEdge(adj, 2, 3, 3);
  addEdge(adj, 2, 5, 6);
  addEdge(adj, 2, 4, 1);
  addEdge(adj, 3, 5, 2);
  addEdge(adj, 4, 5, 3);

  Dijkstras(adj, 0, v);

  return 0;
}