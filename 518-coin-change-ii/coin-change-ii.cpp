class Solution {
public:
    int countWays(int amount, vector<int>& coins, int indx, vector<vector<int>> &dp){
        if(amount==0) return 1;
        else if(amount<0 || indx>=coins.size()) return 0;
        if (dp[indx][amount] != -1) return dp[indx][amount];
        
        int skip = countWays(amount, coins, indx + 1, dp);
        int take = countWays(amount - coins[indx], coins, indx, dp);

        return dp[indx][amount] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        return countWays(amount, coins, 0, dp);
    }
};