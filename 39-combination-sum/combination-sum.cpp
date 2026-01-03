class Solution {
public:
    void helper(int indx, int len, int target, int sum, vector<int>& candidates,
                vector<vector<int>>& ans, vector<int> tmp) {
        if (indx == len || sum > target)
            return;
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(candidates[indx]);
        helper(indx, len, target, sum + candidates[indx], candidates, ans, tmp);
        tmp.pop_back();
        helper(indx + 1, len, target, sum, candidates, ans, tmp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int len = candidates.size();
        helper(0, len, target, 0, candidates, ans, tmp);
        return ans;
    }
};