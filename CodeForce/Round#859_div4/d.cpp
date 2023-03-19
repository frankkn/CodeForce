#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long int

/*
ll lowbit(ll x){ return x&-x; }

ll query(ll bit[], ll x){
	ll sum = 0;
  for(;x; x-= lowbit(x)){
    sum += bit[x];
  }
  return sum;
}

void update(int i, int val, ll bit[], ll n) {
  for (; i <= n; i += lowbit(i))
  bit[i] += val;
}

int main(){
  
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while(T--){
    int n, q;
    cin >> n >> q;
    ll a[n+1];
    for(int i = 1; i <= n; ++i) cin >> a[i];
    ll bit[n+1];
    for(int i = 1; i <= n; ++i)  bit[i] = 0;
    for(int i = 1; i <= n; ++i){
      update(i, a[i], bit, n);
    }
    cout << bit[n] << endl;
    int L, R, V;
    for(int i = 0; i < q; ++i){  
      cin >> L >> R >> V;
      for (int i = L; i <= R; i += lowbit(i)) bit[i] = V;
      ll sum = bit[n];
      // if(sum %2 == 1) cout << "YES\n";
      // else cout << "NO\n";
    }

  }
  return 0;
}*/

int main(){
  
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while(T--){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; ++i){
      cin >> a[i];
    }
    vector<ll> prefix(n+1);
    prefix[0] = 0;
    prefix[1] = a[1];
    for(int i = 2; i <= n; ++i){
      prefix[i] = prefix[i-1] + a[i];
    }
    ll cur_sum = prefix[n];
    for(int i = 0; i < q; ++i){
      ll L, R, V;
      cin >> L >> R >> V;
      ll diff = (prefix[R]-prefix[L-1]) - ((R-L+1)*V);
      // cout << "diff:" << diff << endl;
      if(abs(prefix[n] + diff) % 2 == 1) cout << "YES\n";
      else  cout << "NO\n";
    }


  }
  return 0;
}