#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
map<Node*, Node*>parent;
Node* start;
void dfs(Node* u, Node* p, int target){
     parent[u]=p;
     if(u->data==target){
         start=u;
     }
     if(u->left)dfs(u->left, u,target);
     if(u->right)dfs(u->right, u,target);
}
  public:
    int minTime(Node* root, int target) {
        parent.clear();
        dfs(root, NULL, target);
        queue<Node*>q;
        map<Node*,int>vis;
        q.push(start);
        vis[start]=1;
        int time = -1;
        while(!q.empty()){
            int sz = q.size();
            time++;
            for(int i=0;i<sz;i++){
                auto u=q.front();
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
        }
        
        return time;
        
    }
};