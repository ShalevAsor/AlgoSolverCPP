#include "../../Utils/utils.h"

/*
Given two strings s and t, return true if s is a subsequence of t, or false
otherwise.

A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (i.e., "ace" is a subsequence of
"abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

*/
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return i == s.length();
  }
};

int main() {
  /*

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

  */
  string s1 = "abc", t1 = "ahbgdc";
  string s2 = "axc", t2 = "ahbgdc";

  Solution solution;
  bool res1 = solution.isSubsequence(s1, t1);
  bool res2 = solution.isSubsequence(s2, t2);

  cout << "s1:" << s1 << endl;
  cout << "output:" << res1 << endl;
  cout << "s2:" << s2 << endl;
  cout << "output:" << res2 << endl;

  return 0;
}