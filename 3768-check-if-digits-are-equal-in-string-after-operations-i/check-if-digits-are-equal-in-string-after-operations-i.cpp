class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()!=2){
            int i = 1;
            string t = "";
            while(i!=s.length()){
                //cout<<s[i-1]<<" "<<s[i]<<endl; //s[i] is a character, so int(s[i]) gives the ASCII code('5' = 53).
                int tmp = ((s[i-1]-'0')+(s[i]-'0'))%10;
                //cout<<tmp<<endl;
                i++;
                t += to_string(tmp);
            }
            s = t;
        }
        return (s[0]==s[1]);
    }
};