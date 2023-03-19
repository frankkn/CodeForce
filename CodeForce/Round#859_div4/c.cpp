#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
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
    string s;
    cin >> s;
    set<int> set1, set2;
    for(int i = 0; i < s.size(); ++i){
      if(i%2==0)  set1.emplace(s[i]);
      else set2.emplace(s[i]);
    }
    // for(auto s_i: set1) cout << s_i << " ";
    // cout << endl;
    // for(auto s_i: set2) cout << s_i << " ";
    // cout << endl;

    set<int> comm;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(comm, comm.begin()));
    
    // for(auto s_i: comm) cout << s_i << " ";
    // cout << endl;

    if(comm.size()==0)  cout << "YES\n";
    else  cout <<"NO\n";

  }
  return 0;
}