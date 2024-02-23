// Given an array of nonnegative integers, design a linear algorithm and implement it using a
// program to find whether given key element is present in the array or not. Also, find total number
// of comparisons for each input case. (Time Complexity = O(n), where n is the size of input).
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