#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left_child = (2 * i) + 1;
  int right_child = (2 * i) + 2;
  if (left_child < n && arr[left_child] > arr[largest])
  {
    largest = left_child;
  }
  if (right_child < n && arr[right_child] > arr[largest])
  {
    largest = right_child;
  }
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}
void Heap_sort(int arr[], int n, int k, int &ele)
{
  if (k < n)
  {
    for (int i = n / 2 - 1; i >= 0; i--)
    {
      heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
      swap(arr[0], arr[i]);
      if (k == n - i)
      {
        ele = arr[i];
        return;
      }
      heapify(arr, i, 0);
    }
  }
  else
  {
    cout << "Not present!" << endl;
  }
}
int main()
{
  int test, n, k, ele = 0;
  cout << "Enter test cases: ";
  cin >> test;
  while (test > 0)
  {
    cout << "Enter ARRAY size: ";
    cin >> n;
    int arr[100];
    cout << "Enter ARRAY: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << "Enter Kth(largest):";
    cin >> k;
    Heap_sort(arr, n, k, ele);
    cout << k << "th Largest element: " << ele << endl;
    test--;
  }
  return 0;
}