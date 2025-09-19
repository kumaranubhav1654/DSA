class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int goodOranges = 0, step = 0;
        queue<pair<int, int>>q;
        vector<vector<int>> visited(m, (vector<int>(n, -1)));

        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(grid[i][j]==1) goodOranges++;
                else if (grid[i][j]==2){
                visited[i][j] = 1;
                 q.push({i, j});
                 }
            }
        }

        int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};
        while(!q.empty() && goodOranges!=0){
            int s = q.size();
            while(s--){
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i!=4; i++){
                    int newX = x + dx[i], newY = y + dy[i];
                    if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1 && visited[newX][newY]!=1){
                        grid[newX][newY]=2;
                        q.push({newX, newY});
                        goodOranges--;
                    }
                }
 
            }
            step++;
        }
        if(!goodOranges) return step;
        else return -1;
    }
};