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

int ans = 0;
class Solution {
    int dfs(TreeNode* node){
        if(!node) return 0;
        int left_gain = max(0,dfs(node->left));
        int right_gain = max(0, dfs(node->right));

        int val = left_gain+right_gain+ node->val;

        ans = max(ans , val);
        return node->val+max(left_gain , right_gain);
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};
