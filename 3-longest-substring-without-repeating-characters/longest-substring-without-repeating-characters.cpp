class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0, start = 0, end = 0;
        set<int> st;
        while (end != s.size()) {
            if (s.size() == 0 || st.count(s[end]) == 0){
                st.insert(s[end]);
                end++;
            }
            else {
                st.erase(s[start]);
                start++;
            }
            mx = max(mx, int(st.size()));
        }
        return mx;
    }
};