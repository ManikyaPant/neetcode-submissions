class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int total = accumulate(arr.begin() , arr.end(), 0);
        if (abs(target) > total) return 0;

        if ((total + target) % 2 != 0) return 0;

        target = (total + target) / 2;
        // target = (total+target) /2;
        vector < vector < int>> dp(n+1, vector < int>(target+1,0));
 
        dp[n][0] = 1;
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        // dp[i][0]
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                int v1 =0 , v2=0; 
                    v1 = dp[i+1][j];
                if(j >=arr[i]){
                    v2 = dp[i+1][j-arr[i]];
                }
                dp[i][j] = v1 + v2;
            }
        }
        return dp[0][target];
       
    }
};
