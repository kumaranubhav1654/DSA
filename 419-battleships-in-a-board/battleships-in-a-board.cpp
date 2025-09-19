class Solution {
public:
    // bool isValid(int x, int y, int m, int n){
    //     return ((x>=0 && x<m)&&(y>=0 && y<n));
    // }

    // void dfs(int i, int j, vector<vector<char>>& board, int m, int n, vector<vector<int>>& visited){
    //     int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

    //     for(int a = 0; a<4; a++){
    //         int newI = i+dx[a], newJ = j+dy[a];
    //         if(isValid(newI, newJ, m, n) && board[newI][newJ]=='X' && !visited[newI][newJ]){
    //             visited[newI][newJ] = 1;
    //             dfs(newI, newJ, board, m, n, visited);
    //         }
    //     }
    // }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        //vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;

        for(int i = 0; i!=m; i++){
            for(int j = 0; j!=n; j++){
                if(board[i][j]=='X'){
                    if((i-1 >= 0 && board[i-1][j]=='X') || (j-1 >= 0 && board[i][j-1]=='X')) continue;
                    else ans++;
                }
            }
        }
        return ans;
    }
};