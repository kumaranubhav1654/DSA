class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        int n = graph.size();
        q.push({0});

        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            int len = a.size();
            int last = a.back();
            if (last == n-1) {
                    ans.push_back(a);
                    continue;
            }
            for (int j = 0; j != graph[last].size(); j++) {
                vector<int> tmp = a;
                tmp.push_back(graph[last][j]);
                q.push(tmp);
            }
        }
        return ans;
    }
};