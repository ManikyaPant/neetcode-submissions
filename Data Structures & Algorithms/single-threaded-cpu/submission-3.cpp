// bool cmp()
struct custom{
 bool operator()(const pair < int, int>&a , const pair < int,int>& b)const {
    return a.second < b.second;
 }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& arr) {
        int n = arr.size();  
        vector < pair < int, int>> task(n);
        map < pair <int,int> , int> mp;
        for(int i=0;i<n;i++){
            task[i].first = arr[i][0];
            task[i].second = arr[i][1];
            mp[task[i]]  = i;
        }
        sort(task.begin() ,task.end());
        multiset < pair < int , int >, custom> st;
        vector <int> ans;
        long curr = task[0].first;
        st.insert(task[0]);
        int idx = 1;

        while(ans.size() < n){
            if(!st.empty()){
           auto t = *st.begin() ;
           curr +=  t.second;
           st.erase(st.find(t));
           ans.push_back(mp[t]);
            }
            // now push all the tasks all the tasks having first < curr
            while(idx<n){
                if(task[idx].first <= curr){
                    st.insert(task[idx]);
                    idx++;
                }
                else{
                    break;
                }

            }
            if(st.size() == 0 && idx < n){
                curr = task[idx].first;
                st.insert(task[idx]);
                idx++;
            }
        }

     return ans;
    }
};