#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
  int smallest = i;
  int left_child = (2 * i) + 1;
  int right_child = (2 * i) + 2;
  if (left_child < n && arr[left_child] < arr[smallest])
  {
    smallest = left_child;
  }
  if (right_child < n && arr[right_child] < arr[smallest])
  {
    smallest = right_child;
  }
  if (smallest != i)
  {
    swap(arr[i], arr[smallest]);
    heapify(arr, n, smallest);
  }
}
void heap_sort(int arr[], int n, int k, int &ele)
{
  if (k < n)
  {
    for (int i = n / 2 - 1; i >= 0; i--)
    {
      heapify(arr, n, i);
    }
    for (int i = 0; i < k; i++)
    {
      ele = arr[0];
      swap(arr[0], arr[n - i - 1]);
      heapify(arr, n - i - 1, 0);
    }
  }
  else
  {
    cout << "Not present!" << endl;
  }
}
int main()
{
  int test, n, k, ele, arr[100];
  cout << "Enter test case: ";
  cin >> test;
  while (test > 0)
  {
    cout << "Enter ARRAY size: ";
    cin >> n;
    cout << "Enter ARRAY: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << "Enter K(smallest): ";
    cin >> k;
    heap_sort(arr, n, k, ele);
    cout << k << "th Smallest element: " << ele << endl;
    test--;
  }
  return 0;
}