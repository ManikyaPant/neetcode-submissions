using vi = vector <int>;
using vvi = vector < vi>;
class Solution {
public:
    void solve(vvi&adj , vi&vis , int node){
        vis[node]=1;
        for(auto c: adj[node]){
            if(!vis[c]){
                solve(adj , vis , c);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector < vector < int>> adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vi vis(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(adj , vis , i);
                cnt++;
            }
        }
        return cnt;
    }
};
