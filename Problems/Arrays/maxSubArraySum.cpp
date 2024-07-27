#include "../../Utils/utils.h"

/*
Given an integer array nums, find the
subarray
 with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 */

class Solution {
public:
  /*
   Solution:

   Approach: we check if an element is start of a band
   (its the lowset number in the sequence) if it is we check the band size.
    Time: O(n) Space: O(1)
  */

  int maxSubArray(std::vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < n; i++) {
      currentSum = std::max(nums[i], currentSum + nums[i]);
      maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
  }
};

int main() {
  /*
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
  */
  vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> arr2 = {1};
  vector<int> arr3 = {5, 4, -1, 7, 8};

  Solution solution;
  int res1 = solution.maxSubArray(arr1);
  int res2 = solution.maxSubArray(arr2);
  int res3 = solution.maxSubArray(arr3);

  cout << "arr1:";
  printArray(arr1);
  cout << "output:" << res1 << endl;
  cout << "arr2:";
  printArray(arr2);
  cout << "output:" << res2 << endl;
  cout << "arr3:";
  printArray(arr3);
  cout << "output:" << res3 << endl;

  return 0;
}