class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return((i>=0 && j>=0) && (i<m && j<n));
    }

    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int m, int n){
        int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

        for(int k = 0; k!=4; k++){
            int newi = i+dx[k], newj= j+dy[k];
            if(isValid(newi, newj, m, n) && !vis[newi][newj] && grid[newi][newj]==1){
                vis[newi][newj]=1;
                dfs(newi, newj, vis, grid, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n , 0));
        int count = 0;

        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(i==0 || j==0 || j==n-1 || i==m-1){
                    if(grid[i][j]==1 && !vis[i][j]){
                        vis[i][j]=1;
                        dfs(i, j, vis, grid, m, n);
                    }
                }
            }
        }

        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                count++;    
                }
            }
        }
        return count;
    }
};