class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i != flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][2], flights[i][1]});
        }

        int ans = INT_MAX;

        vector<pair<int, int>> cities(n, {INT_MAX, INT_MAX});

        pq.push({0, 0, src});

        while (!pq.empty()) {
            auto [cost, stopsTaken, currCity] = pq.top();
            pq.pop();

            if (currCity == dst) ans = min(ans, cost);

            for (int i = 0; i != adj[currCity].size(); i++) {
                auto [price, desCity] = adj[currCity][i];

                if(cities[desCity].first < price+cost && cities[desCity].second < stopsTaken) continue;
                else{
                    cities[desCity].first = min(cities[desCity].first,  price+cost);
                    cities[desCity].second = min (cities[desCity].second, stopsTaken+1);
                }

                if(stopsTaken <= k){
                    pq.push({cost + price, stopsTaken + 1, desCity});
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};