class Solution {
public:
    int dp(int n, vector<int> &ways){
        if(n==1) return 1;
        if(n==2) return 2;
        if(ways[n]) return ways[n];

        return ways[n] = dp(n-1, ways)+dp(n-2, ways);
    }
    int climbStairs(int n) {
        vector<int> ways(n+1, 0);
        return dp(n, ways);
    }
};