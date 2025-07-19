class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>>pq;
        map<int, int>mp;

        for(int i = 0; i!=nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto i = mp.begin(); i!=mp.end(); i++){
            pq.push({i->second, i->first});

            if(pq.size()>k)pq.pop();
        }

        while(!pq.empty()){
            auto [a, b] = pq.top();
            pq.pop();
            ans.push_back(b);
        }
        return ans;
    }
};