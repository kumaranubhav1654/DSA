class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<int>& vis, int n) {
        for (int a = 0; a != n; a++) {
            if (isConnected[i][a] == 1 && !vis[a]) {
                vis[a] = 1;
                dfs(isConnected, a, vis, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;

        for (int i = 0; i != n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                count++;
                dfs(isConnected, i, vis, n);
            }
        }
        return count;
    }
};