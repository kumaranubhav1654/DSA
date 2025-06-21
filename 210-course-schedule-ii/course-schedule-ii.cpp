class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pq) {
        queue<int>q;
        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0; i!=pq.size(); i++){
            adj[pq[i][0]].push_back(pq[i][1]);
        }

        for(int i = 0; i!=adj.size(); i++){
            for(auto t : adj[i]) indegree[t]++;
        }

        for(int i = 0; i != numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int k = q.front();
            q.pop();
            ans.push_back(k);
            for(auto t : adj[k]){
                indegree[t]--;
                if(indegree[t]==0) q.push(t);
            } 
        }
        if(ans.size()!=numCourses) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};