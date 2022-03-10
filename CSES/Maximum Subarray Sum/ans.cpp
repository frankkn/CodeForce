#include <iostream>
#include <vector>
using namespace std;

int main()
{
  uint64_t n {};
  cin >> n;
  vector<int64_t> A(n);
  for(auto& A_i : A){ cin >> A_i; }
  if(n == 1)  {cout << A[0]; return 0;}
  int64_t max_sum = A[0];
  for(uint64_t i = 1; i < A.size(); ++i)
  {
    A[i] = max(A[i], A[i-1]+A[i]);
    if(A[i] > max_sum){ max_sum = A[i]; }
  }
  cout << max_sum;
  return 0;
}