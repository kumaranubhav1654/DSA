class Solution {
public:
int count = 0;
    int helper(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(m-1==i && n-1==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int c1 = 0, c2 = 0;
        if(i!=m)
        c1 = helper(m,n,i+1,j, dp);
        if(j!=n)
        c2 = helper(m,n,i,j+1, dp);
        return dp[i][j] = c1+c2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return helper(m,n,0,0, dp);
    }
};