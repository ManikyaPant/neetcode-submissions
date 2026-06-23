bool cmp(pair <string, int> a, pair<string , int> b){
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector <string> str(arr.begin() ,arr.end());
        int n = str.size();
        vector < pair < string , int> > strs(n);
        set <string > st;
        for(int i=0;i<n;i++){
            sort(str[i].begin(),str[i].end());
            st.insert(str[i]);
            strs[i] = {str[i],i};
        }
        int unique = st.size();
        sort(strs.begin(), strs.end());
        vector < vector < string > > ans(unique);
        int idx =0;
        ans[0].push_back(arr[strs[0].second]);
        for(int i=1;i<n;i++){
            if(strs[i].first==strs[i-1].first){
                ans[idx].push_back(arr[strs[i].second]);
            }
            else{
                idx++;
                ans[idx].push_back(arr[strs[i].second]);
            }
        }
        return ans;
    }
};
