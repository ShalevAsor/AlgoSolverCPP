#include "../../Utils/utils.h"

/*
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped.
 */

class Solution {
public:
  /*
  Solution:
  Approach: set left and right array with the max height of the "wall" and then
  calc the trapped water.
   Time: O(n) Space: O(n)
  */
  int trap(vector<int> &height) {
    const int n = height.size();
    int waterTrapped = 0;
    if (n <= 2)
      return 0;
    // init left max , right max
    vector<int> left(n, 0), right(n, 0);
    left[0] = height[0];
    right[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++) {
      left[i] = max(left[i - 1], height[i]);
      right[n - 1 - i] = max(right[n - i], height[n - 1 - i]);
    }
    // compute water trapped
    for (int i = 0; i < n; i++) {
      waterTrapped += min(left[i], right[i]) - height[i];
    }
    return waterTrapped;
  }
};

int main() {
  /*
  Example 1:
  Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
  Output: 6
  Explanation: The above elevation map (black section) is represented by array
  [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
  are being trapped.

  Example 2:
  Input: height = [4,2,0,3,2,5]
  Output: 9
  */
  vector<int> arr1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> arr2 = {4, 2, 0, 3, 2, 5};

  Solution solution;
  int res1 = solution.trap(arr1);
  int res2 = solution.trap(arr2);
  cout << "arr1:";
  printArray(arr1);
  cout << "output:" << res1 << endl;
  cout << "arr2:";
  printArray(arr2);
  cout << "output:" << res2 << endl;

  return 0;
}