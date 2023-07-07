#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long int

vector<vector<int>> v;
vector<vector<int>> w;

void cal(vector<vector<int>>& v, int p, int h, int m){
    sort(v[p].begin(), v[p].end());
    int a = 0, penalty = 0, time = 0;
    for(int i = 0; i < m; ++i){
        if(time + v[p][i] > h) break;
        time += v[p][i];
        a++;
        penalty += time;
    }
    w[p][0] = a;
    w[p][1] = penalty;
    w[p][2] = p;
}

bool cmp(const vector<int>&a, const vector<int>& b){
    if (a[0] != b[0]) {
        return a[0] > b[0];
    } else {
        return a[1] < b[1];
    }
}

int main(){
  
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while(T--){
    int n, m, h; cin >> n >> m >> h;
    v.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> v[i][j];
        }
    }


    w.assign(n, vector<int>(3, 0));
    for(int i = 0; i < n; ++i){
        cal(v, i, h, m);
    }
    stable_sort(w.begin(), w.end(), cmp);

    // for(const auto w_i : w){
    //     cout << "w:" << w_i[0] << " " << w_i[1] << " " << w_i[2] ;
    // }
    // cout << endl;

    int rank = 0;
    for(int i = 0; i < n; ++i){
        if(w[i][2] == 0) {rank++; break;}
        else rank++;
    }
    cout << rank << endl;
  }
  return 0;
}