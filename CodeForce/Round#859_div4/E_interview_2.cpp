#include <iostream>

using namespace std;

int main() {
  int T; 
  cin >> T;
  while(T--){
    int n;
    cin >> n;

    int a[n+1];
    int pf[n+1];
    pf[0] = 0;
    for(int i = 1; i <= n; ++i){
      cin >> a[i];
      pf[i] = pf[i-1] + a[i];
    }

    int l = 1, r = n;
    while (l != r) {
      int mid = (l + r) / 2;
      cout << "? " << mid-l+1 << " ";
      for(int i = l; i <= mid; ++i){
        cout << i << " ";
      }
      cout << endl;

      int response;
      cin >> response;

      if (response == pf[mid]-pf[l-1])
        l = mid + 1;
      else
        r = mid;
    }

    cout << "! " << l << endl;
  }
}