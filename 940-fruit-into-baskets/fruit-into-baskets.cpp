class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int ans = 0, tmp = 0;
        int j = 0;
        for (int i = 0; i != fruits.size(); i++) {
            mp[fruits[i]]++;
            while(mp.size()>2){
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0)mp.erase(fruits[j]);
                j++;
                tmp--;
            }
            tmp++;
            ans = max(tmp, ans);
        }
        return ans;
    }
};