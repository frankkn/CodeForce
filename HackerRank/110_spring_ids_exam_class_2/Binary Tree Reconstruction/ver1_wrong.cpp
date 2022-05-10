#include <iostream>
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

void PrintPreOrder(vector<int>& post, vector<int>& in, int in_start, int in_end){
    if(in_start > in_end){
        return;
    }
    
    int root_index = SearchRoot(in, post[post_end--]);
    
    cout << in[root_index] << " ";//D
    PrintPreOrder(post, in, in_start, root_index-1);//L
    PrintPreOrder(post, in, root_index+1, in_end);//R
}

int main() {
    int n;
    cin >> n;
    post_end = n-1;
    vector<int> post;
    vector<int> in;
    for(int i {}; i < n; ++i){
        int v;
        cin >> v;
        post.push_back(v);
    }
    for(int i {}; i < n; ++i){
        int v;
        cin >> v;
        in.push_back(v);
    }
    
    PrintPreOrder(post, in, 0, n-1);
    
    return 0;
}