class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmpAns = 0;
        int ans = INT_MIN;
        for(int i = 0; i!=nums.size(); i++){
            tmpAns += nums[i];
            ans = max(tmpAns, ans);
            if(tmpAns < 0)
            tmpAns = 0;
        }
        return ans;
    }
};