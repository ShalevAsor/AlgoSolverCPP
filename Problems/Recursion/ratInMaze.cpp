#include "../../Utils/utils.h"

/*
You are given a an integer N and a grid of size NxN. The cells of the grid are numbered row wise from 1 to N^2.
Rat wants to travel from cell number 1 to cell number N^2,
and it can move in only right direction or down direction from a particular cell.
There is exactly one path from source to destination as some cells are blocked.
Help the rat to find the path.

Input Format:
In the function an integer N is given,
and a 2D vector consisting of only 'O's And 'X's is given where 'X' represents blocked cell.

Output Format:
Return a vector of cell numbers of cells in path (in sequence).
*/
bool findPathHelper(vector<vector<char>> &grid, int n, vector<int> &path, int row, int col) {
    // Base Case: Reached destination (bottom-right corner)
    if (row == n - 1 && col == n - 1) {
        path.push_back(row * n + col + 1); // 1-based index for the path
        return true;
    }

    // Add the current cell to the path
    path.push_back(row * n + col + 1); // Convert to 1-based indexing

    // Move right if possible
    if (col + 1 < n && grid[row][col + 1] == 'O') {
        if (findPathHelper(grid, n, path, row, col + 1)) {
            return true;
        }
    }

    // Move down if possible
    if (row + 1 < n && grid[row + 1][col] == 'O') {
        if (findPathHelper(grid, n, path, row + 1, col)) {
            return true;
        }
    }

    // Backtrack: Remove the current cell from the path
    path.pop_back();
    return false;
}

vector<int> findPath(int n, vector<vector<char>> c) {
    vector<int> path;
    findPathHelper(c, n, path, 0, 0);
    return path;
}

int main(){
/*
Example:
Input:

4

O O X O

O X O O

O O O X

X  X O O

Output:

1  5  9  10  11  15  16
*/
vector<vector<char>> c = {
    { 'O', 'O', 'X', 'O' },
    { 'O', 'X', 'O', 'O' },
    { 'O', 'O', 'O', 'X' },
    { 'X', 'X', 'O', 'O' }
};
int n = 4;
vector<int> path = findPath(n, c);
cout<< path.size() << endl;
printArray(path);

    return 0;
}