class Solution {
public:
    void helper(int indx, int sum,  vector<int>& nums, vector<vector<int>> &ans, vector<int> tmp, int target, int n){
        if(sum==target) ans.push_back(tmp);
        if(indx==n || sum>target) return;
        
        for(int j = indx; j!=n; j++){
            if(j>indx && nums[j]==nums[j-1]) continue;
            tmp.push_back(nums[j]);
            helper(j+1, sum+nums[j], nums, ans, tmp, target, n);
            tmp.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        helper(0, 0, candidates, ans, tmp, target, n);
        return ans;
    }
};