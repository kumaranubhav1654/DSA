class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = 0, sell = 0;
        for(int i = 0; i!=prices.size(); i++){
            if(prices[i]<prices[buy]){
                buy = i;
            } 
            if(prices[buy]<prices[i]){
                sell = i;
                profit=max(profit, prices[sell]-prices[buy]);
            }
        }
        return profit;
    }
};