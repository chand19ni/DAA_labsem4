#include <iostream>
using namespace std;
long long merge(int arr[], int lb, int mid, int ub, int &comp)
{
  long long inv = 0;
  int i = lb, j = mid + 1, k = lb, brr[100];
  while (i <= mid && j <= ub)
  {
    if (arr[i] <= arr[j])
    {
      brr[k] = arr[i];
      i++;
    }
    else
    {
      brr[k] = arr[j];
      inv += mid - i + 1;
      j++;
    }
    comp++;
    k++;
  }
  while (i <= mid)
  {
    brr[k] = arr[i];
    i++;
    k++;
  }
  while (j <= ub)
  {
    brr[k] = arr[j];
    j++;
    k++;
  }
  for (int c = lb; c <= ub; c++)
  {
    arr[c] = brr[c];
  }
  return inv;
}
long long merge_sort(int arr[], int lb, int ub, int &comp)
{
  long long inv = 0;
  if (lb < ub)
  {
    int mid = lb + (ub - lb) / 2;
    inv += merge_sort(arr, lb, mid, comp);
    inv += merge_sort(arr, mid + 1, ub, comp);
    inv += merge(arr, lb, mid, ub, comp);
  }
  return inv;
}
int main()
{
  int test, n, comp = 0, inv = 0;
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
    inv = merge_sort(arr, 0, n - 1, comp);
    cout << "Sorted ARRAY: ";
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "Comparisons: " << comp << endl;
    cout << "Inversions: " << inv << endl;
    test--;
  }
  return 0;
}