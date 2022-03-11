#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int64_t n {}, target {};
  cin >> n >> target;
  vector<int64_t> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  // unordered_map<int64_t, int64_t> unordered_map;
  // for(int64_t i = 0; i < n; ++i)
  // {
  //   unordered_map.insert(pair<int64_t, int64_t>(A[i], i+1));
  // }
  vector<int64_t> B(n);
  B = A;

  sort(A.begin(), A.end());
  vector<int64_t>::iterator left = A.begin(), right = prev(A.end());
  while(left != right)
  {
    int64_t sum = (*left + *right);
    if(sum < target)
    {
      left++;
    }
    else if(sum > target )
    {
      right--;
    }
    else
    {
      for(int i = 0; i < n; ++i)
      {
        if(*left == B[i]){ cout << i+1 << " "; }
      }
      
      for(int i = n-1; i >= 0; --i)
      {
        if(*right == B[i]){ cout << i+1;  }
      }
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}