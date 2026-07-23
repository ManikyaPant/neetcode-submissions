struct UnionFind{
    public:
    vector <int> rank , parent;

    UnionFind(int n ) 
     : rank{vector < int>(n+1,0)}
     , parent{vector < int> (n+1)}
     {
        for(int i =0; i<=n;i++){
            parent[i] = i;
        }
     }

    int find_set(int n){
        if(parent[n]==n) return parent[n];
        else 
        return parent[n] = find_set(parent[n]);
    }

    void unite(int a , int b){
        a = find_set(a);
        b = find_set(b);
        if(a==b) return ;
        if(rank[a] < rank[b]){
            swap(a, b);
        }
        if(rank[a] == rank[b]){
            parent[b]=a;
            rank[a]++;
        }
        else{
            parent[b]=a;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // build the adjacency list 
        int n = points.size();
        int num_edge = n*(n-1)/2;
        vector <tuple<int , int , int>> edges;
        for(int i=0;i<n;i++){
            for(int j =i+1 ; j< n ;j++){
                int x1 , y1 , x2 , y2;
                x1 = points[i][0];
                y1 = points[i][1];
                x2 = points[j][0];
                y2 = points[j][1];
                // auto [x1,y1]= points[i];
                // auto [x2 , y2 ] = points[j];
                int d = abs(x1-x2) + abs(y1-y2);

                edges.push_back({d , i , j});
            }
        }
        sort(edges.begin() , edges.end());
        int ans = 0;
        UnionFind Dsu(n);
        for(auto [d , i , j] : edges){
            if(Dsu.find_set(i) == Dsu.find_set(j)) continue;
            else {
                Dsu.unite(i , j);
                ans +=d;
            }
        }
        return ans;
    }
};