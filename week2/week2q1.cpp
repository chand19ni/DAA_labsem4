#include <iostream>
using namespace std;
int search(int arr[], int lb, int ub, int key)
{
  int count = 0;
  if (lb < ub)
  {
    int mid = lb + (ub - lb) / 2;
    if (key == arr[mid])
    {
      count++;
      int i = mid - 1;
      while (i >= 0 && arr[i] == key)
      {
        count++;
        i--;
      }
      i = mid + 1;
      while (i < ub && arr[i] == key)
      {
        count++;
        i++;
      }
      return count;
    }
    else if (key < arr[mid])
    {
      return count + search(arr, 0, mid - 1, key);
    }
    else
    {
      return count + search(arr, mid + 1, ub, key);
    }
  }
  return 0;
}
int main()
{
  int n, key, test, c = 0;
  cout << "Enter case: ";
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
    c = search(arr, 0, n, key);
    if (c != 0)
    {
      cout << "FOUND count: " << c << "\n";
    }
    else
    {
      cout << "Not FOUND!\n";
    }
    test--;
  }
  return 0;
}
