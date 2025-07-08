class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, vis(numCourses), indegree(numCourses, 0);
        queue<int>q;
        vector<vector<int>>adj(numCourses);

        for(auto courses : prerequisites) adj[courses[1]].push_back(courses[0]);

        for(int i =0; i !=numCourses; i++){
            for(int j = 0; j!=adj[i].size(); j++) indegree[adj[i][j]]++;
        }

        for(int i =0; i !=numCourses; i++){
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

        if(ans.size()==numCourses) return ans;
        return {};
    }
};