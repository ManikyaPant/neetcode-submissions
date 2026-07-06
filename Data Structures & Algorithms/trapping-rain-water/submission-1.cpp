class Solution {
public:
    int trap(vector<int>& arr) {
    // for each need to find the next biggest on bothe sides
    int n = arr.size();
    vector< int> bigL(n,0), bigR(n,0);
    for(int i=n-2;i>=0;i--){
        bigR[i] = max(bigR[i+1], arr[i+1]) ;
    }

    for(int i=1;i<n;i++){
        bigL[i] = max(bigL[i-1], arr[i-1]);
    }
    int ans =0;
    for(int i=0;i<n;i++){
        int h = min(bigL[i] , bigR[i]);
        if(h > arr[i]){
            ans+= h-arr[i];
        }
    }
    return ans;

    }
};