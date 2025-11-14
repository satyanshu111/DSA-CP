#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool is_leaf(Node* it){
    return !it->left && !it->right;
}

vector<int>leaves;
void trav(Node *root){
     if(!root)return;
     
     trav(root->left);
     if(!root->left && !root->right){
         leaves.push_back(root->data);
     }
     trav(root->right);
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
         leaves.clear();
         if(!root)return {};
         if(!root->left && !root->right)return {root->data};
         //part 1
         vector<int>ans;
         ans.push_back(root->data);
         auto cur = root->left;
         
         while(cur){
             if(!is_leaf(cur))ans.push_back(cur->data);
             if(cur->left)cur = cur->left;
             else cur=cur->right;
         }
         
         //part 3
         vector<int>temp;
         cur = root->right;
         
         while(cur){
             if(!is_leaf(cur))temp.push_back(cur->data);
             if(cur->right)cur = cur->right;
             else cur = cur->left;
         }
         
         reverse(temp.begin(),temp.end());
         
         //part 2
         trav(root);
         for(int x: leaves)ans.push_back(x);
         for(int x: temp)ans.push_back(x);
         return ans;
    }
};