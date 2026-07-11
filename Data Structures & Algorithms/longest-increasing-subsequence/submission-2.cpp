class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
       int n = arr.size(); 
      //dp[i]  be the longest ending sequence ending at i 
      vector <int> dp(n,1);
       dp[0] = 1;
       for(int i=1;i<n;i++){
        for(int j=0;j<=i-1;j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i] , dp[j]+1);
            }
        }
       }
       int ans =0;
       for(int i=0;i<n;i++){
        cout << i << " " << dp[i] << endl;
        ans = max(ans , dp[i]);
       }
       return ans;
    }
};
