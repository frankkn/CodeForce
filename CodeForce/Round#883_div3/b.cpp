#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long int

vector<vector<char>> v(3, vector<char>(3, 0));

bool check_row(){
  for(int i = 0; i < 3; ++i){
    if(v[i][0] == '.' || v[i][1] == '.' || v[i][2] == '.') continue;
    if(v[i][0] == v[i][1]){
        if(v[i][1] == v[i][2]){
            cout << v[i][0] << endl;
            return 1;
        }
    }
  }
  return 0;
}

bool check_col(){
    for(int i = 0; i < 3; ++i){
        if(v[0][i] == '.' || v[1][i] == '.' || v[2][i] == '.') continue;
        if(v[0][i] == v[1][i]){
            if(v[1][i] == v[2][i]){
                cout << v[0][i] << endl;
                return 1;
            }
        }
    }
    return 0;
}

bool check_dia(){
    if(v[0][0] == v[1][1] && v[0][0] != '.'){
        if(v[1][1] == v[2][2]){
            cout << v[0][0] << endl;
            return 1;
        }
    }
    if(v[0][2] == v[1][1] && v[0][2] != '.'){
        if(v[1][1] == v[2][0]){
            cout << v[0][2] << endl;
            return 1;
        }
    }
    return 0;
}

int main(){
  
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while(T--){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            char s; cin >> s;
            v[i][j] = s;
        }
    }

    if(check_row() != 1){
        if(check_col() != 1){
            if(check_dia() != 1){
                cout << "DRAW" << endl;
            }
        }
    }


  }
  return 0;
}