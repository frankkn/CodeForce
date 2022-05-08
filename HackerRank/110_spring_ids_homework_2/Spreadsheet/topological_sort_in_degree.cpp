#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> tree(n+1);
    vector<int> data(n+1);
    vector<int> in_degree(n+1);
    while(m--){
        char op;
        cin >> op;
        int to;
        cin >> to;
        int nums = op - 'A';
        while(nums--){
            int from;
            cin >> from;
            tree[from].push_back(to);
            in_degree[to]++;
        }
        cin >> data[to];
    }
    deque<int> q;
    for(int i = 1; i <= n; ++i){
        if(in_degree[i] == 0){
            q.push_back(i);
        }
    }
    while(!q.empty()){
        int s = q.front();
        q.pop_front();
        for(auto to : tree[s]){
            data[to] += data[s];
            if(--in_degree[to] == 0){
                q.push_back(to);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(in_degree[i] != 0){
            cout << "#REF!" << "\n";
        }else{
            cout << data[i] << "\n";
        }
    }
    
    return 0;
}