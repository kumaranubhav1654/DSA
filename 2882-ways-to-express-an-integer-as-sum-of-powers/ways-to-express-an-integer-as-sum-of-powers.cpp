class Solution {
public:
    const int MOD = 1e9 + 7;
    int helper(int num, int n, int x, vector<vector<int>>& dp) {
        if (n < 0)
            return 0;
        if (num == 0) {
            if (n == 0)
                return 1;
            return 0;
        }
        if (dp[num][n] != -1)
            return dp[num][n];
        int tmp = pow(num, x);

        int take = helper(num - 1, n - tmp, x, dp);
        int notTake = helper(num - 1, n, x, dp);

        dp[num][n] = ((long long)take + notTake) % MOD;
        return dp[num][n];
    }
    int numberOfWays(int n, int x) {
        int ans = 0, tmp = n;
        int num = ceil(pow(tmp, 1.0 / x));
        if (num <= 1)
            return 1;
        vector<vector<int>> dp(num + 1, vector<int>(n + 1, -1));
        return helper(num, tmp, x, dp);
    }
};