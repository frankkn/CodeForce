#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, int> DIR =
{
  {'U', -1},
  {'D', 1},
  {'L', -1},
  {'R', 1}
};

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m, i1, j1, i2, j2;
    string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    vector<vector<string>> G(n+1, vector<string>(m+1));
    int bounce = 0;
    while(true){
      if(i1 == i2 && j1 == j2){  
        cout << bounce << endl;
        break;
      }
      int hit_wall = 0;
      if(i1 + DIR[d[0]] > n){
        d[0] = 'U';
        hit_wall = 1;
      }else if(i1 + DIR[d[0]] == 0){
        d[0] = 'D';
        hit_wall = 1;
      }
      if(j1 + DIR[d[1]] == 0){
        d[1] = 'R';
        hit_wall = 1;
      }else if(j1 + DIR[d[1]] > m){
        d[1] = 'L';
        hit_wall = 1;
      }
      if(hit_wall)  bounce++;
      i1 = i1 + DIR[d[0]];
      j1 = j1 + DIR[d[1]];

      if(G[i1][j1] == d){
        cout << "-1\n";
        break;
      }
      G[i1][j1] = d;
    }
  }
}