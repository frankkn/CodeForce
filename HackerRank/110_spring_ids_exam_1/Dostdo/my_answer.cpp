#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    long unsigned int n = 0; 
    long unsigned int k = 0;
    cin >> n >> k;
    
    vector<int> R(n);
    for(auto& R_i : R){  cin >> R_i; }
    
    priority_queue <int,vector<int>,greater<int>> min_heap_1;
    priority_queue <int,vector<int>,greater<int>> min_heap_2;
        
    for(long unsigned int i = 0; i < 2*k; i++){
        min_heap_1.push(R[i]);
        min_heap_2.push(R[i]);
        if(min_heap_1.size() > k){
            min_heap_1.pop();
        }
        if(i == (2*k-1)){
            cout << min_heap_1.top() << " " << min_heap_2.top() << "\n";
        }
    }
    
    for(long unsigned int i = 2*k; i < n; i++){
        min_heap_1.push(R[i]);
        min_heap_2.push(R[i]);
        min_heap_1.pop();
        min_heap_2.pop();
        cout << min_heap_1.top() << " " << min_heap_2.top() << "\n";
    }
    return 0;
}