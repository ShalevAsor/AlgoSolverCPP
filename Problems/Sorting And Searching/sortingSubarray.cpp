#include "../../Utils/utils.h"

/*
Write a function that takes in an array and returns two integers, denoting
starting and ending indices of the smallest subarray in the input array that
needs to be sorted in place so that the entire input is sorted.

If the input array is already sorted, return a pair [-1,-1].

Sample Input

[0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29]
Sample Output

[4,6]
Explanation

If we sort the subarray [10, 11, 7] then entire array becomes sorted.
*/

/*
Approach:
Time:O(n)
Space:O(1)
*/
pair<int, int> subarraySorting(vector<int> a) {
  int n = a.size();
  int left = -1, right = -1;

  // Find the first point from the left where the order is incorrect
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      left = i;
      break;
    }
  }

  // If the array is already sorted
  if (left == -1) {
    return {-1, -1};
  }

  // Find the first point from the right where the order is incorrect
  for (int i = n - 1; i > 0; i--) {
    if (a[i] < a[i - 1]) {
      right = i;
      break;
    }
  }

  // Find the minimum and maximum values within the subarray
  int subarrayMin = *min_element(a.begin() + left, a.begin() + right + 1);
  int subarrayMax = *max_element(a.begin() + left, a.begin() + right + 1);

  // Expand the left boundary if there are any values greater than the minimum
  // value
  while (left > 0 && a[left - 1] > subarrayMin) {
    left--;
  }

  // Expand the right boundary if there are any values less than the maximum
  // value
  while (right < n - 1 && a[right + 1] < subarrayMax) {
    right++;
  }
  return {left, right};
}

int main() {
  /*
  Example 1:
  Input: nums = [2,6,4,8,10,9,15]
  Output: {1,5}
  Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the
  whole array sorted in ascending order.

  Example 2:
  Input: nums = [1,2,3,4]
  Output: {-1,-1}

  Example 3:
  Input: nums = [1]
  Output: {-1,-1}

  Example 4:
  Input: nums = [0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29]
  Output: {4,6}

  */

  vector<int> arr1 = {2, 6, 4, 8, 10, 9, 15};
  pair<int, int> res1 = subarraySorting(arr1);
  vector<int> arr2 = {1, 2, 3, 4};
  pair<int, int> res2 = subarraySorting(arr2);
  vector<int> arr3 = {1};
  pair<int, int> res3 = subarraySorting(arr3);
  vector<int> arr4 = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
  pair<int, int> res4 = subarraySorting(arr4);
  cout << "input:" << endl;
  printArray(arr1);
  cout << "output:"
       << "{" << res1.first << "," << res1.second << "}" << endl;
  cout << "input:" << endl;
  printArray(arr2);
  cout << "output:"
       << "{" << res2.first << "," << res2.second << "}" << endl;
  cout << "input:" << endl;
  printArray(arr3);
  cout << "output:"
       << "{" << res3.first << "," << res3.second << "}" << endl;
  cout << "input:" << endl;
  printArray(arr4);
  cout << "output:"
       << "{" << res4.first << "," << res4.second << "}" << endl;

  return 0;
}