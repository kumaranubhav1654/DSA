class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0, mn = 1;
        for(auto i : piles){
            mx=max(mx, i);
        }
        int ans = mx;
        while(mx>=mn){
            int mid = (mx+mn)/2;
            long long tmp = 0;
            for(auto i : piles){
                tmp +=  ceil(1.0 * i / mid);
            }
            if(tmp <= h){
                ans = min(ans, mid);
                mx = mid-1;
            }
            else mn = mid+1;
        }
        return ans;
    }
};