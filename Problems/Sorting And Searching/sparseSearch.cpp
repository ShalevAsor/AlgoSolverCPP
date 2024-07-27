#include "../../Utils/utils.h"
/*
Given a sorted array of string that is interspersed with empty
strings , write a method to find the location of a given string
Example:
Input: ["ai","","","bat","","","car","cat","","","dog",""]
target = "bat"
Output:3

*/

/*
Approach: Straightforward method using linear search
Time Complexity: O(n * w) where w is the length of the word
Space Complexity: O(1)
*/

int sparseSearchLinear(string arr[], int n, string target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i; // the position of target
    }
  }
  return -1; // no target was found
}
/*
Approach: Binary search with extra step - traversing to the nearest non empty
string Time Complexity: O(n) and log(n) on average
Space Complexity:
O(1)
*/

int sparseSearch(string arr[], int n, string target) {
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == "") {
      // traverse mid to the nearest non-empty string
      int left = mid - 1;
      int right = mid + 1;
      while (left >= 0 and right < n) {
        if (arr[left] != "") {
          mid = left;
          break;
        } else if (arr[right] != "") {
          mid = right;
          break;
        } else {
          left--;
          right++;
        }
      }
    }
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1; // not found
}

int main() {

  string arr[] = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};
  int n = sizeof(arr) / sizeof(arr[0]);
  string target = "bat";
  int output = sparseSearch(arr, n, target);
  cout << "input: " << arrayToString(arr, n) << endl;
  cout << "output: " << output << endl;
}