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
    int ans;
    int calc(TreeNode* root) {
        if (!root) return 0;

        int lft = calc(root->left);
        int rgt = calc(root->right);

        int temp = 0;
        if (lft >= 0) temp += lft;
        if (rgt >= 0) temp += rgt;

        int best = max(0, max(lft, rgt));

        ans = max(ans, temp + root->val);
        return best + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        calc(root);
        return ans;
    }
};
