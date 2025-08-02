class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int sz = basket2.size()*2;
        map<int, int> mp1;
        vector<int> merge;
        int gmin = INT_MAX;
        long long ans = 0;

        for (int i = 0; i != basket1.size(); i++) {
            mp1[basket1[i]]++;
            mp1[basket2[i]]--;
            gmin = min(gmin, min(basket2[i], basket1[i]));
        }

        for (auto itr = mp1.begin(); itr != mp1.end(); itr++) {
            if (itr->second % 2 != 0)
                return -1;
            for (int i = 0; i < abs(itr->second) / 2; ++i) {
                merge.push_back(itr->first);
            }
        }
        int n = merge.size() / 2;

        sort(merge.begin(), merge.end());

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(2 * gmin, merge[i]);
        }
        return ans;
    }
};