#include "../../Utils/utils.h"

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/



bool isValid(vector<vector<char>> &board,int row,int col,char num){
    //check the row
    for(int i = 0; i < board.size();i++){
        if(board[row][i] == num){
            return false;
        }
    }
    //check the column
    for(int i = 0; i < board[0].size();i++){
        if(board[i][col] == num){
            return false;
        }
    }
    //check the 3x3 sub-box
    int subRow = row / 3 * 3;
    int subCol = col / 3 * 3;
    for(int i = subRow;i<subRow + 3; i++){
        for(int j = subCol;j < subCol + 3; j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<char>> &board,int row,int col){
    if(row == 9){//if we have reached the last row, then we have solved the sudoku
        return true;
    }
    int nextRow = row,nextCol = col+1;
    if(nextCol == 9){//if we have reached the last column, then we have to move to the next row
        nextRow = row +1;
        nextCol = 0;
    }
    if(board[row][col] != '.'){//if the current cell is not empty go to the next cell
        return sudokuSolver(board,nextRow,nextCol);
    }
    for(char num = '1';num <= '9' ; num++){//try all the possible numbers
        if(isValid(board,row,col,num)){
            board[row][col] = num;
            if(sudokuSolver(board,nextRow,nextCol)){//if we have solved the sudoku
                return true;
            }
            board[row][col] = '.';//backtrack
        }
    
    }
    return false;//if we have tried all the possible numbers and none of them worked
}

void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board,0,0);
}

int main(){

/*
Example:
Input: board = [
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]
Output: [
["5","3","4","6","7","8","9","1","2"],
["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],
["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],
["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]]
*/

vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};
const vector<vector<char>> expected = {
    {'5','3','4','6','7','8','9','1','2'},
    {'6','7','2','1','9','5','3','4','8'},
    {'1','9','8','3','4','2','5','6','7'},
    {'8','5','9','7','6','1','4','2','3'},
    {'4','2','6','8','5','3','7','9','1'},
    {'7','1','3','9','2','4','8','5','6'},
    {'9','6','1','5','3','7','2','8','4'},
    {'2','8','7','4','1','9','6','3','5'},
    {'3','4','5','2','8','6','1','7','9'}
};

solveSudoku(board);
cout << equals(board,expected)<< endl;

}