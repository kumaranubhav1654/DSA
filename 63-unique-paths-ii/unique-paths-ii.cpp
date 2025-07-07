class Solution {
public:
   int helper(int m, int n, int i, int j, vector<vector<int>> &dp, vector<vector<int>>& ob){
        if(j==n || i==m) return 0;
        if(ob[i][j]) return 0;
        if(m-1==i && n-1==j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int c1, c2 = 0;
        c2 = helper(m,n,i,j+1, dp, ob);
        c1 = helper(m,n,i+1,j, dp, ob);

        return dp[i][j] = c1+c2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return helper(m,n,0,0, dp, obstacleGrid);
    }
};