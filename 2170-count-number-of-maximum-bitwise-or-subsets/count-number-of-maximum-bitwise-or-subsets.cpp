class Solution {
public:
    int ans = 0;
    void helper(int indx, int xr, vector<int>& nums, int maxOr){
        if(indx==nums.size()){
            if(xr==maxOr)ans++;
            return;
        }
        
        helper(indx+1, xr|nums[indx], nums, maxOr);
        helper(indx+1, xr, nums, maxOr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto num: nums) maxOr |= num;

        helper(0, 0, nums, maxOr);
        return ans;
    }
};