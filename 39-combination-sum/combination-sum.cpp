class Solution {
public:
    void helper(int indx, int sum,  vector<int>& nums, vector<vector<int>> &ans, vector<int> tmp, int target, int n){
        if(indx==n){
            if(sum==target) ans.push_back(tmp);
            return;
        }

        if(sum<target){
            tmp.push_back(nums[indx]);
            helper(indx, sum+nums[indx], nums, ans, tmp, target, n);
            tmp.pop_back();
        }
        helper(indx+1, sum, nums, ans, tmp, target, n);

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = candidates.size();
        helper(0, 0, candidates, ans, tmp, target, n);
        return ans;
    }
};