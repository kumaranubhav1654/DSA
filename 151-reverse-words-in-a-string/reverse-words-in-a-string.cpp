class Solution {
public:
    string reverseWords(string s) {
        string tmp;
        stack<string>st;
        for(int i = 0; i!=s.length(); i++){
            if(s[i]==' '){
                if(tmp.length() == 0)continue;
                else{
                    st.push(tmp);
                    tmp = "";
                }
            }
            else{
                tmp=tmp+s[i];
            }
        }
        if(tmp.length())st.push(tmp);
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty())
            ans+=' ';
        }
        return ans;
    }
};