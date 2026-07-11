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
using vi = vector <int>;
class Solution {
    TreeNode* solve(vi& preorder , vi&inorder , unordered_map<int,int>&mp ,int&p_idx, int l , int r){
        if(l > r) return nullptr;
        int val = preorder[p_idx];
        p_idx++;
        int idx = mp[val];
        TreeNode* root = new TreeNode(val);

        root->left = solve(preorder , inorder , mp ,p_idx, l , idx-1);      
        root->right= solve(preorder , inorder , mp ,p_idx, idx+1 , r);      
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            //need to solve this
            int l=0, r= inorder.size(); 
            unordered_map < int , int> mp ;
            for(int i=0;i<r;i++){
                int val = inorder[i];
                mp[val]= i;
            }
            int p_idx =0;
            return solve(preorder , inorder , mp , p_idx , l , r-1);
    }
};
