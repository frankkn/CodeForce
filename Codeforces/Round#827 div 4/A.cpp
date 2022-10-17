#include <iostream>
#include <vector>
#include <algorithm>
#define for(i,n) for(int i = 0; i < n; ++i)
using namespace std;

void sum()
{
  vector<int> v(3);
  for(i,3)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if(v[0]+v[1] == v[2])
  {
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main()
{
  int T;
  cin >> T;

  while(T--)
  {
    sum();
  } 

  return 0;
}