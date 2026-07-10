class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
       vector <int> dp(n+1,0); 
        dp[n] = 1; 
        for (int i = n - 1; i >= 0; i--) {
        for (string& str : wordDict) {
            int l = str.length();

            if (i + l <= n &&
                s.substr(i, l) == str &&
                dp[i + l]) {

                dp[i] = 1;
                break;
            }
        }
    }

    return dp[0];
    }
};
