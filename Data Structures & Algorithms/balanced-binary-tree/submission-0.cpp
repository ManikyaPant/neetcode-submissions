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
    int solve(TreeNode* root, bool&ans){
        if(!root) return 0;
        int size = 1;
        int size_l = solve(root->left ,ans);
        int size_r = solve(root->right , ans);
        size += max(size_l , size_r);
        ans = ans && (abs(size_l -size_r)<=1);
        return size;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root , ans);
        return ans; 
    }
};
