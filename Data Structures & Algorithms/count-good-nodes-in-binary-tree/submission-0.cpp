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
    int dfs(TreeNode* root, int min_so_far){
        if(!root) return 0;
        // store the minimum so far
        if(root->val >= min_so_far){
            ans++;
            min_so_far = root->val;
        }
        dfs(root->left,min_so_far);
        dfs(root->right,min_so_far);
    return 0;

    }
public:
    int goodNodes(TreeNode* root) {
        ans = 0;
        dfs(root , -101);
        return ans;
    }
};
