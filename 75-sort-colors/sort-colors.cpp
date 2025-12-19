class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size()-1, i =0;
        while (i <= end) {
            if(nums[i]==1)i++;
            else if(nums[i]==0){
                nums[i] = nums[start];
                nums[start] = 0;
                start++;
                i++;
            }
            else{
                nums[i] = nums[end];
                nums[end] = 2;
                end--;
            }
        }
    }
};