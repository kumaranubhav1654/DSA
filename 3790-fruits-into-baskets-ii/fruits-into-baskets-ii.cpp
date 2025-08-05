class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        for(auto fruit : fruits){
            int j = 0;
            for(j = 0; j!=fruits.size(); j++){
                if(baskets[j]>=fruit){
                    baskets[j] = -1;
                    break;
                }
            }
            if(j==fruits.size())
            ans++;
        }
        return ans;
    }
};