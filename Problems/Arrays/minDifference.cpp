#include "../../Utils/utils.h"
#include <climits>

/*
Minimum Difference
Implement a function that takes in two non-empty arrays of integers, finds the
pair of numbers (one from each array) who absolute difference is closest to
zero, and returns a pair containing these two numbers, with the first number
from array. Only one such pair will exist for the test.
Example 1:
Input

Array1 = [23, 5, 10, 17, 30]
Array2 = [26, 134, 135, 14, 19]
Output:
17,19
 */

class Solution {
public:
  /*
     Solution:
     Approach:
     Time:

     */
  pair<int, int> minDifference(vector<int> a, vector<int> b) {

    sort(b.begin(), b.end());
    vector<int> result;
    // iterate over 1 and do binary search
    int p1, p2;

    int diff = INT_MAX;

    for (int x : a) {
      auto lb = lower_bound(b.begin(), b.end(), x) -
                b.begin(); // the index of the first element y in a s.t y>= x

      if (lb >= 1 and x - b[lb - 1] < diff) {
        diff = x - b[lb - 1];
        p2 = b[lb - 1];
        p1 = x;
      }

      if (lb != b.size() and b[lb] - x < diff) {
        diff = b[lb] - x;
        p1 = x;
        p2 = b[lb];
      }
    }

    return {p1, p2};
  }
};

int main() {
  /*
Example 1:
Input

Array1 = [23, 5, 10, 17, 30]
Array2 = [26, 134, 135, 14, 19]
Output:
17,19
*/
  vector<int> arr1 = {23, 5, 10, 17, 30};
  vector<int> arr2 = {26, 134, 135, 14, 19};

  Solution solution;
  pair<int, int> res = solution.minDifference(arr1, arr2);
  cout << "arr1:";
  printArray(arr1);
  cout << endl;
  cout << "arr2:";
  printArray(arr2);
  cout << "output:" << res.first << "," << res.second << endl;

  return 0;
}