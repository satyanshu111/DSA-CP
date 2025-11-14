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
map<int,vector<pair<int,int>>>mp;

void trav(auto root, int cur, int level){
     if(!root)return;

     mp[cur].push_back({level,root->val});
     if(root->left)trav(root->left, cur-1,level+1);
     if(root->right)trav(root->right,cur+1,level+1);
}
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        mp.clear();
         trav(root,0,0);
         vector<vector<int>>ans;
         for(auto it: mp){
            vector<pair<int,int>>v = it.second;
            sort(v.begin(),v.end());
            vector<int>temp;
            for(auto itt: v){
                temp.push_back(itt.second);
            }
            ans.push_back(temp);
         }

         return ans;
    }
};