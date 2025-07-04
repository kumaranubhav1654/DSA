class Solution {
public:
    int dpHelper(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(i==prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            return dp[i][buy] = max((-prices[i] + dpHelper(i+1, 0, prices, dp)), 
            (0 + dpHelper(i+1, 1, prices, dp)));
        }
        else{
            return dp[i][buy] = max((prices[i] + dpHelper(i+1, 1, prices, dp)), 
            (0 + dpHelper(i+1, 0, prices, dp)));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int maxProfit = dpHelper(0, 1, prices, dp);

        return maxProfit;
    }
};

        // int maxProfit = 0, minPrice = INT_MAX; 
        // for(auto i : prices){
        //     if(minPrice > i) minPrice = i;
        //     if( i - minPrice > 0 ){
        //         maxProfit += (i - minPrice);
        //         minPrice = i;
        //     }
        // }
        // return maxProfit;