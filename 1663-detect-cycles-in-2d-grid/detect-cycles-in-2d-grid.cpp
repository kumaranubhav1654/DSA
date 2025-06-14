class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return((i>=0 && j>=0) && (i<m && j<n));
    }

    bool dfs(char val, pair<int, int>parent, int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis, int m, int n){
        int dx[] = {0,0, 1, -1}, dy[] = {1, -1, 0 ,0};

        for(int a = 0; a!=4; a++){
            int newI = i + dx[a], newJ = j+ dy[a];
            if(isValid(newI, newJ, m , n) && grid[newI][newJ]==val){
                if(!vis[newI][newJ]){
                vis[newI][newJ]= 1;
                if(dfs(val, {i, j}, newI, newJ, grid, vis, m ,n)) return true;
                }
                else if ( make_pair(newI, newJ) != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(!vis[i][j]){
                    vis[i][j]=1;
                    if(dfs(grid[i][j], {-1, -1}, i, j, grid, vis, m ,n)) return true;
                }
            }
        }
        return false;
    }
};