#include <iostream>
using namespace std;
void find(int *a, int m, int value)
{
  int i, count = 0, flag = 0;
  for (i = 0; i < m; i++)
  {
    count++;
    if (a[i] == value)
    {
      flag = 1;
      cout << "Present " << count;
      break;
    }
  }
  if (flag == 0)
  {
    cout << "Not Present " << count;
  }
}
int main()
{
  int *arr, j, n, key, test;
  cin >> test;
  while (test > 0)
  {
    cin >> n;
    arr = new int[n];
    for (j = 0; j < n; j++)
    {
      cin >> arr[j];
    }
    cin >> key;
    find(arr, n, key);
    delete[] arr;
    test--;
  }
  return 0;
}