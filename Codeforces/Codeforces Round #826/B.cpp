#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void input()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    v.emplace_back(n);
  }
}

void perm(int n)
{
  if(n == 3){
    cout << "-1\n";
    return;
  }
  if(n == 5)
  {
    cout << "5 4 1 2 3\n";
    return;
  }
  if(n%2 == 0)
  {
    for(int i = n; i >= 1; --i)
    {
      cout << i << " \n"[i==1];
    }
    return;
  }
  else
  {
    for(int i = n; i >= 1; --i)
    {
      if(i == n/2+1)
      {
        cout << n/2 << " ";
      }
      else if(i == n/2)
      {
        cout << n/2+1 << " ";
      }
      else
      {
        cout << i << " \n"[i == 1];
      }
    }
  }
}

int main()
{
  input();
  for(auto& v_i: v)
  {
    perm(v_i);
  }
  return 0;
}