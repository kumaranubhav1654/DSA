class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int>q;
        vector<int> ans;

        for(int i = 0; i!=prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        for(int i = 0; i!=numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);

            for(auto i : adj[course]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }

        if(ans.size()==numCourses){
            reverse(ans.begin(), ans.end());
            return ans;
        } 
        return {};
    }
};