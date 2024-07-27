#include "../../Utils/utils.h"
/*
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Solution:
Time : O(nlogn)
space: O(n)

*/
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<pair<int, int>> numsCopy;
    copyVector(nums, numsCopy);
    vector<int> res(2);

    // sort the array based on the first element of the pair
    sort(numsCopy.begin(), numsCopy.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first < b.first;
         });

    int first = 0;
    int last = numsCopy.size() - 1;
    while (first < last) { // Corrected the condition from <= to < for proper
                           // two-pointer technique
      int currSum = numsCopy[first].first + numsCopy[last].first;
      if (currSum < target) {
        first++;
      } else if (currSum > target) {
        last--;
      } else {
        res = {numsCopy[first].second, numsCopy[last].second};
        break;
      }
    }
    return res;
  }
  void copyVector(const vector<int> &arr, vector<pair<int, int>> &target) {
    for (int i = 0; i < arr.size(); i++) {
      target.push_back({arr[i], i});
    }
  }

  /*
  his approach
  similar to toSum problem but this time we dont need to return the index we
  need to return the values .
  Solution:
  Time : O(n)
  space: O(n)

  */
  vector<int> toSumReturnValue(vector<int> &nums, int target) {
    vector<int> res;
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (s.find(diff) != s.end()) {
        res.push_back(nums[i]);
        res.push_back(diff);
        return res;
      }
      s.insert(nums[i]);
    }
    return res;
  }
  vector<int> toSumReturnIndex(vector<int> &nums, int target) {
    vector<int> res;
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];

      // Check if the diff exists in the map
      if (numToIndex.find(diff) != numToIndex.end()) {
        res.push_back(numToIndex[diff]); // Push back the index of the diff
        res.push_back(i);                // Push back the current index
        return res;                      // Return the result immediately
      }

      // Store the current number and its index in the map
      numToIndex[nums[i]] = i;
    }

    return res; // Return the result if no pair is found
  }
};

int main() {
  /*
  Example 1:
  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
  */
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  Solution solution;
  vector<int> result = solution.twoSum(nums, target);
  printArray(result);
  printArray(solution.toSumReturnValue(nums, target));

  return 0;
}