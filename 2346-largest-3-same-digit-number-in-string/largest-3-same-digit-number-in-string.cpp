class Solution {
public:
    string largestGoodInteger(string num) {
        string ans, tmp;
        tmp = num[0];

        for(int i = 1; i!=num.length(); i++){
            if(tmp[0]==num[i] && (!ans.length() || tmp[0]>ans[0])){
                tmp+=num[i];
                if(tmp.length()==3) ans=tmp;
            }
            else
            tmp=num[i];
        }
        return ans;
    }
};