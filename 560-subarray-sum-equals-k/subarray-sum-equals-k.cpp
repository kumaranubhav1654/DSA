class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int count = 0;

        int prefixSum = 0;
        m[0]++;

        for(auto n : nums){
            prefixSum+=n;
            if(m.find(prefixSum-k)!=m.end())count+=m[prefixSum-k];
            m[prefixSum]++;
        }
        return count;
    }
};