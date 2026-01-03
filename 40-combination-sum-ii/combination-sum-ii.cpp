class Solution {
public:
    void helper(int indx, int len, int sum, int &target, vector<int>& candidates, vector<vector<int>> &ans, vector<int> tmp){
        if(sum==target){
            ans.push_back(tmp);
            return;
        }

        if(indx>=len || sum>target) return;
        tmp.push_back(candidates[indx]);
        helper(indx+1, len, sum+candidates[indx], target, candidates, ans, tmp);
        tmp.pop_back();
        
        int next = indx+1;
        while(next < len && candidates[indx]==candidates[next]) next++;

        helper(next, len, sum, target, candidates, ans, tmp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp; 
        sort(candidates.begin(), candidates.end());
        int len = candidates.size();
        helper(0, len, 0, target, candidates, ans, tmp);
        return ans;
    }
};