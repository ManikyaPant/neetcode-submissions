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
    TreeNode* solve(TreeNode* root , int targ){
        if(root->left)
        root->left = solve(root->left , targ);
        if(root->right)
        root->right = solve(root->right , targ);
        if(root->left == NULL && root->right==NULL){
            if(root->val == targ){
                return NULL;
            }
        }
        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root , target);        
    }
};