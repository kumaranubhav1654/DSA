class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int mid = (start+end)/2;

        if(nums.size()==1) return nums[0];

        while(start<end){
            mid = (start+end)/2;
            cout<<mid<<endl;
            if(mid%2==0){
                if(nums[mid]!=nums[mid+1])
                end = mid;
                else
                start = mid+1;
            }
            else{
                if(nums[mid]!=nums[mid+1])
                start = mid+1;
                else
                end = mid;
            }
        }
        if(mid==nums.size()-1 || mid == 0 || (nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])) return nums[mid];
        else if(nums[mid]!=nums[mid+1] && nums[mid]==nums[mid-1])
        return nums[mid+1];
        else return nums[mid-1];
    }
};