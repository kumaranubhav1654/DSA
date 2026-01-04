class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()-1, mid = 0;

        if(nums.size()==1) return nums[0];

        while(start<end){
            mid = (start+end)/2;
            if(mid%2!=0) mid--;
            if(nums[mid]==nums[mid+1])
                start = mid+2;
            else
                end = mid;
        }
        return nums[start];
    }
};