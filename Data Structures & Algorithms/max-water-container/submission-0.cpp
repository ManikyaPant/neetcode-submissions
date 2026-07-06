class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0 , j= n-1;
        int ans =0;
        while(i<j){
            int h1 = arr[i];
            int h2 = arr[j];
            int water = (j-i)*(min(h1,h2));
            ans = max(ans , water);
            if(arr[i]< arr[j]){
                i++;
            }
            else if(arr[i]> arr[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return ans;
    }
};
