#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long int

int main(){
  
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    // cout << "n:" << n << endl;
    vector<int> c(n);
    for(auto& c_i: c) cin >> c_i;
    // cout << endl;
    if(n == 1){
      if(c[0] == 1){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
      continue;
    }
    sort(c.begin(), c.end());
    vector<int> a(1,1);
    for(int i = 1; i < n; ++i){
      int sum;
      for(int j = 0; j < i; ++j){
        sum = 0;
        for(int k = j; k < i; ++k){
          sum += a[k];
        }
        if(sum == c[i]) a.emplace_back(sum);
      }
    }
    if(a.size() == c.size())  cout << "YES\n";
    else  cout << "NO\n";
  }
  return 0;
}