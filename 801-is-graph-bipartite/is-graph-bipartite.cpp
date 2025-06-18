class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> color(m, -1);

        for (int i = 0; i != m; i++) {
            if (color[i] == -1) {
                queue<pair<int, int>> q;
                q.push({i, 1});
                color[i] = 1;
                while (!q.empty()) {
                    auto [node, parentColor] = q.front();
                    q.pop();
                    for (int i = 0; i != graph[node].size(); i++) {
                        if (color[graph[node][i]] == -1) {
                            q.push({graph[node][i], !parentColor});
                            color[graph[node][i]] = !parentColor;
                        } else if (color[graph[node][i]] == parentColor)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};