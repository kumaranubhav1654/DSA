class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return ((x >= 0 && y >= 0) && (x < m && y < n));
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis, int m, int n) {

        int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

        for (int k = 0; k != 4; k++) {
            int newx = i + dx[k], newy = j + dy[k];
            if (isValid(newx, newy, m, n) && board[newx][newy] == 'O' && !vis[newx][newy]) {
                vis[newx][newy] = 1;
                dfs(newx, newy, board, vis, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int dx[] = {0, m, 0, n}, dy[] = {1, -1, 0, 0};
        for (int i = 0; i != n; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                vis[0][i] = 1;
                dfs(0, i, board, vis, m, n);
            }
        }
        for (int i = 1; i != m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                vis[i][0] = 1;
                dfs(i, 0, board, vis, m, n);
            }
        }
        if (m > 1) {
            for (int i = 0; i != m; i++) {
                if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                    vis[i][n - 1] = 1;
                    dfs(i, n - 1, board, vis, m, n);
                }
            }
        }
        if (n > 1) {
            for (int i = 0; i != n; i++) {
                if (board[m - 1][i] == 'O' && !vis[m - 1][i]) {
                    vis[m - 1][i] = 1;
                    dfs(m - 1, i, board, vis, m, n);
                }
            }
        }

        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
            }
        }
        }
    };