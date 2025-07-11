class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans;
        int m = str1.size(), n= str2.size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1, -1));

        for(int i = 0; i!=m+1; i++){
            for(int j = 0; j!=n+1; j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
                else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i = m, j = n;
        while(i!=0 && j!=0){
            if(str1[i-1]==str2[j-1]) {
                ans+=str1[i-1];
                i--; j--;
            }
            else if(dp[i][j-1] > dp[i-1][j]){
                ans+=str2[j-1];
                j--;
            }
            else{
                ans+=str1[i-1];
                i--;
            }
        }
        
        while(i > 0) ans += str1[i-- -1];
        while(j > 0) ans += str2[j-- -1];

        reverse(ans.begin(), ans.end());
        return ans;
    }
};