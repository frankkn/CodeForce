#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int postIndex = 0;

int search(vector<int> in, int data,int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        if (in[i] == data)
            return i;
    return i;
}

void fillPre(vector<int> in, vector<int> post, int inStrt,
            int inEnd, stack<int> &s,int n)
{
    if (inStrt > inEnd)
        return;
 
    int val = post[postIndex];
    int inIndex = search(in, val, n);
    postIndex--;
 
    fillPre(in, post, inIndex + 1, inEnd, s, n);
    fillPre(in, post, inStrt, inIndex - 1, s, n);
    s.push(val);
}

void printPreMain(vector<int> in, vector<int> post,int n)
{
    int len = n;
    postIndex = len - 1;
    stack<int> s ;
    fillPre(in, post, 0, len - 1, s, n);
    while (s.size() > 0)
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int n;
    cin >> n;

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
    
    printPreMain(in, post, n);
    return 0;
}
