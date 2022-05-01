#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    queue<int> q;
    vector<int> color(n+1,0);
    for(int i = 1; i <= n; ++i){ //Traverse each components in graph
        if(color[i] != 0){ //If centain component has been traversed 
            continue;
        }
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            if(color[cur] == 0){ //First node in certain component
                color[cur] = 1;
            }
            for(auto it = graph[cur].begin(); it != graph[cur].end(); it++){
                if(color[*it] == 0){
                    q.push(*it);
                    color[*it] = 3-color[cur];
                }
                if(color[*it] == color[cur]){
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
    
    return 0;
}