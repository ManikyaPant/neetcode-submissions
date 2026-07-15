class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum =0;
        int ans =0;
        bool positive = false;
        for(int i=0;i<arr.size();i++){
            if(arr[i] >=0) positive = true || positive;
            if(arr[i]+ sum >=0){
                sum+=arr[i];
            }
            else{
                sum = 0;

            }

            ans = max(ans , sum);
        }
        if(!positive) {
            ans = -1e9;
            for(auto it: arr) ans = max(ans , it);
        }
        return ans;
    }
};
