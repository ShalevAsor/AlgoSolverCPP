#include "../../Utils/utils.h"
#include <deque>
/*
Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.



Example :

Input: nums = [1,1,1], k = 2
Output: 2

*/
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> sum_count;
    sum_count[0] =
        1; // To handle the case when the cumulative sum itself equals k

    int current_sum = 0;
    int count = 0;

    for (int num : nums) {
      current_sum += num;

      // Check if there is a subarray sum equals to k
      if (sum_count.find(current_sum - k) != sum_count.end()) {
        count += sum_count[current_sum - k];
      }

      // Update the count of the current cumulative sum in the map
      sum_count[current_sum]++;
    }

    return count;
  }
};
int main() {
  /*

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

  */
  Solution solution;
  vector<int> arr1 = {1, 1, 1};
  int k1 = 2;
  int res1 = solution.subarraySum(arr1, k1);
  vector<int> arr2 = {1, 2, 3};
  int k2 = 3;
  int res2 = solution.subarraySum(arr2, k2);

  cout << "input: ";
  printArray(arr1);
  cout << "k: " << k1 << "output: " << res1 << endl;
  cout << "input: ";
  printArray(arr2);
  cout << "k: " << k2 << "output: " << res2 << endl;

  return 0;
}