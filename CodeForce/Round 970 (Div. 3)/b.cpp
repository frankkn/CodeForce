#include <iostream>
#include <vector>
#include <numeric> // for gcd function
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if(sqrt(n) * sqrt(n) != n){
        cout << "NO" << endl;
        return;
    }

    int sum = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '1'){
            sum++;
        }
    }

    int e = sqrt(n);
    if(sum == (e*e - (e-2)*(e-2)) ){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
