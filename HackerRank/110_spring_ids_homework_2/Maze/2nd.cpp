#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int>dir_x = {0,1,0,-1};
vector<int>dir_y = {1,0,-1,0};

pair<int,int> Coordinate(vector<string>& graph, char c){
    for(int i = 0; i < static_cast<int>(graph.size()); ++i){
        for(int j = 0; j < static_cast<int>(graph[0].size()); ++j){
            if(graph[i][j] == c){
                return (make_pair(i,j)); 
            }
        }
    }
    return {};
}

void BFS(vector<string>& graph, vector<vector<int>>& dist, pair<int,int>& A, pair<int,int>& B){
    queue<pair<int,int>> q;
    q.push(A);
    dist[A.first][A.second] = 0;
    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();
        if(cur == B){
            break;
        }
        for(int i = 0; i < 4; ++i){
            int new_x = cur.first + dir_x[i];
            int new_y = cur.second + dir_y[i];
            if( new_x >= 0 && new_x < static_cast<int>(graph.size()) && 
                new_y >= 0 && new_y < static_cast<int>(graph[0].size()) &&
                graph[new_x][new_y] != '#' &&
                dist[new_x][new_y] == INT_MAX
            ){
                dist[new_x][new_y] = dist[cur.first][cur.second] + 1; 
                q.push(make_pair(new_x, new_y));
            }
        }
    }
    return;
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<string> graph;
    for(int i = 0; i < row; ++i){
        string s;
        cin >> s;
        graph.push_back(s);
    }
    pair<int,int> A = Coordinate(graph, 'A');
    pair<int,int> B = Coordinate(graph, 'B');
    
    vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

    BFS(graph, dist, A, B);
    
    if(dist[B.first][B.second] != INT_MAX){
        cout << dist[B.first][B.second];
    }else{
        cout << "IMPOSSIBLE";
    }
    
    return 0;
}
