class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end =nums.size()-1, mid = 0;

        while(start<end){
            mid = (start+end)/2;
            if (nums[mid] == target)
                return mid;
            if(nums[mid]>=nums[start]){
                if(target>=nums[start] && target < nums[mid])
                end = mid-1;
                else start = mid+1;
            }
            else {
                if(target<=nums[end] && target > nums[mid])
                start = mid+1;
                else end = mid-1;
            }
        }
        if(nums[start]!=target)return -1;
        return start;
    }
};