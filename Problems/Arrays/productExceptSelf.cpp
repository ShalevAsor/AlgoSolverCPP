#include "../../Utils/utils.h"

/*
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.

You must write an algorithm that runs in O(n) time and without using the
division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
 */

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int prod = 1;
    int n = nums.size();
    int zeros = 0;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        prod *= nums[i];
      } else {
        zeros++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        if (zeros == 0) {
          res[i] = (prod / nums[i]);
        } else {
          res[i] = 0;
        }

      } else {
        if (zeros == 1) {
          res[i] = prod;
        } else {
          res[i] = 0;
        }
      }
    }
    return res;
  }
};

int main() {
  /*
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/

  vector<int> arr1 = {1, 2, 3, 4};
  vector<int> arr2 = {-1, 1, 0, -3, 3};

  Solution solution;
  vector<int> res1 = solution.productExceptSelf(arr1);
  vector<int> res2 = solution.productExceptSelf(arr2);

  cout << "arr1:";
  printArray(arr1);
  cout << "output:" << endl;
  printArray(res1);
  cout << "arr2:";
  printArray(arr2);
  cout << "output:" << endl;
  printArray(res2);

  return 0;
}