class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int> &color){
        vector<int> tmp = graph[i];

        for(int j = 0; j!=tmp.size(); j++){
            if(color[tmp[j]]==-1){
                color[tmp[j]]=!color[i];
                if(!dfs(tmp[j], graph, color))return false;
            }
            else if(color[tmp[j]]==color[i]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> color(m, -1);
        bool ans = true;

        for(int i = 0; i!=m; i++){
            if(color[i]==-1){
                color[i] = 1;
                ans = dfs(i, graph, color);
                if(ans == false) break;
            }
        }
        return ans;
    }
};


// BFS Solution:

// int m = graph.size();
//         vector<int> color(m, -1);

//         for (int i = 0; i != m; i++) {
//             if (color[i] == -1) {
//                 queue<pair<int, int>> q;
//                 q.push({i, 1});
//                 color[i] = 1;
//                 while (!q.empty()) {
//                     auto [node, parentColor] = q.front();
//                     q.pop();
//                     for (int i = 0; i != graph[node].size(); i++) {
//                         if (color[graph[node][i]] == -1) {
//                             q.push({graph[node][i], !parentColor});
//                             color[graph[node][i]] = !parentColor;
//                         } else if (color[graph[node][i]] == parentColor)
//                             return false;
//                     }
//                 }
//             }
//         }
//  return true;