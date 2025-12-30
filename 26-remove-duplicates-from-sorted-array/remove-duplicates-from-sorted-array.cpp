class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int tmp = nums[0];
        int ans = 1;

        for(int i = 1; i!=nums.size(); i++){
            if(nums[i]<=tmp){
                int j = i;
                while(j!=nums.size() && nums[j]<=tmp){
                    j++;
                }
                if(j!=nums.size()){
                tmp = nums[j];
                swap(nums[i], nums[j]);
                ans++;
                }
            }
            else{
                tmp = nums[i];
                ans++;
            }
        }
        return ans;
    }
};