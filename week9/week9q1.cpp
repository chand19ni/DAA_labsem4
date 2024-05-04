#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF INT_MAX
#define v 4

void print(int dist[][v])
{
  cout << "Shortest Distance matrix-\n";
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      if (dist[i][j] == INF)
      {
        cout << "INF ";
      }
      else
      {
        cout << dist[i][j] << " ";
      }
    }
    cout << endl;
  }
}
void floyd_warshall(int dist[][v])
{
  for (int k = 0; k < v; k++)
  {
    for (int i = 0; i < v; i++)
    {
      for (int j = 0; j < v; j++)
      {
        if ((dist[i][k] + dist[k][j] < dist[i][j]) && (dist[i][k] != INF && dist[k][j] != INF))
        {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  print(dist);
}

int main()
{
  int dist[v][v] = {{0, 5, INF, 10},
                    {INF, 0, 3, INF},
                    {INF, INF, 0, 1},
                    {INF, INF, INF, 0}};

  floyd_warshall(dist);
  return 0;
}