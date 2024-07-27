#include "../../Utils/utils.h"

/*
Given a list of non-negative integers nums, arrange them such that they form the
largest number and return it.

Since the result may be very large, so you need to return a string instead of an
integer.

Example 1:

Input: nums = [10,2]
Output: "210"

*/
bool compare(const string &a, const string &b) { return a + b > b + a; }
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> numStrs;
    numStrs.reserve(nums.size()); // Reserve space to avoid multiple allocations
    for (int num : nums) {
      numStrs.push_back(to_string(num));
    }

    // Sort using custom comparator
    sort(numStrs.begin(), numStrs.end(), compare);

    // Handle edge case where the largest number is "0"
    if (numStrs[0] == "0") {
      return "0";
    }

    // Concatenate sorted strings
    string result;
    for (const string &numStr : numStrs) {
      result += numStr;
    }

    return result;
  }
};

int main() {
  /*

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [1,2,3,4,5,6,7,8,9,0]
Output: "9876543210"

  */
  vector<int> arr1 = {10, 2};
  vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  Solution solution;
  string res1 = solution.largestNumber(arr1);
  string res2 = solution.largestNumber(arr2);

  cout << "arr1:";
  printArray(arr1);
  cout << "output:" << res1 << endl;
  cout << "arr2:";
  printArray(arr2);
  cout << "output:" << res2 << endl;

  return 0;
}