#include <iostream>
#include <vector>

using namespace std;

#define MOD ((int)1e9+7)

// 快速冪算法計算模數逆元
long long modInverse(long long a, long long mod) {
    long long result = 1;
    long long power = mod - 2;
    while (power) {
        if (power % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        power /= 2;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long sum_of_elements = 0;
    long long sum_of_squares = 0;

    for (auto num : a) {
        sum_of_elements = (sum_of_elements + num) % MOD;
        sum_of_squares = (sum_of_squares + (num * num) % MOD) % MOD;
    }

    // 計算 ((sum_of_elements * sum_of_elements - sum_of_squares) / 2) % MOD
    long long result = (sum_of_elements * sum_of_elements) % MOD; 
    result = (result - sum_of_squares + MOD) % MOD;  // 防止出現負數
    result = (result * modInverse(2, MOD)) % MOD;  

    // 計算 (n-1)*n/2 的模數逆元
    long long tmp = ((n - 1)*1LL* n / 2 ) % MOD; // *1LL 因為n是int...
    long long tmp_inv = modInverse(tmp, MOD);

    // 最終結果
    cout << (result * tmp_inv) % MOD << endl; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
