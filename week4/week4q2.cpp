#include <iostream>
using namespace std;
int Partition(int arr[], int lb, int ub, int &swwap, int &comp)
{
  int start = lb, end = ub, pivot = arr[lb];
  while (start < end)
  {
    while (arr[start] <= pivot)
    {
      start++;
      comp++;
    }
    while (arr[end] > pivot)
    {
      end--;
      comp++;
    }
    if (start < end)
    {
      swap(arr[start], arr[end]);
      swwap++;
    }
  }
  swap(arr[lb], arr[end]);
  swwap++;
  return end;
}
void Quick_sort(int arr[], int lb, int ub, int &swwap, int &comp)
{
  if (lb < ub)
  {
    int loc = Partition(arr, lb, ub, swwap, comp);
    Quick_sort(arr, lb, loc - 1, swwap, comp);
    Quick_sort(arr, loc + 1, ub, swwap, comp);
  }
}
int main()
{
  int test, n, swwap = 0, comp = 0;
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
    Quick_sort(arr, 0, n - 1, swwap, comp);
    cout << "Sorted ARRAY: ";
    for (int k = 0; k < n; k++)
    {
      cout << arr[k] << " ";
    }
    cout << "\ncomparisons: " << comp << "\n"
         << "swaps: " << swwap << "\n";
    test--;
  }
  return 0;
}