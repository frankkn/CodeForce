#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& color, vector<int>& parents, int parent, int start, vector<int>& path, bool& flag){
    if(flag)    return;
    
    if(color[start] == 2){
        return;
    }
    
    if(color[start] == 1){
        flag = true;
        path.push_back(start);
        int cur = parent;
        while(cur != start){
            path.push_back(cur);
            cur = parents[cur];
        }
        return;
    }
    
    color[start] = 1;
    
    parents[start] = parent;
    
    for(auto to: graph[start]){
        // if(color[to] == 0){
        //     parents[to] = start;
        //     dfs(graph, color, parents, start, to, mark, cycleNum);
        // }
        if(to == parents[start]){
            continue;
        }
        dfs(graph, color, parents, start, to, path, flag);
        
    }
    color[start] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    vector<int> color(n+1,0); // 0:white 1:gray 2:black
    vector<int> parents(n+1);
    vector<int> path;
    bool flag = 0;
    for(int i = 1; i <= n; ++i){
        if(color[i] == 0){
            dfs(graph, color, parents, 0, i, path, flag);
            if(flag){
                cout << path.size() << "\n";
                for(auto p:path){
                    cout << p << " ";
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}