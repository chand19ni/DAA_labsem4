#include <bits/stdc++.h>
using namespace std;
class Knapsack
{
  int capacity;
  vector<pair<double, pair<int, int>>> table;

public:
  Knapsack(int w)
  {
    capacity = w;
  }
  void addData(int wght, int pft)
  {
    double unit = (double)pft / wght;
    table.push_back({unit, {wght, pft}});
  }
  double KnapsackFinal(int n)
  {
    double max_profit = 0;
    sort(table.begin(), table.end(), greater<pair<double, pair<int, int>>>());

    for (int i = 0; i < n; i++)
    {
      if (capacity > table[i].second.first)
      {
        capacity -= table[i].second.first;
        max_profit += table[i].second.second;
      }
      else
      {
        max_profit += capacity * table[i].first;
        break;
      }
    }
    return max_profit;
  }
};
int main()
{
  int n, weight, profit, cap;
  double max_profit;
  cin >> cap;
  Knapsack knp(cap);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> weight >> profit;
    knp.addData(weight, profit);
  }
  max_profit = knp.KnapsackFinal(n);
  cout << "Maximum Profit: Rs." << setprecision(4) << max_profit;
  return 0;
}