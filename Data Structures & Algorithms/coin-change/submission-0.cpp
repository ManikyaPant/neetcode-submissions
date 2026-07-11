class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       int INF = 1e9;
       vector < vector < int >> dp(n , vector <int> (amount+1,INF)); 
       for(int i=0;i<n;i++){
        dp[i][0] = 0;
       }

      for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j <= amount; j++) {
        int v1 = INF, v2 = INF;

        if (i + 1 < n)
            v1 = dp[i + 1][j];

        if (j >= coins[i] && dp[i][j - coins[i]] != INF)
            v2 = dp[i][j - coins[i]] + 1;

        dp[i][j] = min(v1, v2);
    }
}

return dp[0][amount] == INF ? -1 : dp[0][amount];
    }
};
