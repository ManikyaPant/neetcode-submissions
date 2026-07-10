using vi = vector <int>;
using vvi = vector <vi>;

bool ok(int mid , vvi&grid){
    int n = grid.size();
    vvi vis(n, vi(n,0));
    int dx[4] = {-1, 1 , 0 , 0};
    int dy[4] = {0 , 0 , -1 , 1};
    queue <pair <int,int>> q;
    if(grid[0][0] <=mid){
    q.push({0,0});
    vis[0][0] = 1;
    }
    while(!q.empty()){
        auto [x ,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny] && grid[nx][ny] <=mid){
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    // cout << mid << " " << vis[n-1][n-1] << endl;
    return vis[n-1][n-1];
}

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int l = 1 , r = 1e9;
       int ans = -1;
       while(l<=r){
        int mid = (r+l)/2;
        cout << mid << endl;
        if(ok(mid, grid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
       } 
       return ans;
    }
};
