class Solution {
public:
bool isValid(int x, int y, int m ,int n){
    return((x>=0 && y>=0)&&(x<m && y<n));
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>>q;
        int count=0;

        for (int j = 0; j < m; j++){
            for (int i = 0; i < n; i++){
                if(grid[j][i]==1)count++;
                if(i==0 || j==0 || j==m-1 || i ==n-1){
                    if(grid[j][i]==1){
                        q.push({j, i});
                        grid[j][i]=0;
                        count--;
                    }
                }
            }
        }


        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
            for(int i = 0; i!=4; i++){
                int nx = x+dx[i], ny=y+dy[i];
                if(isValid(nx, ny, m , n) && grid[nx][ny]==1){
                    q.push({nx, ny});
                    grid[nx][ny]=0;
                    count--;
                }
            }
        }
        return count;
    }
};