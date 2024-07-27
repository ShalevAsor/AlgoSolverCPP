#include "../../Utils/utils.h"
#include <deque>
/*
You are given an array of integers nums, there is a sliding window of size k
which is moving from the very left of the array to the very right. You can only
see the k numbers in the window. Each time the sliding window moves right by one
position.

Return the max sliding window.

Example :

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

*/
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    deque<int> dq; // Will store indices of array elements

    for (int i = 0; i < nums.size(); i++) {
      // Remove indices of elements not in the current window
      if (!dq.empty() && dq.front() == i - k) {
        dq.pop_front();
      }

      // Remove indices of all elements smaller than the current element
      // since they are not useful anymore
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }

      // Add the current element's index to the deque
      dq.push_back(i);

      // If we have processed at least 'k' elements, add the maximum element in
      // the current window to the result
      if (i >= k - 1) {
        result.push_back(nums[dq.front()]);
      }
    }

    return result;
  }
};
int main() {
  /*

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Example 2:

Input: nums = [1], k = 1
Output: [1]
  */
  vector<int> arr1 = {1, 3, -1, -3, 5, 3, 6, 7};
  int k1 = 3;
  vector<int> arr2 = {1};
  int k2 = 1;

  Solution solution;
  cout << "input: ";
  printArray(arr1);
  cout << "k: " << k1 << endl;
  cout << "output: ";
  vector<int> res1 = solution.maxSlidingWindow(arr1, k1);
  printArray(res1);
  cout << "input: ";
  printArray(arr2);
  cout << "k: " << k2 << endl;
  cout << "output: ";
  vector<int> res2 = solution.maxSlidingWindow(arr2, k2);
  printArray(res2);

  return 0;
}