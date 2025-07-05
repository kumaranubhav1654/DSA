class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i!= nums.size()+1; i++){
            if(nums[k]<0) return k;
            nums[k]= -nums[k];
            k = -nums[k];
        }
        return 0;
    }
};