class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {

        vector<pair<int,int>> arr;

        for(int i = 0; i < profits.size(); i++) {
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());

        multiset<int> st;

        int idx = 0;
        int n = arr.size();

        for(int take = 0; take < k; take++) {

            while(idx < n && arr[idx].first <= w) {
                st.insert(arr[idx].second);
                idx++;
            }

            if(st.empty()) break;

            auto it = prev(st.end()); // largest profit
            w += *it;
            st.erase(it);
        }

        return w;
    }
};