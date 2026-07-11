class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        // dp[i][0] = ways where s[i] is decoded alone
        // dp[i][1] = ways where s[i-1] and s[i] are decoded together
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {

            if (s[i] != '0') {
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
            }

            int num = (s[i-1]-'0') * 10 + (s[i]-'0');
            if (num >= 10 && num <= 26) {
                if (i == 1)
                    dp[i][1] = 1;
                else
                    dp[i][1] = dp[i-2][0] + dp[i-2][1];
            }
        }

        return dp[n-1][0] + dp[n-1][1];
    }
};