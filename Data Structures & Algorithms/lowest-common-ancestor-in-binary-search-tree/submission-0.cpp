class Solution {
    bool path(
        TreeNode* root,
        TreeNode* target,
        vector<TreeNode*>& arr
    ) {
        if (!root) {
            return false;
        }

        if (root == target) {
            arr.push_back(root);
            return true;
        }

        if (path(root->left, target, arr) ||
            path(root->right, target, arr)) {

            arr.push_back(root);
            return true;
        }

        return false;
    }

public:
    TreeNode* lowestCommonAncestor(
        TreeNode* root,
        TreeNode* p,
        TreeNode* q
    ) {
        vector<TreeNode*> p1;
        vector<TreeNode*> p2;

        path(root, p, p1);
        path(root, q, p2);

        int i = p1.size() - 1;
        int j = p2.size() - 1;

        TreeNode* ans = nullptr;

        while (i >= 0 && j >= 0 && p1[i] == p2[j]) {
            ans = p1[i];
            i--;
            j--;
        }

        return ans;
    }
};