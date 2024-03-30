#include <iostream>
using namespace std;
void find(int arr[], int n, int key)
{
  int i = 0, comp = 0, flag = 0;
  while (i < n)
  {
    comp++;
    if (arr[i] == key)
    {
      flag = 1;
      break;
    }
    i++;
  }
  if (flag != 0)
  {
    cout << "Key found! comparisons: " << comp << "\n";
  }
  else
  {
    cout << "Key not found! comparisons: " << comp << "\n ";
  }
}
int main()
{
  int n, key, m;
  cout << "Enter test cases: ";
  cin >> m;
  while (m > 0)
  {
    cout << "Enter Array size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << "Enter key element: ";
    cin >> key;
    find(arr, n, key);
    m--;
  }
}
