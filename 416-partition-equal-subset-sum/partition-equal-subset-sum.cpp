class Solution {
public:
    bool helper(int indx, int n, vector<int>& nums, int target, vector<vector<int>> &dp){
        if(target==0) return true;
        if(indx==n) return false;

        if(dp[indx][target]!=-1) return dp[indx][target];

        bool take=false, notTake=false;

        if(target>=nums[indx])
        take = helper(indx+1, n, nums, target-nums[indx], dp);
        
        notTake = helper(indx+1, n, nums, target, dp);

        return dp[indx][target] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;


        for(auto num: nums){
            totalSum+=num;
        }

        if(totalSum%2!=0) return false;

        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(20001, -1));

        return helper(0, n, nums, totalSum/2, dp);
    }
};