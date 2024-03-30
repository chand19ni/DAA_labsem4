#include <iostream>
using namespace std;
void addup(int arr[], int n)
{
  int flag = 0, a, b, add;
  for (int k = n - 1; k >= 2; k--)
  {
    int i = 0, j = k - 1;
    while (i < j)
    {
      if (arr[i] + arr[j] == arr[k])
      {
        a = i;
        b = j;
        add = k;
        flag = 1;
        break;
      }
      else if (arr[i] + arr[j] < arr[k])
      {
        i++;
      }
      else
      {
        j--;
      }
    }
    if (flag == 1)
    {
      break;
    }
  }
  if (flag == 0)
  {
    cout << "No sequence found!\n";
  }
  else
  {
    cout << "i= " << (a + 1) << " j= " << (b + 1) << " k= " << (add + 1) << "\n";
  }
}
int main()
{
  int test, n;
  cout << "Enter test case: ";
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
    addup(arr, n);
    test--;
  }
  return 0;
}