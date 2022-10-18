#include <iostream>
#include <vector>

using namespace std;

int fac(int n)
{
  if(n <= 1)  return 1;
  else
  {
    return n*fac(n-1);
  }
}

int C(int a, int b)
{
  return fac(a)/(fac(a-b)*fac(b));
}

int main()
{
  int T;
  cin >> T;

  while(T--)
  {
    int n;
    cin >> n;
    vector<int> v(10);
    for(int i = 0; i < n; ++i)
    {
      cin >> v[i];
    }
    cout << C(10-n, 2) * 6 << "\n";
  }
  return 0;
}