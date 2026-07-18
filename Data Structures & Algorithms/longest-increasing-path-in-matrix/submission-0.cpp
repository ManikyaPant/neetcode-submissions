class Solution {
   public:
    using vvi = vector<vector<int>>;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, int n, int m) { return i >= 0 && i < n && j >= 0 && j < m; }

    int solve(const vvi& matrix, vvi& dp, int x, int y) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int n = matrix.size();
        int m = matrix[0].size();

        // The path containing only matrix[x][y] has length 1.
        dp[x][y] = 1;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (isValid(nx, ny, n, m) && matrix[nx][ny] > matrix[x][y]) {
                dp[x][y] = max(dp[x][y], 1 + solve(matrix, dp, nx, ny));
            }
        }

        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        vvi dp(n, vector<int>(m, -1));
        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, solve(matrix, dp, i, j));
            }
        }

        return answer;
    }
};
