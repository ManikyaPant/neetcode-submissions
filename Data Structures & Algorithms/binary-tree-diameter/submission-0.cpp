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
    int solve(TreeNode* root, int &ans){
        if(!root) return 0;
        int left = 0 , right = 0;
        left = solve(root->left,ans);
        right = solve(root->right,ans);
        // l + r + 1
        ans = max(ans , left+ right + 1);
        return max(left, right)+1;
        

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // fore each node , we can find if it's the diameter
        int ans = 0;
        solve(root , ans );
        return ans-1;
    }
};
