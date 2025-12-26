class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i = 0; i!=nums.size(); i++){
            st.insert(nums[i]);
        }
        int ans = 0, tmp = 0;
        for(int i = 0; i!=nums.size(); i++){
            if(st.find(nums[i]-1) != st.end()) continue;
            else {
                int k = 0;
                while(st.find(nums[i]+k) != st.end()){
                    tmp++;
                    st.erase(nums[i]+k);
                    k++;
                }
            }
            ans = max(ans, tmp);
            tmp = 0;
        }
        return ans;
    }
};