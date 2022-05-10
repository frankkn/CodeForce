#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int post_end = 0;

int SearchRoot(vector<int>& in, int root){
    int index = 0;
    while(in[index] != root){
        index++;
    }
    return index;
}

void PrintPreOrder(vector<int>& post, vector<int>& in, int in_start, int in_end, stack<int>& s){
    if(in_start > in_end){
        return;
    }
    
    int root_index = SearchRoot(in, post[post_end--]);
    
    PrintPreOrder(post, in, root_index+1, in_end, s);//R
    PrintPreOrder(post, in, in_start, root_index-1, s);//L
    s.push(in[root_index]);//D
}

int main() {
    int n;
    cin >> n;
    post_end = n-1;
    vector<int> post(n);
    vector<int> in(n);
    for(int i = 0; i < n; ++i){
        cin >> post[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> in[i];
    }
    stack<int> s;
    PrintPreOrder(post, in, 0, n-1, s);
    while(!s.empty()){
        int data = s.top(); s.pop();
        cout << data << " ";
    }
    
    
    return 0;
}