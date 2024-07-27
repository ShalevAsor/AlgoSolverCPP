#include "../../Utils/utils.h"
#include <queue>
/*
You are given a string s of even length consisting of digits from 0 to 9, and
two integers a and b.

You can apply either of the following two operations any number of times and in
any order on s:

Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0.
For example, if s = "3456" and a = 5, s becomes "3951". Rotate s to the right by
b positions. For example, if s = "3456" and b = 1, s becomes "6345". Return the
lexicographically smallest string you can obtain by applying the above
operations any number of times on s.

A string a is lexicographically smaller than a string b (of the same length) if
in the first position where a and b differ, string a has a letter that appears
earlier in the alphabet than the corresponding letter in b. For example, "0158"
is lexicographically smaller than "0190" because the first position they differ
is at the third letter, and '5' comes before '9'.

Example:

Input: s = "5525", a = 9, b = 2
Output: "2050"
*/
class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    string smallest = s;
    queue<string> q;
    unordered_set<string> seen;

    q.push(s);
    seen.insert(s);

    while (!q.empty()) {
      string current = q.front();
      q.pop();

      // Check the smallest string found so far
      if (current < smallest) {
        smallest = current;
      }

      // Apply rotate operation
      string rotated = rotate(current, b);
      if (seen.find(rotated) == seen.end()) {
        seen.insert(rotated);
        q.push(rotated);
      }

      // Apply add operation
      string added = add(current, a);
      if (seen.find(added) == seen.end()) {
        seen.insert(added);
        q.push(added);
      }
    }

    return smallest;
  }

  string rotate(string s, int b) {
    int n = s.length();

    // If string length is 0 or 1, rotation does not change the string.
    if (n <= 1)
      return s;

    // Calculate effective rotation
    b = b % n;

    // If b is 0, no rotation is needed
    if (b == 0)
      return s;

    // Split and rotate
    string endPart = s.substr(n - b);      // last b characters
    string startPart = s.substr(0, n - b); // first n-b characters

    return s = endPart + startPart; // concatenate to get the rotated string
  }
  string add(string s, int a) {
    // If the string has only one character, there's nothing to do.
    if (s.length() == 1)
      return s;

    // Iterate over all odd indices in the string.
    for (int i = 1; i < s.length(); i += 2) {
      // Convert the character at odd index to its integer value.
      int curr = s[i] - '0';

      // Add 'a' and take modulo 10 to handle wrap-around for digits > 9.
      int newVal = (curr + a) % 10;

      // Convert the new integer value back to a character and assign it.
      s[i] = newVal + '0';
    }
    return s;
  }
};

int main() {
  /*
Example 1:
Input: s = "5525", a = 9, b = 2
Output: "2050"


Example 2:
Input: s = "74", a = 5, b = 1
Output: "24"

Example 3:
Input: s = "0011", a = 4, b = 2
Output: "0011"

  */
  Solution solution;
  string s1 = "5525";
  int a1 = 9, b1 = 2;
  string s2 = "74";
  int a2 = 5, b2 = 1;
  string s3 = "0011";
  int a3 = 4, b3 = 2;
  string res1 = solution.findLexSmallestString(s1, a1, b1);
  string res2 = solution.findLexSmallestString(s2, a2, b2);
  string res3 = solution.findLexSmallestString(s3, a3, b3);
  cout << "input: "
       << "s: " << s1 << " a: " << a1 << " b: " << b1 << " output: " << res1
       << endl;
  cout << "input: "
       << "s: " << s2 << " a: " << a2 << " b: " << b2 << " output: " << res2
       << endl;
  cout << "input: "
       << "s: " << s3 << " a: " << a3 << " b: " << b3 << " output: " << res3
       << endl;

  return 0;
}