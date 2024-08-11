#include "../../Utils/utils.h"
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/



bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    // Check left diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }
    // Check right diagonal
    i = row, j = col;
    while (i >= 0 && j < n) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void solveNQueensHelper(int n, int row, vector<string>& board, vector<vector<string>>& solutions) {
    // Base case
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    // Recursive case
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueensHelper(n, row + 1, board, solutions);
            // Backtrack
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));  // Initialize an empty n x n board
    solveNQueensHelper(n, 0, board, solutions);
    return solutions;
}






void printBoard(const vector<vector<string>> &solutions) {
    for (const auto &solution : solutions) {
        for (const auto &row : solution) {
            cout << row << endl;
        }
        cout << "-------------" << endl;
    }
}


int main(){
/*
Example:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/
vector<vector<string>> result = solveNQueens(4);
printBoard(result);

int board[][20] = {0};
int n = 4;


return 0;
}