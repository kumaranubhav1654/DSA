class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int target = INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[start] <= nums[mid]){
                target = min(nums[start], target);
                start = mid+1;
            } 
            else{
                target = min(nums[mid], target);
                end = mid-1;
            } 
        }
        return target;
    }
};