class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(!n) return true;
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i!=n; i++){
            auto a = prerequisites[i];
            adj[a[1]].push_back(a[0]);
        }

        queue<int>q;
        vector<int>indegree(numCourses);

        for(int i = 0; i!=numCourses; i++){
            for(auto a: adj[i]){
                indegree[a]++;
            }
        }

        for(int i = 0; i!=numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }

        int count = 0;

        while(!q.empty()){
            auto node = q.front();
            count++;
            q.pop();

            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }

        if(numCourses==count)return true;
        else return false;
    }
};