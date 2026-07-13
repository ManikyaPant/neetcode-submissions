class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // dp[i][j] is the lcs for t1 
        vector < vector < int>> dp(n , vector <int>(m,0));
        //if(arr[i]!=arr[j]) dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
        // if(arr[i]==arr[j]) dp[i][j] = 
        dp[n-1][m-1] = (text1[n-1] == text2[m-1]);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int v1 = 0;
                int v2 =0;
                int v3 =0;
                if(i+1 < n) v1 = dp[i+1][j];
                if(j+1<m) v2 = dp[i][j+1];
                if(i+1< n && j+1<m) v3 = dp[i+1][j+1];
                if(text1[i]!=text2[j]) {
                    dp[i][j] =  max(v1 ,v2);
                }
                else{
                    dp[i][j] =  v3 + 1;
                }
            }
        }

    return dp[0][0];
        
    
    
    }
};
