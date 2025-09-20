class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dis(n, INT_MAX);

        for (int i = 0; i != edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][2], edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
        }

        pq.push({0, 0});
        dis[0] = 0;

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (weight > dis[node]) continue;
            
            for (auto &[time, child] : adj[node]) {
                if (time + weight < disappear[child] && time + weight < dis[child]) {
                    pq.push({time + weight, child});
                    dis[child] = time + weight;
                }
            }
        }

        for (int i = 0; i != dis.size(); i++) {
            if (dis[i] >= disappear[i])
                dis[i] = -1;
        }

        return dis;
    }
};