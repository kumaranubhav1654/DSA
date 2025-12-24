class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int arrSize = nums.size();
        int i = arrSize-2; 
        while(i!=-1){
            if(nums[i]<nums[i+1]) break;
            i--;
        }
        if(i==-1) sort(nums.begin(), nums.end());
        else{
            int j = arrSize - 1, tmp = INT_MAX, k = 0;
            while(j!=i){
                if(nums[i]<nums[j] && tmp>nums[j]){
                    tmp = nums[j];
                    k = j;
                } 
                j--;
            }
            swap(nums[i], nums[k]);
            sort(nums.begin()+i+1, nums.end());
        }
    }
};