#include <iostream>
#include <vector>
#include <numeric> // for gcd function
#include <algorithm>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    if(a == 0 && b == 0){
        cout << "YES" << endl;
        return;
    }
    if(a == 0){
        if(b % 2 == 0){
            cout << "YES" << endl;
            return;
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    if(b ==0 ){
        if(a % 2 == 0){
            cout << "YES" << endl;
            return;
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    if(a % 2 == 0){
        cout << "YES" << endl;
        return;
    }else{
        cout << "NO" << endl;
        return;
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
