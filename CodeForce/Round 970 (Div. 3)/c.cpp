#include <iostream>
#include <vector>
#include <numeric> // for gcd function
#include <algorithm>
#include <cmath>
using namespace std;
 
void solve() {
    long long l, r; cin >> l >> r;
 
    long long L = 1, R = r;
    while(L < R){
        long long M = (L+R)/2;
        if( (M+1)*M/2 <= (r-l)){
            L = M+1;
        }else{
            R = M;
        }
    }
    
    cout << L << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}