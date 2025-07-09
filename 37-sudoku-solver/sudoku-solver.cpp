class Solution {
public:

    bool isSafe (int row, int col, char k, vector<vector<char>>& board){
        for(int i = 0; i!=9; i++){
            if(board[row][i]==k) return false;
        }
        for(int i = 0; i!=9; i++){
            if(board[i][col]==k) return false;
        }

        int boxRowStart = row - row % 3;
        int boxColStart = col - col % 3;

        for(int i = 0; i!=3; i++){
            for(int j = 0; j!=3; j++){
                if (board[boxRowStart + i][boxColStart + j] == k)
                    return false;
            }
        }
        return true;
    }

    bool helper(int row, int col, vector<vector<char>>& board){
        if(col==board.size()){
            row++;
            col=0;
        }

        if(row==board.size()) return true;

        if (board[row][col] != '.')
            return helper(row, col + 1, board);
        
        for(int k = 0; k!=9; k++){
            if(board[row][col]=='.'){
                if(isSafe(row, col, k + '1', board)){
                    board[row][col] = k + '1';
                    if(helper(row, col, board)) return true;
                    board[row][col] = '.';
                }
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0, 0, board);
    }
};