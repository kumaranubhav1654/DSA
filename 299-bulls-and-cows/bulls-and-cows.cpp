class Solution {
public:
    string getHint(string s, string g) {
        vector<int>v(10, 0);
        int b = 0, c = 0;
        string ans;

        for(int i = 0; i!=s.length(); i++){
            if(s[i]==g[i]){
                b++;
            }
            else
            v[s[i]-'0']++;
        }
        for(int i = 0; i!=s.length(); i++){
            if(s[i] != g[i] && v[g[i]-'0']!=0){
                c++;
                v[g[i]-'0']--;
            }
        }
        ans = to_string(b) + "A" + to_string(c) + "B";
        return ans;
    }
};