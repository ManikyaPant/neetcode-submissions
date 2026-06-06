class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // maintain a set of size k , if the value is greater than 
        multiset <int , greater <int>> st ;
        for(auto it: nums){
            st.insert(it);
            if(st.size()>k){
                int val = *st.rbegin();
                st.erase(st.find(val));
            }
        }
        return *(st.rbegin());
    }
};
