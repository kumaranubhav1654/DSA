class Solution {
public:
    int helper(string s, string rs, int n, vector<vector<int>> &dp){
        int count = 0;

        for(int i = 0; i!=n+1; i++){
            for(int j = 0; j!=n+1; j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(s[i-1]==rs[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                } 
                else {
                    dp[i][j]= max(dp[i-1][j],  dp[i][j-1]);
                }
                count = max(count, dp[i][j]);
            }
        }

        return count;
    }
    int minInsertions(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return s.length()-helper(s, rs, n, dp);
    }
};