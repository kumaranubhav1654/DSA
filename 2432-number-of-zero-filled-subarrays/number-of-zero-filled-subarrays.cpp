class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long tmp = 0;
        for(int i = 0; i!=nums.size(); i++){
            if(nums[i]==0)tmp++;
            else{
                ans+=(tmp*(tmp+1))/2;
                tmp = 0;
            }
        }
        ans+=(tmp*(tmp+1))/2;
        return ans;
    }
};