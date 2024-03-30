#include <iostream>
using namespace std;
void difference(int arr[], int n, int key)
{
  int count = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (abs(arr[i] - arr[j]) == key)
      {
        count++;
      }
    }
  }
  cout << "count: " << count << "\n";
}
int main()
{
  int n, test, key;
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
    cout << "Enter key: ";
    cin >> key;
    difference(arr, n, key);
    test--;
  }
  return 0;
}