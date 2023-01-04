#include <iostream>
#include <vector>
#include <string>
using namespace std;

int check(string& s) {
  int fL = s.find_first_of('L');
  int fR = s.find_first_of('R');
  // cout << fL << " " << fR << endl;
  if(fL == string::npos || fR == string::npos)
  {
    return -1;
  }else if(fL < fR){
    return fR;
  }else{
    return 0;
  }
  return -1;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << check(s) << endl;
  }
  return 0;
}