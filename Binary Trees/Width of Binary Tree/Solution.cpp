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

#define ll long long
class Solution {
map<int,ll>mx, mn;
void trav(auto u, int level, ll cur){
     if(!u)return;

     if(mx.count(level)){
        mx[level]=max(mx[level], cur);
        mn[level]=min(mn[level], cur);
     }
     else{
        mx[level]=cur;
        mn[level]=cur;
     }
     
     cur = cur - mn[level];
     trav(u->left, level+1, 2*cur);
     trav(u->right,level+1,2*cur+1);
}
public:
    int widthOfBinaryTree(TreeNode* root) {
        mx.clear();
        mn.clear();

        trav(root,0,0);
        ll ans = 0;
        for(auto it: mx){
            ans = max(ans, it.second - mn[it.first] + 1);
        }
        return ans;
    }
};