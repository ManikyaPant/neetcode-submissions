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
    int depth(TreeNode* root ){
        if(!root) return 0;
        int l =  depth(root->left);
        int r = depth(root->right);
        return max(l, r) + 1;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
       int lvl = depth(root);
       vector < vector < int >> order(lvl);
    
       queue < TreeNode*> q;
       q.push(root);
       int idx =0;
       while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            auto node = q.front();
            q.pop();
            order[idx].push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        idx++;
       }
       return order;
    }
};
