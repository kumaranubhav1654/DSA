class Solution {
public:
    int helper(int indx, int amount, vector<int>& coins, vector<vector<int>> &dp, int n){
        if(indx==n){
            if(!amount) return 1;
            return 0;
        }

        if(dp[indx][amount]!=-1) return dp[indx][amount];

        int take = 0;
        int notTake = helper(indx+1, amount, coins, dp, n);
        if(amount>= coins[indx])
        take = helper(indx, amount-coins[indx], coins, dp, n);

        return dp[indx][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return helper(0, amount, coins, dp, n);
    }
};