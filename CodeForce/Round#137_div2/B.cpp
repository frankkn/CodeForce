#include <iostream>
#include <vector>
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
    int k = 1;
    if(n%2 == 0)
    {
      for(int i = 0; i < n/2; ++i)
      {
        v[i*2] = k++;
      }
      for(int j = n/2; j > 0; --j)
      {
        v[j*2-1] = k++;
      }
      for(auto& vi:v)
      {
        cout << vi << " "; 
      }
      cout << "\n";
    }
    else
    {
      for(int i = 0; i <= n/2; ++i)
      {
        v[i*2] = k++;
      }
      for(int j = n/2; j > 0; --j)
      {
        v[j*2-1] = k++;
      }
      for(auto& vi:v)
      {
        cout << vi << " "; 
      }
      cout << "\n";
    }
  }
  return 0;
}