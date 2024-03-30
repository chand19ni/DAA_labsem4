#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool duplicate(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == arr[i + 1])
    {
      return true;
    }
  }
  return false;
}
int main()
{
  int test, n, e;
  cout << "Enter test cases: ";
  cin >> test;
  while (test > 0)
  {
    cout << "Enter ARRAY size: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter ARRAY: ";
    for (int i = 0; i < n; i++)
    {
      cin >> e;
      arr.push_back(e);
    }
    sort(arr.begin(), arr.end());
    if (duplicate(arr))
    {
      cout << "Duplicate FOUND!\n";
    }
    else
    {
      cout << "Duplicates NOT FOUND!\n";
    }
    test--;
  }
  return 0;
}