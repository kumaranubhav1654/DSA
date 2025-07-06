class Solution {
public:
    vector<int> ans;
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>>& graph, vector<int> &isSafe) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto i : graph[node]) {
            if (!vis[i]) {
                if(dfs(i, vis, pathVis, graph, isSafe)) return true;
            } else if (pathVis[i]) {
                return true;
            }
        }
        pathVis[node] = 0;
        isSafe[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> isSafe(n, 0);

        for (int i = 0; i != n; i++) {
            if (!vis[i]) {
                dfs(i, vis, pathVis, graph, isSafe);
            }
        }

        for (int i = 0; i < n; i++) {
            if (isSafe[i]) {
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};