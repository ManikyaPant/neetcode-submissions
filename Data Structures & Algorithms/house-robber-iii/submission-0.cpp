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
public:
    void solve(TreeNode* root , unordered_map <TreeNode*,int>&c0 , unordered_map<TreeNode*,int>&c1){
        if(!root) return;
        int val = root->val;
        c1[root] = val;
        solve(root->right, c0 , c1) ;
        solve(root->left, c0 ,c1);
        // case we don't take it
        if(root->right){
            c0[root] += max(c0[root->right],c1[root->right]);
            c1[root] += c0[root->right];
        }
        if(root->left){
            c0[root] += max(c0[root->left],c1[root->left]);
            c1[root] += c0[root->left];
        }
    }
    int rob(TreeNode* root) {
        // standarad dp problem 
        unordered_map <TreeNode* ,int> mp0 , mp1;
        solve(root , mp0 , mp1);
        return max(mp0[root] , mp1[root]);
    }
};