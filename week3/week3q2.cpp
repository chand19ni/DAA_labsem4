#include <iostream>
#include <algorithm>
using namespace std;
void selection_sort(int arr[], int n)
{
  int min, comp = 0, swwap = 0, flag = 0;
  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      comp++;
      if (arr[min] > arr[j])
      {
        flag = 1;
        min = j;
      }
    }
    if (min != i || flag == 1)
    {
      swwap++;
      swap(arr[min], arr[i]);
    }
  }
  cout << "Sorted ARRAY: ";
  for (int k = 0; k < n; k++)
  {
    cout << arr[k] << " ";
  }
  cout << "\ncomparisons: " << comp << "\n"
       << "swaps: " << swwap << "\n";
}
int main()
{
  int test, n;
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
    selection_sort(arr, n);

    test--;
  }
  return 0;
}