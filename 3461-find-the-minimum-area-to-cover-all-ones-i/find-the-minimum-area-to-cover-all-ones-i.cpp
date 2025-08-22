class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minX = INT_MAX, maxX =-1, minY = INT_MAX, maxY = -1;
        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(grid[i][j]==1){
                    minX = min(i, minX);
                    maxX = max(i, maxX);
                    minY = min(j, minY);
                    maxY = max(j, maxY);
                }
            }
        }
        return (maxX-minX+1)*(maxY-minY+1);
    }
};