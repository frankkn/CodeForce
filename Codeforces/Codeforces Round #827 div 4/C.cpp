#include <iostream>
#include <vector>
#include <string>
#define for(i,n) for(int i = 0; i < n; ++i)
using namespace std;

int main()
{
  int T;
  cin >> T;

  while(T--)
  {
    // string s;
    // cin >> s;
    vector<vector<int>> g(8,vector<int>(8,0));
    for(i, 8)
    {
      string row;
      cin >> row;
      for(j,8)
      {
        if(row[j] == '.') g[i][j] = 0;
        else if(row[j] == 'R') g[i][j] = 1;
        else g[i][j] = 2;
      }
    }

    bool flag = false;
    for(r, 8)
    {
      if(flag)  break;
      for(c, 7)
      {
        if(flag)  break;
        if(g[r][c] == 0)  break;
        if(g[r][c] != g[r][c+1])  break;
        if(c == 6 && (g[r][c] == g[r][c+1]))
        {
          if(g[r][c] == 1){
            flag = true;
            cout << "R\n";
          }
          else{
            flag = true;
            cout << "B\n";
          }
        }
      }
    }
    if(!flag)
    {
      for(c,8)
      {
        if(flag)  break;
        for(r,7)
        {
          if(flag)  break;
          if(g[r][c] == 0)  break;
          if(g[r][c] != g[r+1][c])  break;
          if(r == 6 && (g[r][c] == g[r+1][c]))
          {
            if(g[r][c] == 1){
              flag = true;
              cout << "R\n";
            }
            else{
              flag = true;
              cout << "B\n";
            }
          }
        }
      } 
    }

  }
  

  return 0;
}