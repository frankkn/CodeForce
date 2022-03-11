#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

int main()
{
  int64_t n {}, target {};
  cin >> n >> target;
  vector<int64_t> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  map<int64_t,list<int64_t>> map;
  for(int64_t i = 0; i < n; ++i)
  {
    map[A[i]].push_back(i+1);
  }

  sort(A.begin(), A.end());
  vector<int64_t>::iterator left = A.begin(), right = prev(A.end());
  while(left != right)
  {
    int64_t sum = (*left + *right);
    if(sum < target)
    {
      left++;
    }
    else if(sum > target)
    {
      right--;
    }
    else
    {
      if(*left == *right)
      {
        list<int64_t>::iterator it = map[*left].begin(); 
        cout << *it << " " << *(++it); 
      }
      else
      {
        cout << *map[*left].begin() << " " << *map[*right].begin();
      }
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}