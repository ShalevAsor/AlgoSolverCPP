#include "../../Utils/utils.h"
#include <climits>

/*
There are some spherical balloons taped onto a flat wall that represents the
XY-plane. The balloons are represented as a 2D integer array points where
points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches
between xstart and xend. You do not know the exact y-coordinates of the
balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from
different points along the x-axis. A balloon with xstart and xend is burst by an
arrow shot at x if xstart <= x <= xend. There is no limit to the number of
arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting
any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to
burst all balloons.



Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
 */

class Solution {
public:
  /*
       Solution:
       Approach:
       Time: O(n log n)
  */
  int findMinArrowShots(vector<vector<int>> &points) {
    if (points.empty())
      return 0;

    // Sort the points by their end coordinate
    sort(
        points.begin(), points.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    int arrows = 1; // Start with one arrow
    int end =
        points[0][1]; // Shoot the first arrow at the end of the first interval

    for (int i = 1; i < points.size(); i++) {
      // If the current interval starts after the end of the previous interval,
      // we need a new arrow
      if (points[i][0] > end) {
        arrows++;
        end =
            points[i][1]; // Shoot the arrow at the end of the current interval
      }
    }

    return arrows;
  }
};

int main() {
  /*
Example 1:
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4
arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
*/

  vector<vector<int>> arr1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  vector<vector<int>> arr2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  vector<vector<int>> arr3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

  Solution solution;
  int res1 = solution.findMinArrowShots(arr1);
  int res2 = solution.findMinArrowShots(arr2);
  int res3 = solution.findMinArrowShots(arr3);

  cout << "arr1:";
  print2DArray(arr1);
  cout << "output:" << res1 << endl;
  cout << "arr2:";
  print2DArray(arr2);
  cout << "output:" << res2 << endl;
  cout << "arr3:";
  print2DArray(arr3);
  cout << "output:" << res3 << endl;

  return 0;
}