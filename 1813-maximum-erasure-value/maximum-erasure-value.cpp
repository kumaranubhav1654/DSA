class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> st;
        int ans = INT_MIN, tmp = 0;
        int j = 0;

        for(int i = 0; i!=nums.size() && j<=i; i++){
                while(st.find(nums[i])!=st.end()){
                    st.erase(nums[j]);
                    tmp-=nums[j];
                    j++;
                }
                tmp+=nums[i];
                st.insert(nums[i]);
                ans=max(tmp, ans);
            }
            cout<<tmp<<endl;
        
        return ans;
    }
};


// if(prefixSum.find(nums[i])==prefixSum.end()){
//                 tmp+=nums[i];
//                 prefixSum[nums[i]] = tmp;
//             }
//             else{
//                 tmp-=prefixSum[nums[i]];
//                 tmp+=nums[i];
//                 prefixSum[nums[i]] = tmp;
//             }