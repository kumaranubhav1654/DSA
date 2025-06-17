class Solution {
public:
    void helper(vector<string>& ans, int n, int open, int close, string tmp) {
        if (tmp.length() == 2*n){ ans.push_back(tmp);}
        
        if(open < n)helper(ans, n, open+1, close, tmp+"(");
        
        if (close < open) helper(ans, n, open, close+1, tmp+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0, close = 0;
        string tmp;
        helper(ans, n, open, close, tmp);
        return ans;
    }
};