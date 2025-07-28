class Solution {
public:
    int ans = 0;
    void helper(int indx, int xr, vector<int>& nums, int mx){
        if(indx==nums.size()){
            if(xr==mx)ans++;
            return;
        }
        
        helper(indx+1, xr|nums[indx], nums, mx);
        helper(indx+1, xr, nums, mx);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto num: nums) maxOr |= num;

        helper(0, 0, nums, maxOr);
        return ans;
    }
};