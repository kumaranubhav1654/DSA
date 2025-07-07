class Solution {
public:
int count = 0;
    int helper(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(j==n || i==m) return 0;
        if(m-1==i && n-1==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = helper(m,n,i+1,j, dp)+helper(m,n,i,j+1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return helper(m,n,0,0, dp);
    }
};