#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<uint64_t>>& tree, vector<uint64_t>& data, uint64_t parent, uint64_t from) {
    for(auto to : tree[from]){
        if(parent != to){
            dfs(tree, data, from, to);
            data[from] += data[to];
        }
    }
}

int main() {
    uint64_t n;
    cin >> n;
    
    vector<uint64_t> data(n+1);
    for(uint64_t i = 1; i <= n; ++i){
        uint64_t d;
        cin >> d;
        data[i] = d;
    }
    
    vector<vector<uint64_t>> tree(n+1);
    for(uint64_t i = 1; i <= n-1; ++i){
        uint64_t x,y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    dfs(tree, data, 0, 1);

    for(uint64_t i = 1; i <= n; ++i){
        cout << data[i] << " ";
    }
    
    return 0;
}
