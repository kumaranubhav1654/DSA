class Solution {
public:
bool isValid(int x,int y,int m, int n){
return ((x>=0 && y>=0)&&(x<m && y<n));
}
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1;
        int countGood = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair< int, int>>q;

        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) countGood++;
            }
        }

        if(!countGood) return 0;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [ i , j] = q.front();
                q.pop();

                int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
                for(int a = 0; a!=4; a++){
                    int ni = i+dx[a], nj = j+dy[a];
                    if(isValid(ni, nj, m, n) && grid[ni][nj]==1){
                        q.push({ ni, nj});
                        grid[ni][nj]=2;
                        countGood--;
                    } 
                }
            }
            ans++;
        }
        if(!countGood)
        return ans;
        else return -1;
    }
};