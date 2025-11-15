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
map<int,pair<int,int>>mp;
void trav(auto root,int cur, int level){
     if(!root)return;
     
     if(mp.count(level)==0){
         mp[level]={level,root->val};
     }
     else{
         if(mp[level].first<cur){
             mp[level]={cur,root->val};
         }
     }
     
     trav(root->right,cur-1,level+1);
     trav(root->left,cur+1,level+1);
}
public:
    vector<int> rightSideView(TreeNode* root) {
         if(!root)return {};
        mp.clear();
        vector<int>ans;
        trav(root,0,0);
        
        for(auto it: mp){
            ans.push_back(it.second.second);
        }
        
        return ans;
    }
};