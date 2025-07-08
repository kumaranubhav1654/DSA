class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans, indegree(n, 0);
        queue<int>q;

        vector<vector<int>>adj(n);

        for(int i =0; i !=n; i++) {
            for(int j =0; j !=graph[i].size(); j++) {
            adj[graph[i][j]].push_back(i);
            }
        }

        for(int i =0; i !=n; i++){
            indegree[i]=graph[i].size();
        }

        for(int i =0; i !=n; i++){
            if(indegree[i]==0)
            q.push(i);
        }

        while(!q.empty()){
            auto course = q.front();
            q.pop();
            ans.push_back(course);

            for(auto a: adj[course]){
                indegree[a]--;
                if(indegree[a]==0) q.push(a);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};