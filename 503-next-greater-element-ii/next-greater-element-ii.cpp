class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int> ans(nums.size(), 0);
        for(int i = nums.size()-1; i!=-1; i--){
            int tmp = nums[i];
            if(st.empty())
                ans[i] = INT_MIN;
            else{
                while(!st.empty() && nums[i]>=st.top()) st.pop();
                if(st.empty()) ans[i] = INT_MIN;
                else  ans[i] = st.top();
            }
            //cout<<ans[i]<<" "<<nums[i]<<endl;
            st.push(tmp);
        }

        for(int i = nums.size()-1; i!=-1; i--){
            if(ans[i]==INT_MIN){
                while(!st.empty() && nums[i]>=st.top()) st.pop();
                if(st.empty()) ans[i] = -1;
                else  ans[i] = st.top();
            }
        }

        return ans;
    }
};