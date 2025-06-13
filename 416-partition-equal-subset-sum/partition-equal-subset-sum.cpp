class Solution {
public:
    bool solve(int i, int t, vector<int>& nums, int sm,
               vector<vector<int>>& dp) {
        if (t == sm)
            return true;
        if (i >= nums.size() || t > sm)
            return false;

        if (dp[i][t] != -1)
            return dp[i][t];

        // Take
        if (solve(i + 1, t + nums[i], nums, sm, dp))
            return dp[i][t] = true;

        // Not take
        if (solve(i + 1, t, nums, sm, dp))
            return dp[i][t] = true;

        return dp[i][t] = false;
    }
    bool canPartition(vector<int>& nums) {
        int sm = 0;
        for (auto i : nums)
            sm += i;
        if (sm % 2 != 0)
            return false;
        else {
            sm = sm / 2;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int maxSum = sm + 1;
            vector<vector<int>> dp(n, vector<int>(maxSum, -1));
            return solve(0, 0, nums, sm, dp);
        }
    }
};