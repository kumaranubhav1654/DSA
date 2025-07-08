class Solution {
public:
    int helper(int indx, int amount, vector<int> &coins, vector<vector<int>> &dp, int n){
        if(indx==n){
            if(amount == 0) return 0;
            return 1e8;
        }
        
        if(dp[indx][amount]!=-1) return dp[indx][amount];
        
        int notTake = helper(indx+1, amount, coins, dp, n);
        int take = INT_MAX;
        if(amount>=coins[indx]) take = 1 + helper(indx, amount-coins[indx], coins, dp, n);
        
        return dp[indx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = helper(0, amount, coins, dp , n);
        return (ans!=1e8) ? ans : -1;
    }
};