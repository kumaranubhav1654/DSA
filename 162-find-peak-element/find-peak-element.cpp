class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if((mid==0 || nums[mid]>=nums[mid-1]) 
            && (mid == nums.size()-1 || nums[mid]>=nums[mid+1]))
            return mid;
            else if(nums[mid]<=nums[mid+1]){
                start=mid+1;
            }
            else{
                end = mid-1;
            }
        } 
        return nums.size()-1;
    }
};