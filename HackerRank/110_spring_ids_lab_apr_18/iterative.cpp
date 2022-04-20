#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
void preOrder(vector<vector<int>>& graph, int& root, vector<int>& order);
void inOrder(vector<vector<int>>& graph, int& root, vector<int>& order);
void postOrder(vector<vector<int>>& graph, int& root, vector<int>& order);
void levelOrder(vector<vector<int>>& graph, int& root, vector<int>& order);

ostream& operator << (ostream& out, vector<int>& order){
    if(!order.empty()){
        auto it = order.begin();
        out << *it++;
        while(it != order.end()){
            out << " " << *it++;
        }
    }
    out << "\n";
    return out;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1,vector<int>(2));
    vector<int> in_degree(n+1);
    for(int i {1}; i != n; ++i){
        int from, to, is_right;
        cin >> from >> to >> is_right;
        graph[from][is_right] = to;
        ++in_degree[to];
    }
    
    int root = 0;
    for(int i {1}; i <= n; ++i){
        if(in_degree[i] == 0){
            root = i;
        }
    }
    vector<int> order;
    for(auto Order: {preOrder, inOrder, postOrder, levelOrder}){
        order.clear();
        Order(graph, root, order);
        cout << order;
    }
    
    return 0;
}

void preOrder(vector<vector<int>>& graph, int& root, vector<int>& order){
    stack<int> st;
    st.push(root);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        order.push_back(node);
        if(graph[node][1] != 0){//push right child first
            st.push(graph[node][1]);
        }
        if(graph[node][0] != 0){//afterwards, push left child 
            st.push(graph[node][0]);
        }
    }
}

void inOrder(vector<vector<int>>& graph, int& root, vector<int>& order){
    stack<int> st;
    int node = root;
    while(true){
        if(node != 0){
            st.push(node);
            node = graph[node][0];
        }else{
            if(st.empty())  break;
            node = st.top();
            st.pop();
            order.push_back(node);
            node = graph[node][1];
        }
    }
}

void postOrder(vector<vector<int>>& graph, int& root, vector<int>& order){
    stack<int> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        int node = st1.top();
        st1.pop();
        st2.push(node);
        if(graph[node][0]){
            st1.push(graph[node][0]);
        }
        if(graph[node][1]){
            st1.push(graph[node][1]);
        }
    }
    while(!st2.empty()){
        int node = st2.top();
        st2.pop();
        order.push_back(node);
    }
}

void levelOrder(vector<vector<int>>& graph, int& root, vector<int>& order){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        order.push_back(node);
        if(graph[node][0]){
            q.push(graph[node][0]);
        }
        if(graph[node][1]){
            q.push(graph[node][1]);
        }
    }
}