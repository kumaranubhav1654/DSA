class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sm = 0;
        int n = nums.size();
        sm = (n*(n+1))/2;
        for(auto i : nums){
            sm -= i;
        }
        return sm;
    }
};