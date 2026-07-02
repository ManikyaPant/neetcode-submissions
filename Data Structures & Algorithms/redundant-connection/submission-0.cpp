using vi = vector < int> ;
using vvi = vector < vi>;
struct UnionFind{
    vi m_root;
    vi m_rank;

    UnionFind(int n)
    : m_root(n+1)
    , m_rank(n+1,1){
        iota(m_root.begin() , m_root.end(), 0);
    }

    int find_set(int v){
        if(m_root[v]==v) return v;
        return m_root[v] = find_set(m_root[v]);
    }

    void union_join(int u , int v){
        u = find_set(u);
        v = find_set(v);
        if(v == u) return;

        if(m_rank[v] < m_rank[u]){
            swap(u,v);
        }

        if(m_rank[v] == m_rank[u]){
            m_root[u] = v;
            m_rank[v]++;
            return;
        }
        
        m_root[u] = v;
    }
};




class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =0;
        for(auto vec: edges){
            n = max(n,max(vec[0],vec[1]));
        }
        UnionFind d(n+1);
        vector <int> ans;
        for(auto vec: edges){
            int u = vec[0];
            int v = vec[1];
            if(d.find_set(u)!=d.find_set(v)){
                d.union_join(u,v);
            }
            else{
                ans.push_back(u);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
