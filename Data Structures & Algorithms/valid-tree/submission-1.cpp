class Solution {
public:
    void dfs(vector < vector <int>>&adj , vector <int>&vis , int node){
        vis[node]=1;
        for(auto c: adj[node]){
            if(!vis[c]){
                dfs(adj, vis , c);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector <vector <int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    vector < int> vis(n,0);
    dfs(adj , vis , 0);
    // if anyone is not visited return false
    return accumulate(vis.begin(),vis.end(),0) == n ? true : false; 
    }
};
