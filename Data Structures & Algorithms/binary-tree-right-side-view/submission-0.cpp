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
    vector<int> rightSideView(TreeNode* root) {
        // for each level take the last value , in left to right order
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
       vector < int> ans;
       for(auto vec: order){
         int last = vec[vec.size()-1];
         ans.push_back(last);
       }
       return ans;
    }
};
