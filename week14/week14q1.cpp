#include <iostream>
using namespace std;
bool checkUgly(int i)
{
  if (i <= 0)
  {
    return false;
  }
  if (i == 1)
  {
    return true;
  }
  if (i % 2 == 0)
  {
    return checkUgly(i / 2);
  }
  if (i % 3 == 0)
  {
    return checkUgly(i / 3);
  }
  if (i % 5 == 0)
  {
    return checkUgly(i / 5);
  }
  return false;
}
int getugly(int n)
{
  int ugly = 0, i = 0;
  while (i != n)
  {
    ugly++;
    if (checkUgly(ugly))
    {
      i++;
    }
  }
  return ugly;
}
int main()
{
  int n, test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    int result = getugly(n);
    cout << n << "th ugly number: " << result << endl;
  }
  return 0;
}