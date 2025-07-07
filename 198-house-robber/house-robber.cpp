class Solution {
public:
    int helper(vector<int>& nums, int indx, int pick, int n, vector<vector<int>> &dp) {
        if (indx == n) return 0;
        
        if(dp[indx][pick]!=-1)return dp[indx][pick];

        int sumPick = 0;

        if (pick) sumPick = nums[indx] + helper(nums, indx + 1, 0, n, dp);

        int notpick = helper(nums, indx + 1, 1, n, dp);

        return dp[indx][pick] =  max(sumPick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return helper(nums, 0, 1, n, dp);
    }
};