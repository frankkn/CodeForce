#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long int

int main(){
  
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while(T--){
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b == c)  cout << "+\n";
    else  cout << "-\n";
  }
  return 0;
}