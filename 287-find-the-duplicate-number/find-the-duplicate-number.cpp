class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, len = nums.size();
        while(len!=-1){
            if(nums[i]<0) return i;
            else{
                int tmp = nums[i];
                nums[i] = -1;
                i=tmp;
            }
        }
        return -1;
    }
};