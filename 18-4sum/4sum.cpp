class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        if(nums.size()<=3) return ans;

        for(int i = 0; i!=len-3; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j!=len-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1, z = len-1;
                while(k<z){
                    long long sumTotal = (long long)nums[i]+nums[j]+nums[k]+nums[z];
                    if(sumTotal==target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[z]});
                        k++;
                        z--;
                        while(k<z && nums[k]==nums[k-1]) k++;
                        while(k<z && nums[z]==nums[z+1]) z--;
                    } 
                    else if(sumTotal>target)z--;
                    else k++;
                }
            }
        }
        return ans;
    }
};