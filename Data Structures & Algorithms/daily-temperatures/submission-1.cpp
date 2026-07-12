class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //finding the index of the next greatest integer
        int n = temperatures.size();
        stack <int> st;
        vector <int> ans(n); 
        for(int i=n-1;i>=0;i--){
            int val = temperatures[i];
            while(!st.empty()){
                if(temperatures[st.top()] <= val){
                    st.pop();
                }
                else{
                    break;
                }
            }
            if(st.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = st.top() - i ;
            }
            st.push(i);
        }
        return ans;
    }
};
