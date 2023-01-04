#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define ll long long int

ll check(vector<ll>& v, ll f){
  if(v.size() == 1) return 0;
  priority_queue<int, vector<int>, greater<int>> PQ1; // smallest
  priority_queue<int> PQ2;
  ll sum1 = 0, sum2 = 0;
  ll op = 0;
  for(ll i = f+1; i < v.size(); ++i){
    sum1 += v[i];
    PQ1.push(v[i]);
    while(sum1 < 0 && (!PQ1.empty())){
      sum1 -= (PQ1.top()*2);
      ++op;
      PQ1.pop();
    }
  } 
  for(ll i = f; i >= 0; --i){
    sum2 += v[i];
    PQ2.push(v[i]);
    while(sum2 > 0 && (!PQ2.empty())){
      sum2 -= (PQ2.top()*2);
      ++op;
      PQ2.pop();
    }
  }
  return op;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll T;
  cin >> T;
  while(T--){
    ll n, f;
    cin >> n >> f;
    f--;
    vector<ll> v(n,0);
    for(ll i = 0; i < n; ++i){
      cin >> v[i];
    }
    cout << check(v, f) << endl;
  }
  return 0;
}