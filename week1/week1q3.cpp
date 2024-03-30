#include <iostream>
using namespace std;
int search(int arr[], int start, int end, int key, int &comp)
{
  for (int i = start; i <= end; i++)
  {
    comp++;
    if (key == arr[i])
    {
      return comp;
    }
  }
  return comp;
}
int binary_search(int arr[], int n, int key)
{
  int comp = 0, i = 0;
  while (i < n && key >= arr[i])
  {
    comp++;
    if (key == arr[i])
    {
      return comp;
    }
    else if (i == 0)
    {
      i = 2;
    }
    else
    {
      i *= 2;
    }
  }
  int start = i / 2;
  int end = min(i, n - 1);
  return search(arr, start, end, key, comp);
}
int main()
{
  int n, test, c, key;
  cout << "Enter test cases: ";
  cin >> test;
  while (test > 0)
  {
    cout << "Enter ARRAY size: ";
    cin >> n;
    int arr[n];
    cout << "Enter ARRAY: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << "Enter key: ";
    cin >> key;
    c = binary_search(arr, n, key);
    if (c == 0)
    {
      cout << "Not present!\n";
    }
    else
    {
      cout << "Present! Comparisons: " << c << "\n";
    }
    test--;
  }
  return 0;
}