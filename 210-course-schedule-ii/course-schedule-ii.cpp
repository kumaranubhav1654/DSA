class Solution {
public:
    bool dfs(int indx, vector<vector<int>>& adj, vector<int>& path, vector<int>& vis, vector<int>& ans) {
        vis[indx] = 1;
        path[indx] = 1;
        
        for (auto t: adj[indx]) {
            if (!vis[t]){
                if(dfs(t, adj, path, vis, ans)) return true; 
            }
            else if (vis[t] && path[t])
                return true;
        }

        path[indx] = 0;
        ans.push_back(indx);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> path(numCourses, 0);
        vector<int> vis(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto i : prerequisites)
            adj[i[0]].push_back(i[1]);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]){
                if (dfs(i, adj, path, vis, ans)) return {};
            }
        }
        return ans;
    }
};