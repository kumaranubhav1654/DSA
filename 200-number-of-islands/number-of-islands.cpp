class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return ((x>=0 && y>=0)&&(x<m && y<n));
    }
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis, int m , int n){
        int dx[]={0,0,1,-1}, dy[]={-1,1,0,0};
        for(int a = 0; a!=4; a++){
            int ni = i+dx[a], nj= j+dy[a];
            if(isValid(ni, nj, m ,n)){
            if(grid[ni][nj] == '1' && !vis[ni][nj]){
                vis[ni][nj] = 1;
                dfs(ni, nj, grid, vis, m, n);
            }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    vis[i][j] = 1;
                    dfs(i, j, grid, vis, m, n);
                }
            }
        }
        return count;
    }
};