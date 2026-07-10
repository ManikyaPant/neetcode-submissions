using vi = vector <int> ;
using vvi = vector < vi>;

struct UnionFind{
    vi m_root {};
    vi m_rank {};

    UnionFind(int n)
    :m_root{vi(n+1)}
    ,m_rank{vi(n+1,1)} 
    {
        for(int i=0;i<=n;i++){
            m_root[i] =i;
        }
    }

    int findset(int a){
       if(m_root[a] == a) {
            return a;
       }
       return m_root[a] = findset(m_root[a]);
    }

    void join(int u , int v){
        u = findset(u);
        v = findset(v);

        if(u==v){
            return;
        }

        if(m_rank[v] < m_rank[u]){
            // v needs to have a larger rank
            swap(v , u);
        }

        if(m_rank[v] == m_rank[u]){
            m_root[u] = v;
            m_rank[v]++;
        }

        m_root[u] = v;
    }

    
};




class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        UnionFind dsu(n);

        vector< tuple <int,int,int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int w = abs(x1-x2) + abs(y1-y2);
                edges.push_back({w,i,j});
            }
        }
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(auto [w , x, y] : edges){
            if(dsu.findset(x) != dsu.findset(y)){
                ans+= w;
                dsu.join(x,y); 
            }
        }
        return ans;
    }
};
