class Solution {
public:
    bool isValid(int i, int j, int n) {
        return ((i >= 0 && j >= 0) && (i < n && j < n));
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        
        int n = grid.size();
        
        vector<vector<int>> vis(n, vector<int>(n, -1));

        int dx[] = {0, 0, -1, -1, -1, 1, 1, 1},
            dy[] = {-1, 1, -1, 0, 1, -1, 0, 1};

        pq.push({1, {0, 0}});

        while (!pq.empty()) {
            auto [dis, add] = pq.top();
            pq.pop();
            int i = add.first, j = add.second;
            if (i == n - 1 && j == n - 1)
                return dis;
            for (int a = 0; a != 8; a++) {
                int ni = i + dx[a], nj = j + dy[a];
                if (isValid(ni, nj, n) && grid[ni][nj] == 0 && vis[ni][nj]==-1){
                    pq.push({dis + 1, {ni, nj}});
                    vis[ni][nj] = 1;
                }
            }
        }
        return -1;
    }
};