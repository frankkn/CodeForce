#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void Print_kth_smallest(vector<uint64_t>& A, uint64_t& k)
{
    priority_queue<uint64_t> max_heap;
    uint64_t i {};
    while(i < k)
    {
        max_heap.push(A[i++]);
    }
    cout << max_heap.top() << " ";
    while(i < A.size())
    {
        max_heap.push(A[i++]);
        max_heap.pop();
        cout << max_heap.top() << " ";
    }
}

int main() {
    uint64_t n {};
    cin >> n;
    uint64_t k {};
    cin >> k;
    vector<uint64_t> A(n);
    for(auto& A_i : A){ cin >> A_i; }
    Print_kth_smallest(A, k);
    return 0;
}