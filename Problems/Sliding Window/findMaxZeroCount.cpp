#include "../../Utils/utils.h"

/*
Given a binary array, find the maximum number of zeros in an array with one flip
of a subarray allowed. A flip operation switches all 0s to 1s and 1s to 0s.
Example:

Input :  arr[] = {0, 1, 0, 0, 1, 1, 0}
Output : 6
We can get 6 zeros by flipping the subarray {4, 5}

*/

int findMaxZeroCount(bool arr[], int n) {
  // Initialize count of zeros and maximum difference
  // between count of 1s and 0s in a subarray
  int orig_zero_count = 0;
  // Init overall max diff for any subarray
  int max_diff = 0;
  // Initialize current diff
  int curr_max = 0;
  for (int i = 0; i < n; i++) {
    // Count of zeros in original array (Not related
    // to Kadane's algorithm)
    if (arr[i] == 0)
      orig_zero_count++;

    // Value to be considered for finding maximum sum
    int val = (arr[i] == 1) ? 1 : -1;
    // Update current max and max_diff
    curr_max = max(val, curr_max + val);
    max_diff = max(max_diff, curr_max);
  }
  max_diff = max(0, max_diff);

  return orig_zero_count + max_diff;
}

int main() {
  /*
Examples:

Input :  arr[] = {0, 1, 0, 0, 1, 1, 0}
Output : 6
We can get 6 zeros by flipping the subarray {4, 5}

Input :  arr[] = {0, 0, 0, 1, 0, 1}
Output : 5


  */

  bool arr1[] = {0, 1, 0, 0, 1, 1, 0};
  int n = sizeof(arr1) / sizeof(arr1[0]);
  cout << findMaxZeroCount(arr1, n) << endl;
  bool arr2[] = {0, 0, 0, 1, 0, 1};
  n = sizeof(arr2) / sizeof(arr2[0]);
  cout << findMaxZeroCount(arr2, n);

  return 0;
}