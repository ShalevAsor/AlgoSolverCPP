#include "../../Utils/utils.h"

/*
Given an array of n distinct elements. Find the minimum number of swaps required
to sort the array in strictly increasing order.

Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explanation:
swap 8 with 4.
 */

class Solution {
public:
  /*
     Solution:
     Approach: we check if an element is start of a band(its the lowset number
     in the sequence) if it is we check the band size. Time: O(n) Space: O(n)

     */
  int minSwaps(vector<int> &nums) {
    // know the correct position of the element (sorting)
    // store current indices
    int ans = 0;
    const int n = nums.size();
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++) {
      ap[i].first = nums[i];
      ap[i].second = i;
    }
    sort(ap, ap + n);
    // main logic
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      // case 1: element is visited or element is in the correct position
      int oldPosition = ap[i].second;
      if (visited[i] == true || oldPosition == i) {
        continue;
      }

      // case 2: visiting the element (index) for the first time
      int node = i;
      int cycleSize = 0;
      while (!visited[node]) {
        visited[node] = true;
        int nextNode = ap[node].second;
        node = nextNode;
        cycleSize++;
      }
      ans += (cycleSize - 1);
    }
    return ans;
  }
};

int main() {
  /*
Example 1:
Input:
nums = {2, 8, 5, 4}
Output: 1
Explanation: swap 8 with 4.

Example 2:
Input:
nums = {10, 19, 6, 3, 5}
Output:2
Explanation:
swap 10 with 3 and swap 19 with 5.
*/
  vector<int> arr1 = {2, 8, 5, 4};
  vector<int> arr2 = {10, 19, 6, 3, 5};

  Solution solution;
  int res1 = solution.minSwaps(arr1);
  int res2 = solution.minSwaps(arr2);
  cout << "arr1:";
  printArray(arr1);
  cout << "output:" << res1 << endl;
  cout << "arr2:";
  printArray(arr2);
  cout << "output:" << res2 << endl;

  return 0;
}