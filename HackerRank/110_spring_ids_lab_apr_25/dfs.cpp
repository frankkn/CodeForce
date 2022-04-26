#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, int& timer, vector<int>& finish_time, vector<bool>& visited, int start){
    visited[start] = true;
    for(auto it = graph[start].begin(); it != graph[start].end(); ++it){
        if(!visited[*it]){
            dfs(graph, timer, finish_time, visited, *it);
        }
    }
    timer++;
    finish_time[start] = timer;
}

bool has_cycle(vector<vector<int>>& graph, vector<int>& finish_time, int& root){
    for(int i = 1; i < static_cast<int>(graph.size()); ++i){
        for(auto it = graph[i].begin(); it != graph[i].end(); ++it){
            if(finish_time[*it] > finish_time[i]){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1);
    while(m--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    
    int timer = 0; // A timer which increments when a node finishes traversal
    vector<int> finish_time(n+1); 
    int root = 1;
    vector<bool> visited(n+1);
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            dfs(graph, timer, finish_time, visited, i);
        }
    }

    if(has_cycle(graph, finish_time, root)){
        cout << "no";
    }else{
        cout << "yes";
    }
    
    return 0;
}