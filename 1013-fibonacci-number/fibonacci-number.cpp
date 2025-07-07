class Solution {
public:
    int helper(int n, vector<int> &dp){
        if(n==0 || n==1) return n;
        if(dp[n]) return dp[n];
        return dp[n] = helper(n-1, dp)+helper(n-2, dp);
    }
    int fib(int n) {
        vector<int>dp(n+1, 0);
        return helper(n, dp);
    }
};