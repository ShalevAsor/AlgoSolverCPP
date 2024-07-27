#include "../../Utils/utils.h"
/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous
row. Given an integer target, return true if target is in matrix or false
otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

/*
Approach: Binary search
Time: O(log(m * n))
Space:O(1)
*/
//
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }

    int rows = matrix.size();
    int columns = matrix[0].size();
    int left = 0;
    int right = rows * columns - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2; // mid index
      int midValue = matrix[mid / columns][mid % columns];

      if (midValue == target) {
        return true;
      } else if (midValue < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return false;
  }
};
int main() {
  /*
  Example 1:
  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
  Output: true
  Example 2:
  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
  Output: false
  */
  Solution solution;
  vector<vector<int>> m = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target1 = 3;
  int target2 = 13;

  cout << "input: " << endl;
  print2DArray(m);
  cout << "target: " << target1
       << " output: " << solution.searchMatrix(m, target1) << endl;
  cout << "target: " << target2
       << " output: " << solution.searchMatrix(m, target2) << endl;
}