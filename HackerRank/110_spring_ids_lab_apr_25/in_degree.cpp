#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
  
    vector<vector<int>> graph(n+1);
    vector<int> in_degree(n+1,0);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        in_degree[y]++;
    }
    
    queue<int> q;
    vector<int> order; // Topological order
    for(int i = 1; i <= n; ++i){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        order.push_back(node);
        for(auto it = graph[node].begin(); it != graph[node].end(); ++it){
            if(--in_degree[*it] == 0){
                q.push(*it);
            }
        }
    }
    
    if(order.size() == n){
        cout << "yes";
    }else{
        cout << "no";
    }

    return 0;
}