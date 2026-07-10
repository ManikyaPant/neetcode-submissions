class Solution {
    int solve(vector<int>& arr, int start, int end) {
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = end; i >= start; i--) {

            dp[i][0] = max(
                dp[i + 1][0],
                dp[i + 1][1]
            );

            dp[i][1] = arr[i] + dp[i + 1][0];
        }

        return max(dp[start][0], dp[start][1]);
    }

public:
    int rob(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) {
            return arr[0];
        }

        int excludeLast = solve(arr, 0, n - 2);
        int excludeFirst = solve(arr, 1, n - 1);

        return max(excludeLast, excludeFirst);
    }
};