class Solution {
public:
    int uniquePaths(int m, int n) {
        vector < vector < int>> dp(m , vector < int> (n,-1));
        // 
        // dp[i][j] = dp[i+1][j] + dp[i][j+1]
        dp[m-1][n-1] = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(dp[i][j]==-1){
                   int v1 = 0  , v2 =0;
                   if(i+1<m) v1 = dp[i+1][j];
                   if(j+1 <n) v2 = dp[i][j+1];
                    dp[i][j] = v1 + v2;
                }
            }
        }
        return dp[0][0];
    }
};
