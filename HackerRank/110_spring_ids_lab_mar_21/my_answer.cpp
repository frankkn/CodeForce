#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// ostream& operator<< (ostream& out, vector<vector<int>> const& v)
// {
//     for(auto v_i : v){
//         for(auto x : v_i){
//             out << x << " ";
//         }
//         out << "\n";
//     }  
//     return out;
// }

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1);
    
    for(int i = 1; i <= m; i++){
        int node, neighbor;
        cin >> node >> neighbor;
        graph[node].push_back(neighbor);
        graph[neighbor].push_back(node);
    }

    // cout << graph;
    
    vector<vector<int>> ff(n+1,vector<int>(501,0));
    for(int i = 1; i <= n; i++){
        for(auto fd = graph[i].begin(); fd != graph[i].end(); fd++){
            vector<int> cur_fd = graph[*fd];
            for(auto nof = cur_fd.begin(); nof != cur_fd.end(); nof++){
                if(*nof != i){
                  ff[i][*nof] = 1;
                }
            }
        }
    }
    
    int max = 0;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for (int j = 1; j <= 501; j++) {
            if(ff[i][j]){
                sum += j;
            }
        }
        if(sum > max){
            max = sum;
        }   
    }
    cout << max;

    return 0;
}