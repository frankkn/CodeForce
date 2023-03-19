#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
  int T;
  cin >> T;

  while(T--)
  {
    int n;
    cin >> n;
    vector<int> lid(n);
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i)
    {
      lid[i] = s[i] -'0';
    }
    vector<int> mag(n);
    for(int i = 0; i < n; ++i)
    {
      cin >> mag[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; )
    {
      if(lid[i] == 0)
      {
        int j = i+1;
        while(j < n && lid[j] == 1)
        {
          j++;
        }
        int cur_min = 1e+9;
        for(int s = i; s < j; ++s){
          if(mag[s] < cur_min)  cur_min = mag[s];
          cnt += mag[s];
        }
        cnt -= cur_min;
        i = j;
      }
      else
      {
        i++;
      }
    }
    if(lid[0]==1)
    {
      for(int i = 0; i < n; ++i)
      {
        if(lid[i] == 1)
        {
          cnt += mag[i];
        }else{
          break;
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}