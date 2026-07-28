class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();

        // Extra space lets us safely access dp[i + 1] ... dp[i + 6]
        vector<int> dp(n + 7, 0);

        for (int i = n - 1; i >= 0; i--) {
            int v1 = arr[i] +
                     min({dp[i + 2], dp[i + 3], dp[i + 4]});

            int v2 = INT_MIN;
            if (i + 1 < n) {
                v2 = arr[i] + arr[i + 1] +
                     min({dp[i + 3], dp[i + 4], dp[i + 5]});
            }

            int v3 = INT_MIN;
            if (i + 2 < n) {
                v3 = arr[i] + arr[i + 1] + arr[i + 2] +
                     min({dp[i + 4], dp[i + 5], dp[i + 6]});
            }

            dp[i] = max({v1, v2, v3});
        }

        int alice = dp[0];
        int total = accumulate(arr.begin(), arr.end(), 0);
        int bob = total - alice;

        if (alice > bob) {
            return "Alice";
        }

        if (bob > alice) {
            return "Bob";
        }

        return "Tie";
    }
};