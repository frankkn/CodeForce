#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int T; 
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);

    int a[n+1];
    int pf[n+1];
    pf[0] = 0;
    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
      pf[i] = pf[i-1] + a[i];
    }

    int l = 1, r = n;
    while (l != r) {
      int mid = (l + r) / 2;
      printf("? %d ", mid - l + 1);
      fflush(stdout);
      for(int i = l; i <= mid; ++i){
        if(i == mid){
          printf("%d", i);
          fflush(stdout);
        }else{
          printf("%d ", i);
          fflush(stdout);
        }
      }
      printf("\n");
      fflush(stdout);

      int response;
      scanf("%d", &response);

      if (response == pf[mid]-pf[l-1])
        l = mid + 1;
      else
        r = mid;
    }

    printf("! %d\n", l);
    fflush(stdout);
  }
}