class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int offset = 1000;

        vector<int> fre(2001, 0);

        for (int x : nums)
            fre[x + offset]++;

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (int i = 0; i < 2001; i++) {
            int freq = fre[i];

            if (freq > 0) {
                int val = i - offset;
                bucket[freq].push_back(val);
            }
        }

        vector<int> ans;

        for (int i = n; i >= 1 && ans.size() < k; i--) {
            while (!bucket[i].empty() && ans.size() < k) {
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
            }
        }

        return ans;
    }
};