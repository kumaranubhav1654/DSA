class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();
        vector<int> ans(len, -1);
        stack<int>st;
        unordered_map<int, int>mp;

        for(int i = 0; i!=nums2.size(); i++){
            if(st.empty() || st.top() > nums2[i]) st.push(nums2[i]);
            else{
                while(!st.empty() && st.top() < nums2[i]){
                    mp[st.top()]=nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }

        for(int i = 0; i!=nums1.size(); i++){
            if(mp.find(nums1[i]) != mp.end()) ans[i]=mp[nums1[i]];
        }

        return ans;
    }
};