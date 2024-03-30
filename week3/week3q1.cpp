#include <iostream>
using namespace std;
void insertion_sort(int arr[], int n)
{
  int comp = 0, shift = 0;
  for (int i = 1; i < n; i++)
  {
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      comp++;
      shift++;
      arr[j + 1] = arr[j];
      j--;
    }
    shift++;
    arr[j + 1] = temp;
  }
  cout << "Sorted Array-\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\ncomparisons: " << comp << "\n"
       << "shifts: " << shift << "\n";
}
int main()
{
  int test, n;
  cout << "Enter test: ";
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
    insertion_sort(arr, n);
    test--;
  }
  return 0;
}