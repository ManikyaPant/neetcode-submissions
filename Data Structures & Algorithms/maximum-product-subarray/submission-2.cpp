class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int currMax = nums[0];
        int currMin = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            int prevMax = currMax;
            int prevMin = currMin;

            currMax = max({
                x,
                x * prevMax,
                x * prevMin
            });

            currMin = min({
                x,
                x * prevMax,
                x * prevMin
            });

            ans = max(ans, currMax);
        }

        return ans;
    }
};