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
map<TreeNode*,TreeNode*>parent;

void dfs(TreeNode *u, TreeNode *p){
     if(!u)return;
     parent[u]=p;

     if(u->left)dfs(u->left, u);
     if(u->right)dfs(u->right,u);
}

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if(k==0){
            return {target->val};
        }
        vector<int>ans;
        parent.clear();

        dfs(root, NULL);

        queue<TreeNode*>q;
        q.push(target);
        int cur_level = 0;
        map<TreeNode*,int>vis;
        vis[target]=1;
        while(!q.empty()){
            cur_level++;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto u = q.front();
                q.pop();

                if(u->left && !vis[u->left]){
                    q.push(u->left);
                    vis[u->left]=1;
                }
                if(u->right && !vis[u->right]){
                    q.push(u->right);
                    vis[u->right]=1;
                }
                if(parent[u] && !vis[parent[u]]){
                    q.push(parent[u]);
                    vis[parent[u]]=1;
                }
            }

            if(cur_level==k){
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();

                    ans.push_back(it->val);
                }
                break;
            }
        }

        return ans;
    }
};