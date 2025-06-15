class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int,int> map;

        int n=nums2.size();

        for(int i=n-1;i>=0;i--){
            if(!st.empty() && st.top()>nums2[i]){
                // st.pop();
                // st.push(nums2[i]);
                map[nums2[i]] = st.top();
            }else{
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                map[nums2[i]] = !st.empty() ? st.top(): -1;
            }
            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            ans.push_back(map[nums1[i]]);
        }

        return ans;
    }
};