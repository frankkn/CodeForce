#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

vector<int>& get_key(vector<int>& curlevel, vector<int>& levelorder, vector<int>& inorder, int i_start, int i_end){
  for(int i = 1; i < levelorder.size(); ++i){
    for(int j = i_start; j <= i_end; ++j){
      if(levelorder[i] == inorder[j]){
        curlevel.emplace_back(levelorder[i]);
      }
    }
  }
  return curlevel;
}

TreeNode* dfs(vector<int>& levelorder, vector<int>& inorder, int i_start, int i_end){
  if(i_start > i_end)  return nullptr;

  TreeNode* root = new TreeNode(levelorder[0]);
  if(i_start == i_end)  return root;

  int i = i_start;
  while(inorder[i] != levelorder[0])  ++i;

  vector<int> leftlevel, rightlevel;
  leftlevel = get_key(leftlevel, levelorder, inorder, i_start, i-1);
  rightlevel = get_key(rightlevel, levelorder, inorder, i+1, i_end);

  root->left = dfs(leftlevel, inorder, i_start, i-1);
  root->right = dfs(rightlevel, inorder, i+1, i_end);
  return root;
}

map<int, pair<TreeNode*, TreeNode*>>& traverse(TreeNode* root, map<int, pair<TreeNode*, TreeNode*>>& m){
  if(root)  m[root->val] = {root->left, root->right};
  if(root->left)  traverse(root->left, m);
  if(root->right) traverse(root->right, m);
  return m;
}

int main(){
  int n;
  cin >> n;
  vector<int> levelorder(n);
  for(auto& l_i: levelorder)  cin >> l_i;
  vector<int> inorder(n);
  for(auto& i_i: inorder)  cin >> i_i;
  TreeNode* root = dfs(levelorder, inorder, 0, n-1);
  map<int, pair<TreeNode*, TreeNode*>> m;
  traverse(root, m);
  for(auto& [x, y]: m){
    if(y.first){
      cout << y.first->val << " ";
      if(y.second){
        cout << y.second->val << endl;
      }else{
        cout << "0\n";
      }
    }else{
      cout << "0 ";
      if(y.second){
        cout << y.second->val << endl;
      }else{
        cout << "0\n";
      }
    }
  }

  return 0;
}