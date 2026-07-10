/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    void solve(TreeNode* root , int curr, int&ans){
        if(!root) return;
        curr++; 
        ans = max(ans , curr);
        solve(root->left , curr , ans);
        solve(root->right , curr ,ans);
    }
public:
    int maxDepth(TreeNode* root) {
       int ans = 0;
       solve(root , 0, ans); 
       return ans;
    }
};
