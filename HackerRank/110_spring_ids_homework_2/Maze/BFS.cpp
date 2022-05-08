#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int row, col;
pair<int,int> A,B;
vector<string> maze;
vector<vector<int>> dist;
vector<int> dx = {1,0,-1,0};//up right down left
vector<int> dy = {0,1,0,-1};//up right down left
void BFS(pair<int,int> A);

int main() {
    cin >> row >> col;
    
    for(int i = 0; i < row; ++i){
        string s;
        cin >> s;
        maze.push_back(s);
    }
    dist.resize(row,vector<int>(col,INT_MAX));
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(maze[i][j] == 'A'){
                A.first = i;
                A.second = j;
            }else if(maze[i][j] == 'B'){
                B.first = i;
                B.second = j;
            }
        }
    }
    
    BFS(A);
    
    if(dist[B.first][B.second] != INT_MAX){
        cout << dist[B.first][B.second];
    }else{
        cout << "IMPOSSIBLE";
    }
    
    return 0;
}

void BFS(pair<int,int> A){
    queue<pair<int,int>> q;
    q.push(A);
    dist[A.first][A.second] = 0;
    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();
        if(cur == B){
            break;
        }
        for(int i=0; i < 4; ++i){
            int new_x = cur.first + dx[i];
            int new_y = cur.second + dy[i];
            if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < col &&
               maze[new_x][new_y] != '#' && dist[new_x][new_y] == INT_MAX){
                q.push(make_pair(new_x, new_y));
                dist[new_x][new_y] = dist[cur.first][cur.second]+1;
            }
        }
    }
    return;
}