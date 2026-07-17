class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        // Store the last occurrence of each character
        vector<int> last_occur(26);
        for (int i = 0; i < n; i++) {
            last_occur[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int size = 0;
        int last = 0;

        for (int i = 0; i < n; i++) {
            last = max(last, last_occur[s[i] - 'a']);

            size++;

            if (i == last) {
                ans.push_back(size);
                size = 0;
            }
        }

        return ans;
    }
};