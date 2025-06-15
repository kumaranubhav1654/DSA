class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(2*n, -1);
        vector<int> ans;
        stack<int> st;
        int count = 2;
        while(count--){
            for(int i=n-1;i>=0;i--){
                if(!st.empty() && st.top()>nums[i]){
                    temp[count*n +i] = st.top();
                }else{
                    while(!st.empty() && st.top()<=nums[i]){
                        st.pop();
                    }
                    if(!st.empty())
                        temp[count*n +i] =st.top();
                    else
                        temp[count*n +i] = -1;
                }
                st.push(nums[i]);
            }
        }

        for(int i=0;i<n;i++) ans.push_back(temp[i]);
        return ans;
    }
};