class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector < int> pre(n),suff(n);
        int mult = 1;
        pre[0]=1;
        suff[n-1]=1;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]*arr[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]*arr[i+1];
        }


        vector < int> ans(n);
        for(int i=0;i<n;i++){
            
                ans[i] = pre[i]*suff[i];
            
        }
    return ans;
    }
};
