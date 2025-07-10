class Solution {
public:
    bool isValid(int i , int j, int n){
        return ((i>=0 && j>=0) && (j<n && i<n));
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0) return -1;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
        vector<vector<int>> vis(n, vector<int>(n, -1));
        pq.push({1, 0, 0});
        vis[0][0] = 1;
        
        while(!pq.empty()){
            auto [dis, i, j] = pq.top();
            pq.pop();

            if(i==n-1 && j==n-1) return dis;

            int dx[]= {0,1,1,1,0,-1,-1,-1}, dy[]={1,1,0,-1,-1,-1,0,1};
            for(int a = 0; a!=8; a++){
                int newI= i+dx[a], newJ= j+dy[a];
                if(isValid(newI, newJ, n) && vis[newI][newJ] == -1 && grid[newI][newJ]==0){
                    pq.push({dis+1, newI, newJ});
                    vis[newI][newJ] = 1;
                }
            }

        }
        return -1;
    }
};