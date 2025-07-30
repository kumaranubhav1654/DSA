class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx_num = INT_MIN;

        for(auto num: nums)mx_num = max(mx_num, num);

        int n = nums.size(), ans = 0, tmp = 0;

        for(int i = 0; i<n; i++){
            if(nums[i]==mx_num) tmp++;
            else tmp = 0;
            ans= max(ans, tmp);
        }
        return ans;
    }
};