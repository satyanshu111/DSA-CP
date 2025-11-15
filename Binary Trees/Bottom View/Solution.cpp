#include<bits/stdc++.h>
using namespace std;

// The only difference between top view and bottom view is in this we have to update map when map[cur]<=level;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
map<int,pair<int,int>>mp;
void trav(auto root,int cur, int level){
     if(!root)return;
     
     if(mp.count(cur)==0){
         mp[cur]={level,root->data};
     }
     else{
         if(mp[cur].first<=level){
             mp[cur]={level,root->data};
         }
     }
     
     trav(root->left,cur-1,level+1);
     trav(root->right,cur+1,level+1);
}
  public:
    vector<int> bottomView(Node *root) {
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