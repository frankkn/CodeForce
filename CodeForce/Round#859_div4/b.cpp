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
    vector<int> a(n);
    for(int i = 0; i < n; ++i)  cin >> a[i];
    int M = 0, B = 0;
    for(int i = 0; i < n; ++i){
      if(a[i]%2==0) M+=a[i];
      else  B+=a[i];
    }
    if(M > B) cout << "YES\n";
    else  cout <<"NO\n";
  }
  return 0;
}