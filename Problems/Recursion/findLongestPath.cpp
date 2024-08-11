#include "../../Utils/utils.h"

/*
Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the length of longest possible route possible from top left position (0,0) to bottom right position (m,n)  within the matrix. We are allowed to move to only adjacent cells which are not hurdles. The route cannot contains any diagonal moves and a location once visited in a particular path cannot be visited again.

Input Format:

In the function you are given number of rows M, number of columns N and 2D vector (M X N) consisting of 0s and 1s where 0s represents the hurdles.

Output Format:

A single integer representing the length of longest path
*/

int longestPathHelper(vector<vector<int>> &mat, int m, int n, int row, int col, set<int> &visited) {
    // Base Case: Reached destination (bottom-right corner)
    if (row == m - 1 && col == n - 1) {
        return 0; // This counts as a valid step to the destination
    }
    
    // Mark the current cell as visited
    visited.insert(row * n + col);
    
    int maxPath = -1; // Set to -1 to signify no valid path found yet

    // Move right if possible
    if (col + 1 < n && mat[row][col + 1] == 1 && visited.find(row * n + (col + 1)) == visited.end()) {// Check if the cell is not a hurdle and not visited
        int pathLength = longestPathHelper(mat, m, n, row, col + 1, visited);
        if (pathLength != -1) { // Only consider valid paths
            maxPath = max(maxPath, 1 + pathLength);
        }
    }

    // Move down if possible
    if (row + 1 < m && mat[row + 1][col] == 1 && visited.find((row + 1) * n + col) == visited.end()) {
        int pathLength = longestPathHelper(mat, m, n, row + 1, col, visited);
        if (pathLength != -1) { // Only consider valid paths
            maxPath = max(maxPath, 1 + pathLength);
        }
    }

    // Move left if possible
    if (col - 1 >= 0 && mat[row][col - 1] == 1 && visited.find(row * n + (col - 1)) == visited.end()) {
        int pathLength = longestPathHelper(mat, m, n, row, col - 1, visited);
        if (pathLength != -1) { // Only consider valid paths
            maxPath = max(maxPath, 1 + pathLength);
        }
    }

    // Move up if possible
    if (row - 1 >= 0 && mat[row - 1][col] == 1 && visited.find((row - 1) * n + col) == visited.end()) {
        int pathLength = longestPathHelper(mat, m, n, row - 1, col, visited);
        if (pathLength != -1) { // Only consider valid paths
            maxPath = max(maxPath, 1 + pathLength);
        }
    }

    // Backtrack: Remove the current cell from the visited set
    visited.erase(row * n + col);

    return maxPath; // Return the maximum path length found
}

int findLongestPath(int m, int n, vector<vector<int>> v) {
    // Check if the start or end is blocked
    if (v[0][0] == 0 || v[m-1][n-1] == 0) {
        return -1; // No path possible
    }

    set<int> visited;
    return longestPathHelper(v, m, n, 0, 0, visited);
}





int main(){

/*
Example:
Input:

3 3

1 1 1

1 1 1

0 0 1

Output:
6

*/

int m = 3, n  = 3;
vector<vector<int>> v = {{1,1,1},{1,1,1},{0,0,1}};
cout << findLongestPath(m,n,v) << endl;//6
    return 0;
}