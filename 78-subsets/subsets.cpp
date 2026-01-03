class Solution {
public:
    void helper(int indx, int len,vector<int> tmp,vector<vector<int>> &ans, vector<int>& nums){
        if(indx==len){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[indx]);
        helper(indx+1, len, tmp, ans, nums);
        tmp.pop_back();
        helper(indx+1, len, tmp, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        helper(0, nums.size(), tmp, ans, nums);
        return ans;
    }
};