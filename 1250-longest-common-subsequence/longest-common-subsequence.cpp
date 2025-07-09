class Solution {
public:
    // int helper(int i, int j, string text1, string text2, vector<vector<int>> &dp, int n1, int n2){
    //     if(i==n1 || j==n2) return 0;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int match = 0;
    //     if(text1[i]==text2[j])
    //     return match = 1 + helper(i+1, j+1, text1, text2, dp, n1, n2);

    //     int notMatch = max(helper(i+1, j, text1, text2, dp, n1, n2),
    //     helper(i, j+1, text1, text2, dp, n1, n2));

    //     return dp[i][j] = max(match, notMatch);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i = 0; i!=n1+1; i++){
            for(int j = 0; j!=n2+1; j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j],  dp[i][j-1]);
            }
        }

        return dp[n1][n2];
    }
};