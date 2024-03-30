#include <iostream>
using namespace std;
int search(int arr[], int lb, int ub, int key)
{
  int comp = 0;
  if (lb < ub)
  {
    int mid = lb + (ub - lb) / 2;
    if (arr[mid] == key)
    {
      comp++;
      return comp;
    }
    else if (key < arr[mid])
    {
      comp++;
      return comp + search(arr, lb, mid - 1, key);
    }
    else
    {
      comp++;
      return comp + search(arr, mid + 1, ub, key);
    }
  }
  return 0;
}
int main()
{
  int n, key, c;
  cout << "Enter array size:";
  cin >> n;
  int arr[n];
  cout << "Enter ARRAY: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << "Enter key element: ";
  cin >> key;
  c = search(arr, 0, n, key);
  if (c == 0)
  {
    cout << "KEY not found!";
  }
  else
  {
    cout << "Key found! Total comp: " << c;
  }
  return 0;
}