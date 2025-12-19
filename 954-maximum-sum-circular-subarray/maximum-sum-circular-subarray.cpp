class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0], totalSum = 0, tmpMax = 0, globalMin = nums[0], tmpMin = 0;

        for(int i = 0; i!=nums.size(); i++){
            tmpMax = max(tmpMax+nums[i], nums[i]);
            tmpMin = min(tmpMin+nums[i], nums[i]);
            totalSum += nums[i];
            globalMax = max(globalMax, tmpMax);
            globalMin = min(globalMin, tmpMin);
        }

        if(globalMax<0) return globalMax;
        return max(globalMax, totalSum - globalMin);
    }
};