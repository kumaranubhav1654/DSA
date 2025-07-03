class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] != i)
            parent[i] = find(parent[i], parent);
        return parent[i];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> size(n, 1);
        vector<int> parent(n);
        int ans = 0;

        for (int i = 0; i != n; i++)
            parent[i] = i;

        for (int i = 0; i != n; i++) {
            for (int j = 0; j != n; j++) {
                if (isConnected[i][j] == 1) {
                    int pi = find(i, parent);
                    int pj = find(j, parent);
                    if (pi == pj)
                        continue;
                    if(size[pi] < size[pj]){
                        parent[pi] = pj;
                        size[pj] += size[pi];
                    } else {
                        parent[pj] = pi;
                        size[pi] += size[pj];
                    }
                }
            }
        }

        for (int i = 0; i != n; i++) {
            if (parent[i] == i)
                ans++;
        }

        return ans;
    }
};

// Using DFS:

// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& adj, vector<int> &vis){
//         vis[node]=1;
//         for(auto it: adj[node]){
//             if(!vis[it])
//             dfs(it, adj, vis);
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int v = isConnected.size();

//         vector<vector<int>> adj(v);
//         for(int i = 0; i !=v; i++){
//             for(int j = 0; j !=v; j++){
//                 if(isConnected[i][j]==1 && i!=j){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }

//         vector<int> vis(v, 0);
//         int provinces = 0;

//         for(int i = 0; i!=v; i++){
//             if(vis[i]==0){
//                 provinces++;
//                 dfs(i, adj, vis);
//             }
//         }
//         return provinces;
//     }
// };