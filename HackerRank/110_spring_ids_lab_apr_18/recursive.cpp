#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void preOrder(vector<vector<int>>& graph, int root);
void inOrder(vector<vector<int>>& graph, int root);
void postOrder(vector<vector<int>>& graph, int root);
void levelOrder(vector<vector<int>>& graph, int root);
int findRoot(vector<vector<int>>& graph);


int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1,vector<int>(2,0)); // node num from 0 to n
    int x, y, op;
    while(cin >> x >> y >> op){
        if(op == 0){
            graph[x][0] = y;
        }else{
            graph[x][1] = y;
        }
    }
    int root = findRoot(graph);
    preOrder(graph, root);cout<<"\n";
    inOrder(graph, root);cout<<"\n";
    postOrder(graph, root);cout<<"\n";
    levelOrder(graph, root);
    return 0;
}

int findRoot(vector<vector<int>>& graph){
    vector<int> nodes(graph.size(), 0);
    for(vector<std::vector<int>>::size_type i = 0; i < graph.size(); ++i){
        nodes[graph[i][0]] = 1;
        nodes[graph[i][1]] = 1;
    }
    int root = 0;
    for(vector<std::vector<int>>::size_type i = 0; i < nodes.size(); ++i){
        if(nodes[i] == 0){
            root = i;
        }
    }
    return root;
}

void preOrder(vector<vector<int>>& graph,int root){
    if(root == 0){
        return;
    }
    cout << root << " ";
    preOrder(graph, graph[root][0]);
    preOrder(graph, graph[root][1]);
}

void inOrder(vector<vector<int>>& graph,int root){
    if(root == 0){
        return;
    }
    inOrder(graph, graph[root][0]);
    cout << root << " ";
    inOrder(graph, graph[root][1]);
}

void postOrder(vector<vector<int>>& graph,int root){
    if(root == 0){
        return;
    }
    postOrder(graph, graph[root][0]);
    postOrder(graph, graph[root][1]);
    cout << root << " ";
}

void levelOrder(vector<vector<int>>& graph,int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();q.pop();
        cout << cur << " ";
        if(graph[cur][0]){
            q.push(graph[cur][0]);
        }
        if(graph[cur][1]){
            q.push(graph[cur][1]);
        }
    }
}