#include <iostream>
using namespace std;
bool find(int arr[], int n, int key, int &i, int &j)
{
  for (int k = 0; k < n - 1; k++)
  {
    for (int l = k + 1; l < n; l++)
    {
      if (arr[k] + arr[l] == key)
      {
        i = k;
        j = l;
        return true;
      }
    }
  }
  return false;
}
int main()
{
  int test, n, arr[100], key, i, j;
  cout << "Enter test cases: ";
  cin >> test;
  while (test > 0)
  {
    cout << "Enter Array size: ";
    cin >> n;
    cout << "Enter ARRAY: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << "Enter key: ";
    cin >> key;
    if (!find(arr, n, key, i, j))
    {
      cout << "No Such Elements Exist!" << endl;
    }
    else
    {
      cout << arr[i] << " " << arr[j] << endl;
    }
    test--;
  }
  return 0;
}