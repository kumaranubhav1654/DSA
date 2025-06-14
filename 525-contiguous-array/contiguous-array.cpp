class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        map<int, int>m;

        m[0] = -1;

        for(int i = 0; i!=nums.size(); i++){
            count += nums[i] ? 1 : -1;
            if(m.find(count)!=m.end()){
                ans = max(ans, i - m[count]);
            }
            else m[count] = i;
        }
        return ans;
    }
};