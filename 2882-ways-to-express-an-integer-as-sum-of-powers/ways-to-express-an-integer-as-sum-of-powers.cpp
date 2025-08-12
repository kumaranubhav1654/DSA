class Solution {
public:
    const int MOD = 1e9 + 7;
    int helper(int p, int n, int x, vector<vector<int>>& dp) {
        if (n < 0)
            return 0;
        if (p == 0) {
            if (n == 0)
                return 1;
            return 0;
        }
        if (dp[p][n] != -1)
            return dp[p][n];
        int tmp = pow(p, x);

        int take = helper(p - 1, n - tmp, x, dp);
        int notTake = helper(p - 1, n, x, dp);

        dp[p][n] = (take + notTake) % MOD;
        return dp[p][n];
    }
    int numberOfWays(int n, int x) {
        int p = ceil(pow(n, 1.0 / x));
        if (p <= 1)
            return 1;
        vector<vector<int>> dp(p + 1, vector<int>(n + 1, -1));
        return helper(p, n, x, dp);
    }
};