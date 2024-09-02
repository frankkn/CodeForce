#include <iostream>
#include <vector>
#include <numeric> // for gcd function
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    string s; cin >> s;

    vector<int> Father(n+1, 0);
    unordered_map<int, int> mp; // i, black NO
    for(int i = 1; i <= n; ++i){
        if(!Father[i]){
            Father[i] = i;
            int start = a[i];
            int black = (s[i-1]=='0')?1:0;
            while(start != i){
                Father[start] = i;
                if(s[start-1] == '0'){
                    black++;
                }
                start = a[start];
            }
            mp[i] = black;
            cout << mp[i] << " ";
        }else{
            cout << mp[Father[i]] << " ";
        }
    }
    cout << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
