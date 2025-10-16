class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int size = temp.size();
        vector<int>ans(size, 0);
        stack<pair<int, int>>st;

        for(int i = size-1; i!=-1; i--){
            while(!st.empty() && st.top().first<=temp[i]) st.pop();
            if(st.empty())ans[i] = 0;
            else ans[i] = st.top().second - i;

            st.push({temp[i], i});
        }
        return ans;
    }
};