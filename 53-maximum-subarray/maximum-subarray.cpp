class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int j = 0, tmpSum = 0, sum = nums[0];
        for(int i = 0; i!=nums.size(); i++){
            tmpSum+=nums[i];
            sum=max(sum, tmpSum);
            if(tmpSum<0)
                tmpSum = 0;
        }
        return sum;
    }
};