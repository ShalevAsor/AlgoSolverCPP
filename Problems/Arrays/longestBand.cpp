#include "../../Utils/utils.h"

/*
Given an unsorted array of integers nums, return the length of the longest
consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is
[1, 2, 3, 4].
Therefore its length is 4.
 */

class Solution {
public:
  /*
     Solution:
     Approach: we check if an element is start of a band(its the lowset number
     in the sequence) if it is we check the band size. Time: O(n) Space: O(n)

     */
  int longestConsecutive(vector<int> &nums) {
    const int n = nums.size();
    unordered_set<int> set;
    int longest = 0;
    // init the set with data
    for (int num : nums) {
      set.insert(num);
    }
    // iterate of the array
    for (auto element : set) {
      int parent = element - 1;
      if (set.find(parent) == set.end()) {
        // find entire band
        int nextNum = element + 1;
        int count = 1;
        while (set.find(nextNum) != set.end()) {
          count++;
          nextNum++;
        }
        longest = max(longest, count);
      }
    }

    return longest;
  }
};

int main() {
  /*

  Example 1:
  Input: nums = [100,4,200,1,3,2]
  Output: 4
  Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
  Therefore its length is 4.

  Example 2:
  Input: nums = [0,3,7,2,5,8,4,6,0,1]
  Output: 9
  */
  vector<int> arr1 = {100, 4, 200, 1, 3, 2};
  vector<int> arr2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

  Solution solution;
  int res1 = solution.longestConsecutive(arr1);
  int res2 = solution.longestConsecutive(arr2);
  cout << "arr1:";
  printArray(arr1);
  cout << "output:" << res1 << endl;
  cout << "arr2:";
  printArray(arr2);
  cout << "output:" << res2 << endl;

  return 0;
}