#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int pre_start = 0;

int SearchRoot(vector<int>& in, int root){
    int index = 0;
    while(in[index] != root){
        index++;
    }
    return index;
}

void PrintPostOrder(vector<int>& pre, vector<int>& in, int in_start, int in_end){
    if(in_start > in_end){
        return;
    }
    
    int root_index = SearchRoot(in, pre[pre_start++]);
    
    PrintPostOrder(pre, in, in_start, root_index-1);//L
    PrintPostOrder(pre, in, root_index+1, in_end);//R
    cout << in[root_index] << " ";//D
}

int main() {
    int n;
    cin >> n;
    vector<int> pre;
    vector<int> in;
    for(int i {}; i < n; ++i){
        int v;
        cin >> v;
        pre.push_back(v);
    }
    
    in = pre;
    sort(in.begin(), in.end());
    
    for(auto v:in){
       cout << v << " "; 
    }
    cout << "\n";
    PrintPostOrder(pre, in, 0, n-1);
    
    return 0;
}
