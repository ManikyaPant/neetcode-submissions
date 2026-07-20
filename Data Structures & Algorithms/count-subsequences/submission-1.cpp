using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
   public:
    int numDistinct(string s, string t) {
        int l = t.length();
        int n = s.length();
        // dp[i][j] num of distinct of length j ending at i
        //  dp[i][j] = summ k=0_ i-1 dp[k][k-1]
        vector<long long> dp(l + 1, 0);
        dp[0] = 1;

        for (char c : s) {
            for (int j = l; j >= 1; j--) {
                if (c == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[l];
    }
};
