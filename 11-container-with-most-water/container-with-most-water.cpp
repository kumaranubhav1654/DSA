class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0, tmp = 0, i = 0, j= h.size()-1;
        while(i<j){
            tmp = min(h[i], h[j])*(j-i);
            ans = max(tmp, ans);
            if(h[i]>h[j])j--;
            else i++;
        }
        return ans;
    }
};