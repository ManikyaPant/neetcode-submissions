using vvi = vector < vector <int>>;
using vi = vector<int>;
#define INF 1e9

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector < vector < pair <int,int>>> adj(n+1);
        for(auto vec: times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({w, v});
        }       

        vi dis(n+1, INF);
        dis[k] = 0;
        set < pair <int,int>> st; 
        st.insert({0,k});
        while(!st.empty()){
            auto [c_d , node] = *st.begin();
            st.erase(st.find({c_d ,node}));
            for(auto [w , u]: adj[node]){
                int new_d = c_d + w;
                if(dis[u] > new_d) {
                    if(st.find({dis[u], u})!=st.end()){
                        st.erase({dis[u], u});
                    }
                    dis[u] = new_d;
                    st.insert({dis[u], u});
                }
            }
        }
        int ans = 0;
    for(int i=1;i<=n;i++){
        if(i==k) continue;
        ans = max(ans ,dis[i] );
    }
    if(ans == INF) return -1;
    return ans;
    }
    
};
