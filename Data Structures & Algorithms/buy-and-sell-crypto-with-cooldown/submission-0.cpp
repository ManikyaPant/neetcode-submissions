class Solution {
public:
    int maxProfit(vector<int>& arr) {
        // 0 do nothing
        //1 means sell
        //2 means buy
        int n = arr.size();
        vector < vector < int>> dp(n , vector <int>(3,0)); 
        dp[0][1] = -1e9;
        dp[0][2] = -arr[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][2] + arr[i];
            dp[i][2] = max(dp[i-1][2] , dp[i-1][0] - arr[i]);
        }
        return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

    }
};
