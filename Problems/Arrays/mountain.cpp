#include "../../Utils/utils.h"

/*
Mountain:
write a function that takes input an array of distinct integers
and returns the length of the highest mountain.
a mountain is defined as adjacent integers that are strictly
increasing until they reach a peak at which the
become strictly decreasing. at least 3 numbers
are required to form a mountain

Example 1:
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2]
which has length 5.
 */

class Solution {
public:
  /*
    Solution:
    Approach: using sliding window , start with window of size 3 and try to
    increase the window size Time : O(n) Space: O(1) Note:this solution may
    contain duplicates triplets

    */
  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    if (n < 3)
      return 0;

    int longest = 0;

    for (int i = 1; i < n - 1; ++i) {
      // Check if arr[i] is a peak
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
        int left = i - 1;
        int right = i + 1;

        // Expand to the left
        while (left > 0 && arr[left] > arr[left - 1]) {
          left--;
        }
        // Expand to the right
        while (right < n - 1 && arr[right] > arr[right + 1]) {
          right++;
        }

        // Calculate the length of the mountain
        int currentLength = right - left + 1;
        longest = max(longest, currentLength);
      }
    }
    return longest;
  }
  /*
    Solution:
    Approach: using sliding window , start with window of size 3 and try to
    increase the window size Time . similar to previus solution but more
    efficient Time: O(n) Space: O(1) Note:this solution may contain duplicates
    triplets

    */
  int longestMountain2(vector<int> &arr) {
    int n = arr.size();
    int longest = 0;
    if (n < 3)
      return 0;
    // iterate for potential peaks
    for (int i = 1; i <= n - 2;) {
      // check if a[i] is a peak
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
        int j = i;
        int cnt = 1;
        // expends backwards
        while (j > 0 && arr[j] > arr[j - 1]) {
          j--;
          cnt++;
        }
        // expends forwards
        while (i <= n - 2 && arr[i] > arr[i + 1]) {
          i++;
          cnt++;
        }
        longest = max(longest, cnt);
      } else {
        i++;
      }
    }
    return longest;
  }
};

int main() {
  /*
  Example 1:
  Input: arr = [2,1,4,7,3,2,5]
  Output: 5
  Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
  Example 2:
  Input: arr = [2,2,2]
  Output: 0
  Explanation: There is no mountain.
    */
  vector<int> arr1 = {2, 1, 4, 7, 3, 2, 5};
  vector<int> arr2 = {2, 2, 2};
  vector<int> arr3 = {1, 2, 1, 1};

  Solution solution;
  int res1 = solution.longestMountain(arr1);
  int res2 = solution.longestMountain(arr2);
  int res3 = solution.longestMountain(arr3);
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