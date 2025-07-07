class Solution {
public:
    int helper(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n){
        if(j1 < 0 || j2 < 0 || j1 > n-1|| j2 > n-1) return INT_MIN;
        
        if(i == m-1){
            if(j1==j2)
            return grid[i][j2];
            else return grid[i][j2]+grid[i][j1];;
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int dx[] = {-1, 0, 1};
        int cherry = INT_MIN;

        for(int a = 0; a!=3; a++){
            for(int b = 0; b!=3; b++){
                if(j1==j2)
                cherry = max(cherry , helper(i+1, j1+dx[a], j2+dx[b], grid, dp, m, n));
                else
                cherry = max(cherry , helper(i+1, j1+dx[a], j2+dx[b], grid, dp, m, n));
            }
        }
        if (j1 == j2)
            dp[i][j1][j2] = grid[i][j1] + cherry;
        else
            dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + cherry;

        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(0, 0, n-1, grid, dp, m, n);
    }
};