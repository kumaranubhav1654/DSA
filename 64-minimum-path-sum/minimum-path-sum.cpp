class Solution {
public:
    int helper(int m, int n, int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i==m-1 && j==n-1) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];

        int c1 = INT_MAX, c2 = INT_MAX;
        if(i+1< m)
        c1 = grid[i][j] + helper(m,n,i+1,j, dp, grid);
        if(j+1< n)
        c2 = grid[i][j] + helper(m,n,i,j+1, dp, grid);

        return dp[i][j] =  min(c1, c2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(m,n,0,0, dp, grid);
    }
};