class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // dp[i][j] = dp[i-1][j+1] && arr[i] == arr[j];

        for (int len = 1; len <= n; len++) {
            for (int left = 0; left + len - 1 < n; left++) {
                if(len ==1) continue;
                if(len==2){
                    if(left+1<n)
                    dp[left+1][left] = (s[left]==s[left+1]) ? 1 : 0;
                    continue;
                }
                int right = left + len - 1;
                if(right-1>=0 && left+1 <n)
                dp[right][left] = (dp[right-1][left+1] && s[left] == s[right]);
            }
        }
        int maxi = 0;
        string ans = "";
        for(int j=0;j<n;j++){
            for(int i= j; i < n;i++){
                if(i-j+1 > maxi && dp[i][j] ==1 ){
                    maxi = i-j+1;
                    ans = s.substr(j , i-j+1);
                }
            }
        }
        return ans; 
    }
};
