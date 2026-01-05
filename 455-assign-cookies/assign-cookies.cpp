class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int gstart = 0;
        int istart = 0;

        while(gstart!=g.size() && istart!=s.size()){
            if(g[gstart]<=s[istart]){
                ans++;
                gstart++;
                istart++;
            }
            else istart++;
        }
        return ans;
    }
};