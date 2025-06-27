class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans;
        for (auto i : s) {
            string tmp, count;
            //int count = 0;
            if (i == ']') {
                while (st.top() != "[") {
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                cout<<tmp<<endl;
                while (!st.empty() && isdigit(st.top()[0])) {
                    count += st.top();
                    st.pop();
                }
                reverse(count.begin(), count.end());
                int c = stoi(count);
                cout<<count<<" "<<c<<endl;
                string result;
                for (int i = 0; i < c; ++i) {
                    result += tmp;
                }
                st.push(result);
            } else
                st.push(string(1, i));
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};