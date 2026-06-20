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

string bit_rep(int num, int fixed) {
    string s(fixed, '0');

    for (int i = 0; i < fixed; i++) {
        s[fixed - i - 1] = ((num >> i) & 1) + '0';
    }

    return s;
}

int bit_to_num(const string &s) {
    int num = 0;

    for (char c : s) {
        num = (num << 1) + (c - '0');
    }

    return num;
}

class Codec {
public:
    int offset = 1000;
    int fixed = 11;          // enough for 0..2001
    int NULL_MARKER = 1001;  // outside valid node values

    map<int, string> mp;
    map<string, int> back_mp;

    Codec() {
        for (int i = -1000; i <= 1001; i++) {
            int code = i + offset;
            string rep = bit_rep(code, fixed);

            mp[i] = rep;
            back_mp[rep] = i;
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        string ans;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                ans += mp[NULL_MARKER];
                continue;
            }

            ans += mp[node->val];

            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<int> vals;

        for (int i = 0; i < (int)data.size(); i += fixed) {
            string encoding = data.substr(i, fixed);
            vals.push_back(back_mp[encoding]);
        }

        if (vals.empty() || vals[0] == NULL_MARKER)
            return nullptr;

        TreeNode* root = new TreeNode(vals[0]);

        queue<TreeNode*> q;
        q.push(root);

        int idx = 1;

        while (!q.empty() && idx < (int)vals.size()) {

            TreeNode* cur = q.front();
            q.pop();

            // left child
            if (idx < (int)vals.size() && vals[idx] != NULL_MARKER) {
                cur->left = new TreeNode(vals[idx]);
                q.push(cur->left);
            }
            idx++;

            // right child
            if (idx < (int)vals.size() && vals[idx] != NULL_MARKER) {
                cur->right = new TreeNode(vals[idx]);
                q.push(cur->right);
            }
            idx++;
        }

        return root;
    }
};