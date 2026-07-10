class Solution {
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        if (p->val != q->val) return false;

        return isSame(p->left, q->left) &&
               isSame(p->right, q->right);
    }

    bool solve(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (isSame(root, subRoot)) {
            return true;
        }

        return solve(root->left, subRoot) ||
               solve(root->right, subRoot);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};