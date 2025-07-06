class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph, vector<int> &tmp, int n){
        int l = tmp.back();
        if(l==n-1) ans.push_back(tmp);
        for(int i = 0; i!=graph[l].size(); i++){
            tmp.push_back(graph[l][i]);
             dfs(graph, tmp, n);
             tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> tmp;
        tmp.push_back({0});
        dfs(graph, tmp, graph.size());
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>> ans;
//         queue<vector<int>> q;
//         int n = graph.size();
//         q.push({0});

//         while (!q.empty()) {
//             auto a = q.front();
//             q.pop();
//             int len = a.size();
//             int last = a.back();
//             if (last == n-1) {
//                     ans.push_back(a);
//                     continue;
//             }
//             for (int j = 0; j != graph[last].size(); j++) {
//                 vector<int> tmp = a;
//                 tmp.push_back(graph[last][j]);
//                 q.push(tmp);
//             }
//         }
//         return ans;
//     }
// };