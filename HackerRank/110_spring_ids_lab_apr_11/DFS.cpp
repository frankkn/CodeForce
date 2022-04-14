#include <iostream>
#include <vector>
using namespace std;
vector<int> visited;

void dfs(vector<vector<int>>& graph, int i);

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1);
    while(m--){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    visited.resize(n+1,0);
    visited[0] = 1;
    
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(visited[i] == 0){
            dfs(graph, i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

void dfs(vector<vector<int>>& graph, int i){
    visited[i] = 1;
    for(auto it = graph[i].begin(); it != graph[i].end(); it++){
        if(!visited[*it]){
            dfs(graph, *it);
        }
    }
    return;
}