#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void FindKthUgly(long long k)
{
    vector<long long> ugly(k+1); // index from 0 to k
    ugly[1] = 1;
    long long p2 = 1, p3 = 1, p5 = 1;
    for(long long i = 2; i <= k; i++)
    {
        long long f2 = 2 * ugly[p2];
        long long f3 = 3 * ugly[p3];
        long long f5 = 5 * ugly[p5];
        long long min_ = min(f2, min(f3, f5));
        
        ugly[i] = min_;
        
        if(min_ == f2){ p2++; }
        if(min_ == f3){ p3++; }
        if(min_ == f5){ p5++; }    
    }
    cout << ugly[k] << "\n";
    return;
}

int main() {
    long long n;
    cin >> n;
    long long k;
    while(n--)
    { 
        cin >> k; 
        FindKthUgly(k);
    }
    return 0;
}