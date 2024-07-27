#include "../../Utils/utils.h"

/*
Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string
"".

The testcases will be generated such that the answer is unique.



Example:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from
string t.

*/
class Solution {
public:
  string minWindow(string s, string t) {
    // set frequency pattern and string
    int FP[256] = {0};
    int FS[256] = {0};
    for (int i = 0; i < t.length(); i++) {
      FP[t[i]]++;
    }
    // sliding window algorithm
    int counter = 0;
    int start = 0; // left contraction
    int startIdx = -1;
    int minWindowSize = INT_MAX;
    int windowSize;
    string result = "";
    for (int i = 0; i < s.length(); i++) {
      // expand the window by including current character
      char ch = s[i];
      FS[ch]++;
      // count how many characters have been matched till now
      if (FP[ch] > 0 and FS[ch] <= FP[ch]) {
        counter++;
      }
      // if all characters of the pattern are found in the current window
      if (counter == t.length()) {
        // start contracting from the left to remove unwanted characters
        while (FP[s[start]] == 0 or FS[s[start]] > FP[s[start]]) {
          // while the char at position start is not part of the pattern
          //  or it occurs at the window more then in the pattern
          FS[s[start]]--;
          start++;
        }

        windowSize = i - start + 1;
        if (windowSize < minWindowSize) {
          minWindowSize = windowSize;
          startIdx = start;
        }
      }
    }
    if (startIdx == -1) { // now window found
      return "";
    }
    return s.substr(startIdx, minWindowSize);
  }
};
int main() {
  /*

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from
string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


  */
  vector<string> s = {"ADOBECODEBANC", "a", "a"};
  vector<string> t = {"ABC", "a", "aa"};

  Solution solution;
  for (int i = 0; i < s.size(); ++i) {
    string res = solution.minWindow(s[i], t[i]);
    cout << "s" << (i + 1) << ": " << s[i] << " t" << (i + 1) << ": " << t[i]
         << " output: " << res << endl;
  }

  return 0;
}