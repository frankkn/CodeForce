#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> S(n);
    for(auto& s : S) { cin >> s; }
    
    map<int,int> map;
    for(int i = 0; i < k; ++i){
        map[S[i]]++;
    }
    cout << map.size() << " ";
    
    for(int i = k; i < n; ++i){
        if(--map[S[i-k]] == 0){
            map.erase(S[i-k]);
        } 
        map[S[i]]++;
        cout << map.size() << " ";
    }
    
    return 0;
}