class Solution {
public:
    int helper(int indx, int target, vector<int> &nums, vector<vector<int>> &dp, int n, int offset){
        if (target + offset < 0 || target + offset > 2 * offset) return 0; 
        if(indx==n){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[indx][target+ offset]!=-1) return dp[indx][target+ offset];

        int negative = helper(indx+1, target-nums[indx], nums, dp, n, offset);
        int positive = helper(indx+1, target+nums[indx], nums, dp, n, offset);
        
        return dp[indx][target+ offset] = positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // Target out of achievable range
        if (abs(target) > sum) return 0;

        vector<vector<int>>dp(n+1, vector<int>(2*sum+1, -1));
        int ans = helper(0, target, nums, dp , n, sum);
        return ans;
    }
};