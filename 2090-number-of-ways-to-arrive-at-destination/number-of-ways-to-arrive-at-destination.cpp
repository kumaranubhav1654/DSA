class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>>adj(n);
        int countWays = 0;
        vector<long long>dis(n, LLONG_MAX);
        vector<int>ways(n, 0);

        for(auto i : roads){
            adj[i[0]].push_back({i[2], i[1]});
            adj[i[1]].push_back({i[2], i[0]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;

        pq.push({0, 0});
        dis[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            auto [wt, src] = pq.top();
            pq.pop();

            for(auto i : adj[src]){
                auto [cwt, des] = i;
                if(dis[des] > wt+cwt){
                    ways[des] = ways[src];
                    dis[des] = wt+cwt;
                    pq.push({wt+cwt, des});
                }
                else if(dis[des] == wt+cwt){
                    ways[des]= (ways[des] + ways[src])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};