class Solution {
public:
    int helper(int indx, int canBuy, vector<int>& prices, int n, vector<vector<int>> &dp, int fee){
    if(indx>=n)
        return 0;
    int buy = 0, sell = 0;

    if(dp[indx][canBuy]!=-1) return dp[indx][canBuy];

    if(canBuy) buy = max(-prices[indx]+ helper(indx+1, 0, prices, n, dp, fee),
                        helper(indx+1, 1, prices, n, dp, fee));

    else sell = max(prices[indx] - fee + helper(indx+1, 1,  prices, n, dp, fee),
                                        helper(indx+1, 0, prices, n, dp, fee));


    return dp[indx][canBuy] = max(buy, sell);
    }

    int maxProfit(vector<int>& prices, int fee) {
       int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, n, dp, fee); 
    }
};
