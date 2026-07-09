using vi  = vector <int>;
using vvi = vector <vi > ;

class Solution {
public:
    int dx[4] = {-1, 1 , 0 ,0};
    int dy[4] = {0 , 0 , -1 , 1};
    void dfs(vector<vector < char>>& adj , int x , int y , int n , int m ,vvi&vis){
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x +dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx < n && ny<m && !vis[nx][ny]){
                if(adj[nx][ny] == '1') dfs(adj , nx , ny , n , m , vis);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector < vector < int>> vis(n , vector <int>(m,0)); 
       int ans = 0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == '1'){
                dfs(grid, i , j , n , m , vis);
                ans++;
            }
        }
       }
        return ans;
    }
};
