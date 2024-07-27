#include "../../Utils/utils.h"

/*
Given an integer array nums of unique elements, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any
order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

*/
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    res.push_back({}); // insert the empty set

    for (int num : nums) {
      int n = res.size();
      for (int i = 0; i < n; i++) {
        vector<int> subset = res[i];
        subset.push_back(num);
        res.push_back(subset);
      }
    }
    return res;
  }
};
int main() {
  /*

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

  */
  vector<int> arr1 = {1, 2, 3};
  vector<int> arr2 = {0};

  Solution solution;
  vector<vector<int>> res1 = solution.subsets(arr1);
  vector<vector<int>> res2 = solution.subsets(arr2);

  cout << "arr:";
  printArray(arr1);
  cout << "output:" << endl;
  print2DArray(res1);
  cout << "arr:";
  printArray(arr2);
  cout << "output:" << endl;
  print2DArray(res2);

  return 0;
}