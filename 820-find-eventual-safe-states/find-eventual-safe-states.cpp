class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path, vector<int> &ans){
        vis[node] = 1;
        path[node]=1;
        int flag = 1;

        int a = adj[node].size();
        for(int i = 0; i!=a; i++){
            int n = adj[node][i];
            if(!vis[n]){
                if(!dfs(n, adj, vis, path, ans)) return false;
            }
            else if(path[n]){ 
                flag = 0;
                return false;
            }
        }
        path[node] = 0;
        if(flag)
        ans.push_back(node);
        flag = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int a = graph.size();
        vector<int> ans;
        vector<int> vis(a, 0);
        vector<int> path(a, 0);

        for(int i = 0; i!=a; i++){
            if(!vis[i])
            dfs(i, graph, vis, path, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};