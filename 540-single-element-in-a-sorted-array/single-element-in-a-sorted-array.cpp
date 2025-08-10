class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        if(start==end) return nums[end];
        while(start<=end){
            int mid = (start+end)/2;
            if((mid==0 || nums[mid-1]!=nums[mid]) && (mid==nums.size()-1 || nums[mid+1]!=nums[mid]))
            return nums[mid];
            else if(nums[mid-1]==nums[mid]){
                if(mid%2!=0)
                start= mid+1;
                else
                end = mid-1;
            }
            else{
                if((mid)%2!=0)
                end = mid-1;
                else
                start= mid+1;
            }
        } 
        return -1;
    }
};