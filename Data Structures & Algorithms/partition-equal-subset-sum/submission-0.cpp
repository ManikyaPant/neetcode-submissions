class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }

        int n = nums.size();
        int target = sum / 2;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(target + 1, 0)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= target; j++) {

                bool notTake = dp[i + 1][j];

                bool take = false;

                if (nums[i] <= j) {
                    take = dp[i + 1][j - nums[i]];
                }

                dp[i][j] = take || notTake;
            }
        }

        return dp[0][target];
    }
};