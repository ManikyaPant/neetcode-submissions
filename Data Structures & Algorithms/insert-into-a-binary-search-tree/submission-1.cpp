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

    void insert(TreeNode* root , TreeNode* ptr, int val){
        if(!root) return;
        if(val < root->val){
            // belongs in left half
            if(root->left == NULL){
                root->left = ptr;
            }
            else{
                insert(root->left, ptr ,val);
            }
        }
        else if( val >= root->val){
            // belong in right halfif(root->left == NULL){
            if(root->right == NULL)
                root->right = ptr;
            
            else{
                insert(root->right, ptr ,val);
            }
        }
    }
    

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // create the new node
        
        TreeNode* ptr = new TreeNode(val);
        if(!root){
            
            return ptr;
        }
        insert(root, ptr ,val);
        return root;
    }
};