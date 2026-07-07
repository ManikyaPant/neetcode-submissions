class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque <int> dq;
        int i=0 , j=0 , n= arr.size();
        // for(int i=0;i<k-1;i++){
        //     dq.push_back(i);
        // }
        // // push the first k-1 characters
        vector <int> ans;
        while(i<n){
            while(!dq.empty() && dq.front() < i+1-k ){
            dq.pop_front();
            }
            while(!dq.empty()){
               int idx = dq.back();
               if(arr[idx] < arr[i] ){
                dq.pop_back();
               }
               else{
                break;
               }
            }
            dq.push_back(i);
            if(i>=k-1){
            cout << i << " " << dq.front();
            ans.push_back(arr[dq.front()]);
            }
            i++;


 
        }
        return ans;
    }
};
