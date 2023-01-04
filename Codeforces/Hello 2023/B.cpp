#include <iostream>
#include <vector>
#include <string>
using namespace std;

void check(int n){
  if(n == 3){
    cout <<"NO"<<endl;
  }else if(n%2){
    cout<<"YES"<<endl;
    for(int i = 0; i < n; ++i){
      if(i%2 == 0){
        cout << (n/2-1)*-1;
      }else{
        cout << n/2;
      }
      if(i != n-1)  cout << " ";
    }
    cout << endl;
    return;
  }else{
    cout<<"YES"<<endl;
    for(int i = 0; i < n; ++i){
      if(i%2){
        cout << "1";
      }else{
        cout << "-1";
      }
      if(i != n-1)  cout << " ";
    }
    cout << endl;
  }
}

int main(){
  int T;
  cin >> T;
  
  while(T--){
    int n;
    cin >> n;
    check(n);
  }
  return 0;
}