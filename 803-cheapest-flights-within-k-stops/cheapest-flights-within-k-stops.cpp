class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        queue<vector<int>>pq;
        vector<int> price(n, INT_MAX);
        vector<int> stp(n);
        int ans = INT_MAX;

        for(auto i: flights){
            adj[i[0]].push_back({i[2], i[1]});
        }

        pq.push({0,src,-1});
        price[src] = 0;

        while(!pq.empty()){
            vector<int>info = pq.front();
            pq.pop();

            int cost = info[0], city = info[1], stops = info[2];
            
            if(city==dst && stops<=k) ans = min(ans, cost);

            for(int i = 0; i!=adj[city].size(); i++){
                auto [money, nxtcity] = adj[city][i];
                if(stops<k && (price[nxtcity] > cost+money || stp[nxtcity] > stops+1)){
                    pq.push({cost+money, nxtcity, stops+1});
                    price[nxtcity]=cost+money;
                    stp[nxtcity] = stops+1;
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};