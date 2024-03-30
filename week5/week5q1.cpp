#include <iostream>
using namespace std;
void count_sort(char arr[], int n)
{
  int alphabet[26] = {0}, flag = 0, maxm = 0;
  char ele;
  for (int i = 0; i < n; i++)
  {
    alphabet[(int)arr[i] % 97]++;
  }
  for (int j = 1; j < 26; j++)
  {
    if (alphabet[j] > alphabet[maxm])
    {
      maxm = j;
    }
    if (alphabet[j] > 1)
    {
      flag = 1;
    }
  }
  ele = (char)(97 + maxm);
  if (flag == 0)
  {
    cout << "No Duplicates Present!" << endl;
  }
  else
  {
    cout << ele << "- " << alphabet[maxm] << endl;
  }
}
int main()
{
  int test, n;
  char arr[100];
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
    count_sort(arr, n);
    test--;
  }
  return 0;
}