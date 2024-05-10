#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, total_time = 0, time, deadline, max_task = 0;
  vector<int> tasks;
  cin >> n;
  vector<pair<int, pair<int, int>>> table;
  for (int i = 0; i < n; i++)
  {
    cin >> time >> deadline;
    table.push_back({deadline, {time, i + 1}});
  }
  sort(table.begin(), table.end());
  for (int i = 0; i < n; i++)
  {
    if (table[i].first - total_time >= table[i].second.first)
    {
      tasks.push_back(table[i].second.second);
      total_time += table[i].second.first;
      max_task++;
    }
  }
  cout << "Max task: " << max_task << endl;
  cout << "Activity Selected- " << endl;
  for (auto task : tasks)
  {
    cout << task << " ";
  }

  return 0;
}