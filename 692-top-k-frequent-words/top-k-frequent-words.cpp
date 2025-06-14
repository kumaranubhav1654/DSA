class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int >m;
        vector<string> ans;
        map<int, set<string>>m1;

        for(auto i: words) m[i]++;

        for(auto itr: m){
            m1[itr.second].insert(itr.first);
        }

        for(auto i = m1.rbegin(); i!= m1.rend(); i++){
            for(auto a : i->second){
            ans.push_back(a);
            if(ans.size()==k) return ans;
            }
        }

        return ans;
    }
};