class Solution {
public:

    bool isValid(int x, int y, int m, int n){
        return ((x>=0 && y>=0) && (x<m && y<n));
    }

    void bfs(queue<pair<pair<int, int>, int>> &q, vector<vector<int>>& vis, int m, int n, vector<vector<int>>& mat){
        while(!q.empty()){
            auto [a, b] = q.front();
            int x = a.first, y = a.second;
            q.pop();

            int dx[] = {0,0,-1,1}, dy[]={1,-1,0,0};

            for(int i = 0; i!=4; i++){
                int newx = x+dx[i], newy = y+dy[i];
                if(isValid(newx, newy, m, n) && !vis[newx][newy]){
                    if( mat[newx][newy] == 1 && b==0){
                        q.push({{newx, newy}, 1});
                        vis[newx][newy] = 1;
                    }
                    else{
                        q.push({{newx, newy}, b+1});
                        mat[newx][newy] = b+1;
                        vis[newx][newy] = 1;
                    }
                }
            }

        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>>q;

        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(mat[i][j] == 0 && !vis[i][j]){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        bfs(q, vis, m, n ,mat);

        return mat;
    }
};