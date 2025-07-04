class Solution {
public:
    int helper(int indx, int buy, vector<int>& prices, int cap, vector<vector<vector<int>>> &dp){
        if(indx == prices.size() || cap == 0) return 0;
        if(dp[indx][buy][cap] != -1) return dp[indx][buy][cap];
        if(buy){
            return dp[indx][buy][cap] = max((-prices[indx] + helper(indx+1, 0, prices, cap, dp)), 
            (0 + helper(indx+1, 1, prices, cap, dp)));
        }
        else{
            return dp[indx][buy][cap] = max((prices[indx] + helper(indx+1, 1, prices, cap-1, dp)), 
            (0 + helper(indx+1, 0, prices, cap, dp)));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        int profit = helper(0, 1, prices, 2, dp);
        return profit;
    }
};