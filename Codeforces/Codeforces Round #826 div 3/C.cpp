#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

int t;
vector<vector<int>> v;
void input()
{
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> vv(n);
    for(int i = 0; i < n; ++i)
    {
      cin >> vv[i];
    }
    v.push_back(vv);
  }
}

int thick(vector<int>& a)
{
  int sum = accumulate(a.begin(), a.end(), 0);
  int n = a.size();
  vector<int> min_max_thick {n};
  for(int c = 2; c <= n; ++c)
  {
    if(sum % c != 0)  continue; 
    int target = sum / c;
    int cur_sum = 0;
    int set_cnt = 0;
    int cur_thick = 0;
    int cur_max_thick = 0;
    for(int i = 0; i < n; ++i)
    {
      cur_thick++;
      cur_sum += a[i];
      if(cur_sum == target){
        cur_sum = 0;
        set_cnt++;
        cur_max_thick = cur_max_thick < cur_thick ? cur_thick: cur_max_thick;
        cur_thick = 0;
        continue;
      }
      else if(cur_sum > target){
        break;
      } 
    }
    if(set_cnt == c)
    {
      min_max_thick.push_back(cur_max_thick);
    }
  }
  return *min_element(min_max_thick.begin(), min_max_thick.end());
}

int main()
{
  input();
  for(auto& v_i: v)
  {

    cout << thick(v_i) << "\n";
  }
  return 0;
}