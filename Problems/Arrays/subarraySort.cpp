#include "../../Utils/utils.h"

/*
Given an integer array nums, you need to find one continuous subarray such that
if you only sort this subarray in non-decreasing order, then the whole array
will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.


 */

class Solution {
public:
  /*
  Solution:
  Approach: we set new copy array and sort it, then we check if there are
  elements that has different position Time: O(nlogn) Space: O(n)
  */
  int findUnsortedSubarray(vector<int> &nums) {
    int smallestLen = 0;
    // creat a copy
    vector<int> numsCopy(nums);
    sort(numsCopy.begin(), numsCopy.end());
    int i = 0, n = nums.size();

    while (i < n && nums[i] == numsCopy[i]) {
      i++;
    }
    int j = n - 1;
    while (j > 0 && nums[j] == numsCopy[j]) {
      j--;
    }
    if (i == n) {
      // this array is already sorted;
      return 0;
    }
    return (j - i + 1);
  }
  /*
  Solution:
  Approach: we find the samllest element and the largest element that
  out of order.
  we return the
  Time: O(n) Space: O(1)
  */
  int subarraySort(vector<int> &arr) {
    int smallest = INT_MAX;
    int largest = INT_MIN;
    if (arr.size() < 2)
      return 0;
    // get the smallest and largest element that are out of order
    for (int i = 0; i < arr.size(); i++) {
      int num = arr[i];
      if (outOfOrder(arr, i)) {
        smallest = min(smallest, num);
        largest = max(largest, num);
      }
    }
    if (smallest == INT_MAX)
      return 0; // this array is already sorted
    // find the right index where smallest and largest lie
    int left = 0;
    while (smallest >= arr[left]) {
      left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right]) {
      right--;
    }
    return right - left + 1;
  }
  bool outOfOrder(vector<int> &arr, int index) {
    int num = arr[index];
    if (index == 0) {
      return num > arr[index + 1];
    }
    if (index == arr.size() - 1) {
      return num < arr[index - 1];
    }
    return (num > arr[index + 1] || num < arr[index - 1]);
  }
  /*
  Solution:
  Approach: same solution like subarraySort but we return the length of
  the unsorted subarray we return the unsorted subarray
  Time: O(nlogn) Space: O(n)
  */
  vector<int> subarraySort2(vector<int> &arr) {
    int smallest = INT_MAX;
    int largest = INT_MIN;
    if (arr.size() < 2)
      return {-1, -1};
    // get the smallest and largest element that are out of order
    for (int i = 0; i < arr.size(); i++) {
      int num = arr[i];
      if (outOfOrder(arr, i)) {
        smallest = min(smallest, num);
        largest = max(largest, num);
      }
    }
    if (smallest == INT_MAX)
      return {-1, -1}; // this array is already sorted
    // find the right index where smallest and largest lie
    int left = 0;
    while (smallest >= arr[left]) {
      left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right]) {
      right--;
    }
    return {left, right};
  }
};
int main() {
  /*
Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the
whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
  */
  vector<int> arr1 = {2, 6, 4, 8, 10, 9, 15};
  vector<int> arr2 = {1, 2, 3, 4};
  vector<int> arr3 = {1};

  Solution solution;
  int res1 = solution.findUnsortedSubarray(arr1);
  int res2 = solution.findUnsortedSubarray(arr2);
  int res3 = solution.findUnsortedSubarray(arr3);
  cout << "arr1:";
  printArray(arr1);
  cout << "output:" << res1 << endl;
  cout << "arr2:";
  printArray(arr2);
  cout << "output:" << res2 << endl;
  cout << "arr3:";
  printArray(arr3);
  cout << "output:" << res3 << endl;
  //////////second method
  vector<int> res_1 = solution.subarraySort2(arr1);
  vector<int> res_2 = solution.subarraySort2(arr2);
  vector<int> res_3 = solution.subarraySort2(arr3);
  cout << "arr1:";
  printArray(arr1);
  cout << "output:";
  printArray(res_1);
  cout << endl;

  cout << "arr2:";
  printArray(arr2);
  cout << "output:";
  printArray(res_2);
  cout << endl;
  cout << "arr3:";
  printArray(arr3);
  cout << "output:";
  printArray(res_3);
  cout << endl;

  return 0;
}