class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = INT_MAX; 
        for(auto i : prices){
            if(minPrice > i) minPrice = i;
            if( i - minPrice > 0 ){
                maxProfit += (i - minPrice);
                minPrice = i;
            }
        }
        return maxProfit;
    }
};