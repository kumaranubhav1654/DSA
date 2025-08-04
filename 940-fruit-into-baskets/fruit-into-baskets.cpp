class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>m;
        int ans = 0, tmp = 0;
        int i = 0, j = 0;
        while(j!=fruits.size()){
            m[fruits[j]]++;
            while(m.size()>2){
                m[fruits[i]]--;
                if(m[fruits[i]]==0) m.erase(fruits[i]);
                i++;
                tmp--;
            }
            j++;
            tmp++;
            ans = max(tmp,ans);
        }
        return ans;
    }
};