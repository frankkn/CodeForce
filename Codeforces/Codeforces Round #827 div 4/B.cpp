#include <iostream>
#include <vector>
#include <algorithm>
#define for(i,n) for(int i = 0; i < n; ++i)
using namespace std;

int main()
{
  int T;
  cin >> T;

  while(T--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for(i, n)
    {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool flag = true;
    for(i, n-1)
    {
      if(v[i] == v[i+1])
      {
        flag = false;
        break;
      }
    }
    if(flag)  cout << "YES\n";
    else  cout <<"NO\n";
  }
  

  return 0;
}