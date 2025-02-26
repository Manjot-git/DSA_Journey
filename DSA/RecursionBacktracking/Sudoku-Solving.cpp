class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        //horizontal
        for(int j=0; j<9; j++){
            if(board[row][j] == dig){
                return false;
            }
        }

        //vertical
        for(int i=0; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        //grid  // Check 3x3 grid

        int srow = (row/3) * 3;
        int scol = (col/3) * 3;

        for(int i=srow; i<=srow+2; i++){
            for(int j=scol; j<=scol+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col){
        // Base-case: If we have reached past the last row, the board is solved
        if(row == 9){
            return true;
        }


        int nextRow = row, nextCol = col+1;
        if(nextCol == 9){
            nextRow = row + 1;
            nextCol = 0;
        }

        // If the cell is already filled, move to the next cell
        if(board[row][col] != '.'){
            return helper(board, nextRow, nextCol);
        }

        //place the digit, // Try placing digits from '1' to '9'
        for(char dig = '1'; dig<='9'; dig++){
            if(isSafe(board, row, col, dig)){
                board[row][col] = dig; //main

                if(helper(board, nextRow, nextCol)) return true;
                board[row][col] = '.'; // backtracking

            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0 , 0);
    }
};
