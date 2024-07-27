#include "../../Utils/utils.h"

/*
Given an array of integers nums and an integer target, return all the different
triplets that sums to the target . the triplets should be sorted and the array
of the triplets should be sorted

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].


*/
class Solution {
public:
  /*
  Solution:
  This is the solution for the leetcode question , here
  we dont need to sort the arrays . the original question from leetcode :
  Given an integer array nums, return all the triplets [nums[i], nums[j],
  nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k]
  == 0. Notice that the solution set must not contain duplicate triplets.
  Time : O(n^2)
  Space: O(1)
  Note:this solution SKIP! duplicates triplets

  */
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    // Sort the array
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    // Pick every nums[i] and use pair sum for the remaining parts
    for (int i = 0; i <= n - 3; i++) {
      // Skip duplicates
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int currSum = nums[i] + nums[left] + nums[right];
        if (currSum == 0) {
          res.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;
          // Skip duplicates
          while (left < right && nums[left] == nums[left - 1])
            left++;
          while (left < right && nums[right] == nums[right + 1])
            right--;
        } else if (currSum < 0) {
          left++;
        } else {
          right--;
        }
      }
    }
    return res;
  }

  /*
  Solution:
  This is the solution for the general case (not target = 0) , here
  we need to sort the array and the triplets .
  Approach:
  Time : O(n^2)
  Space: O(1)
  Note:this solution may contain duplicates triplets

  */
  vector<vector<int>> triplets(vector<int> &arr, int target) {
    vector<vector<int>> res;
    // Sort the array
    sort(arr.begin(), arr.end());
    const int n = arr.size();
    // pick every arr[i] and use pair sum for remaning parts
    for (int i = 0; i <= n - 3; i++) {
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int currSum = arr[i];
        currSum += arr[left];
        currSum += arr[right];
        if (currSum == target) {
          res.push_back({arr[i], arr[left], arr[right]});
          left++;
          right--;
        } else if (currSum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    return res;
  }
};

int main() {
  /*
  Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
  */
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution solution;
  vector<vector<int>> res = solution.threeSum(nums);

  for (int i = 0; i < res.size(); i++) {
    cout << "triple " << i + 1 << ": " << vectorToString(res[i]) << endl;
  }

  return 0;
}