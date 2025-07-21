class Solution {
public:
bool isValid(int x, int y, int m, int n){
    return ((x>=0 && y>=0) && (x<m && y<n));
}
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(grid[i][j]==1){
                    ans+=4;
                    int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
                    for(int a = 0; a!=4; a++){
                        int newI = i+dx[a], newJ = j+dy[a];
                        if(isValid(newI, newJ, m, n) && grid[newI][newJ])ans--;
                    }
                }
            }
        }
        return ans;
    }
};