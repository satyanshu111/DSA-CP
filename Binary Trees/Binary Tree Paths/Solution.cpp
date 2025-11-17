#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
vector<string>paths;
void dfs(TreeNode* u, string &cur){
     if(!u){
        return;
     }
     int old_sz = cur.size();

     if(!cur.empty())cur+= "->";
     cur += to_string(u->val);

     if(!u->left && !u->right){
        paths.push_back(cur);
     }
     else{
        dfs(u->left, cur);
        dfs(u->right, cur);
     }

     cur.resize(old_sz);
     
}
public:
    vector<string> binaryTreePaths(TreeNode* root) {
          string cur="";
          paths.clear();

          dfs(root, cur);
          return paths;
    }
};