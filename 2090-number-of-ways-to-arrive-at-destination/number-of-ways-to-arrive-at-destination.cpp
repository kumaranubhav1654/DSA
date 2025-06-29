class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<int, long long>>>adj(n);
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int>ways(n, 0);
        vector<long long>time(n, LLONG_MAX);

        for(auto i : roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        } 

        pq.push({0,0});
        time[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long parentTime = pq.top().first;
            int des = pq.top().second;
            pq.pop();

            for(int i = 0; i!=adj[des].size(); i++){
                auto [subDes, Time] = adj[des][i];
                if( time[subDes] > (parentTime + Time)){
                    pq.push({ parentTime + Time, subDes});
                    ways[subDes] =  ways[des]; // replace not add.
                    time[subDes] = parentTime + Time;
                }
                else if(time[subDes] == parentTime + Time){
                    ways[subDes] =  (ways[subDes] + ways[des]) % MOD; // needs to be MOD here 
                }
            }
        }
        return ways[n-1]% MOD;
    }
};