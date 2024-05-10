#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, count = 1;
  cin >> n;
  vector<pair<int, int>> table(n);
  for (int i = 0; i < n; i++)
  {
    int finish, start;
    cin >> start >> finish;
    table[i] = {finish, start};
  }
  sort(table.begin(), table.end());
  int i = 0, j = 1;
  cout << "Activity selected-\n";
  cout << i + 1 << " : " << table[i].second << " - " << table[i].first << endl;
  while (j < n)
  {
    if (table[i].first <= table[j].second)
    {
      cout << j + 1 << " : " << table[j].second << " - " << table[j].first << endl;
      i = j;
      count++;
    }
    j++;
  }
  cout << "No. of non conflicting activities: " << count;
  return 0;
}