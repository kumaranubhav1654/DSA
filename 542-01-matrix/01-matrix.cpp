class Solution {
public:
bool isValid(int x, int y, int m, int n){
  return ((x>=0 && y>=0)&&(x<m && y<n));  
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<tuple<int, int, int>> q;

        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                if (!vis[i][j] && mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto [x, y, step] = q.front();
                q.pop();
                int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
                for (int j = 0; j != 4; j++) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if (isValid(nx, ny, m, n) && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        mat[nx][ny] = step + 1;
                        q.push({nx, ny, step + 1});
                    }
                }
            }
        }
    return mat;
    }
}
;