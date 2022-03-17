// https://cses.fi/problemset/task/1640

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
  int64_t n {}, target {};
  cin >> n >> target;
  vector<int64_t> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  map<int64_t, int64_t> hash;
  for(int64_t i = 0; i < A.size(); i++)
  {
    if(hash.find(target - A[i]) != hash.end())
    {
      cout << hash[target - A[i]] << " " << i+1;
      return 0;
    }
    else
    {
      hash[A[i]] = i+1;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}