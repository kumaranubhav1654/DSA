class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int j = 0;

        int len = s.length();
        int ans = 0;

        for(int i = 0; i!=len; i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[j]);
                j++;
            }

            st.insert(s[i]);
            int k = st.size();
            ans = max(ans, k);
        }
        return ans;
    }
};