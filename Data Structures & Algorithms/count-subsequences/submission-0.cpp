using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
   public:
    int numDistinct(string s, string t) {
        int l = t.length();
        int n = s.length();
        // dp[i][j] num of distinct of length j ending at i
        //  dp[i][j] = summ k=0_ i-1 dp[k][k-1]
        vector<vector<int>> dp(n, vi(l + 1, 0));
        if (s[0] == t[0]) dp[0][1] = 1;

        if (t.empty()) return 1;
        if (s.empty() || t.length() > s.length()) return 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == t[0]) {
                dp[i][1] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 2; j <= l; j++) {
                if (s[i] == t[j - 1]) {
                    int val = 0;
                    for (int k = 0; k <= i - 1; k++) {
                        val += dp[k][j - 1];
                    }
                    dp[i][j] += val;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[i][l];
        }
        return ans;
    }
};
