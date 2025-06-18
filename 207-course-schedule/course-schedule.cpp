class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int> &path, vector<vector<int>>& pq, vector<vector<int>> &adj, int nc){
        for(int k = 0; k!=adj[i].size(); k++){
            if(!vis[adj[i][k]]){
                vis[adj[i][k]] = 1;
                path[adj[i][k]] = 1;
                if(dfs(adj[i][k], vis, path, pq, adj, nc)) return true;
            }
            else if(path[adj[i][k]]) return true;
        }
        path[i] = 0;  // This line is essential to backtrack correctly after exploring a node in DFS for cycle detection   in a directed graph.
        return false;
    }
    bool canFinish(int nc, vector<vector<int>>& pq) {
        vector<vector<int>> adj(nc);                                         
        vector<int> vis(nc, 0);

        for(int i = 0; i!=pq.size(); i++) adj[pq[i][0]].push_back(pq[i][1]);

        for(int i = 0; i!=nc; i++){
            vector<int> path(nc, 0);
            if(!vis[i]){
                if (dfs(i, vis, path, pq, adj, nc)) return false;
            }
        }
        return true;
    }
};