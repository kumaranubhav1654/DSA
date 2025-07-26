class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = INT_MIN;
        set<int>st;
        for(int i = 0; i!=nums.size(); i++){
            if(sum<0 && nums[i]>sum) sum=nums[i];
            else if(st.find(nums[i])==st.end() && nums[i]>0){
               if(sum>0) sum+=nums[i];
               else sum = nums[i];
            } 
            st.insert(nums[i]);
        }
        return sum;
    }
};