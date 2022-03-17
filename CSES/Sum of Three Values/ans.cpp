// https://cses.fi/problemset/task/1641

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

pair<int64_t, int64_t> two_sum (vector<int64_t>::iterator left, vector<int64_t>::iterator right, int64_t target)
{
  int64_t sum = *left+*right;
  while(left != right){
    if(sum > target)
    {
      right--;
    }
    else if(sum < target)
    {
      left++;
    }
    else
    {
      pair<int64_t, int64_t> p(*left,*right);
      return p;
    }
  }
  return make_pair<int64_t, int64_t>(0,0);
}

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

  vector<int64_t>::iterator left = A.begin(); 
  vector<int64_t>::iterator right = prev(prev(A.end()));

  pair<int64_t, int64_t> p;
  for(int64_t i = n-1; i >= 2; --i)
  {
    right--;
    p = two_sum(left, right, target - A[i]);
    if(p == make_pair<int64_t, int64_t>(0,0)){
      continue;
    }

    int64_t num1 = p.first;
    int64_t num2 = p.second;
    if(p.first == p.second){
      cout << *map[p.first].begin() << " " << *++map[p.first].begin() << " " << *map[A[i]].begin();
      return 0;
    }else if(p.first == A[i])
    {
      cout << *map[p.first].begin() << " " << *++map[p.first].begin()  << " " << *map[A[i]].begin();
      return 0;
    }else if(p.second == A[i]){
      cout << *map[p.first].begin() << " " << *map[p.second].begin()  << " " << *map[A[i]].begin();
      return 0;
    }else{

    }
  }
  
  if(p == make_pair<int64_t, int64_t>(0,0)){
    cout << "IMPOSSIBLE";
  }
  return 0;
}