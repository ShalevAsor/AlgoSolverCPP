#include "../../Utils/utils.h"

/*
Given an array nums with n objects colored red, white, or blue, sort them
in-place so that objects of the same color are adjacent, with the colors in the
order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and
blue, respectively.

You must solve this problem without using the library's sort function.


Example:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

class Solution {
public:
  /*
  Approach: Counting the occurrences of each color and then setting the elements
in the array based on the counts
  Time: O(n)
  Space: O(1)
  */
  void sortColors(vector<int> &nums) {
    int white = 0;
    int blue = 0;
    int red = 0;
    // count how many blue , white  and red objects we have
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        red++;
      } else if (nums[i] == 1) {
        white++;
      } else {
        blue++;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i < red) {
        nums[i] = 0;
      } else if (i >= red and i < white + red) {
        nums[i] = 1;
      } else {
        nums[i] = 2;
      }
    }
  }
  /*
   Approach: Dutch National Flag algorithm. This method sorts the array in-place
   using three pointers to keep track of the positions of red, white, and blue.

   Time: O(n)
   Space: O(1)
   */
  void sortColors2(vector<int> &nums) {
    int low = 0; // all low objects (red) will be before the low pointer
    int mid = 0; // point to the first unknown object
    int high = nums.size() -
               1; // all the high (blue) objects will be after the high pointer

    while (mid <= high) {
      if (nums[mid] == 0) { // The current object is red (0), swap it with the
                            // object at the 'low' pointer,
        // then increment both 'low' and 'mid' to process the next object.
        swap(nums[low++], nums[mid++]);
      } else if (nums[mid] == 1) { // the current object is mid (white) ,
                                   // increment mid to the next unknown object
        mid++;
      } else { // the current object is high (blue) , swap it with the mid
        swap(nums[mid], nums[high--]);
      }
    }
  }
};

int main() {

  /*
  Example 1:
  Input: nums = [2,0,2,1,1,0]
  Output: [0,0,1,1,2,2]

  Example 2:
  Input: nums = [2,0,1]
  Output: [0,1,2]

    */
  Solution solution;
  vector<int> nums1 = {2, 0, 2, 1, 1, 0};
  vector<int> nums2 = {2, 0, 1};
  cout << "input:" << endl;
  printArray(nums1);
  solution.sortColors(nums1);
  cout << "output:" << endl;
  printArray(nums1);
  cout << "input:" << endl;
  printArray(nums2);
  solution.sortColors(nums2);
  cout << "output:" << endl;
  printArray(nums2);
  return 0;
}