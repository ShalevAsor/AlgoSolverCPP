#include "../../Utils/utils.h"

/*
Given a string s, find the length of the longest
substring
 without repeating characters.

Example :

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

*/
class Solution {
public:
  //   int lengthOfLongestSubstring(string s) {
  //     unordered_set<char> visited;
  //     int maxLength = 0;
  //     int currLength = 0;
  //     int i = 0, j = 0;
  //     int n = s.size();
  //     while (j < n) {
  //       if (visited.find(s[j]) == visited.end()) {
  //         currLength++;
  //         visited.insert(s[j]);
  //         j++;
  //       } else {
  //         maxLength = max(maxLength, currLength);
  //         i = j;
  //         currLength = 0;
  //         visited.clear();
  //       }
  //     }
  //     return maxLength;
  //   }
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastOccurrence;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.size(); ++end) {
      char currentChar = s[end];

      // If the character is found in the map and is within the current window
      if (lastOccurrence.find(currentChar) != lastOccurrence.end() &&
          lastOccurrence[currentChar] >= start) {
        start = lastOccurrence[currentChar] + 1;
      }

      // Update the last occurrence of the current character
      lastOccurrence[currentChar] = end;

      // Calculate the length of the current window and update maxLength if
      // needed
      maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }
  string uniqueSubstring(string s) {
    unordered_map<char, int> lastOccurrence;
    int i = 0, j = 0;
    int currWindowLen = 0;
    int maxWindowLen = 0;
    int startWindow = -1;
    int n = s.length();

    while (j < n) {
      char ch = s[j];
      // if it is inside the map and its in current window
      if (lastOccurrence.count(ch) and lastOccurrence[ch] >= i) {
        i = lastOccurrence[ch] + 1;
        currWindowLen = j - i;
      }
      // update last occurrence
      lastOccurrence[ch] = j;
      currWindowLen++;
      j++;
      // update max window length at every step
      if (currWindowLen > maxWindowLen) {
        maxWindowLen = currWindowLen;
        startWindow = i;
      }
    }
    return s.substr(startWindow,maxWindowLen);
  }
};
int main() {
  /*

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a
substring.


  */
  string str1 = "abcabcbb";
  string str2 = "bbbbb";
  string str3 = "pwwkew";
  string str4 = " ";
  string str5 = "dvdf";

  Solution solution;
  int res1 = solution.lengthOfLongestSubstring(str1);
  int res2 = solution.lengthOfLongestSubstring(str2);
  int res3 = solution.lengthOfLongestSubstring(str3);
  int res4 = solution.lengthOfLongestSubstring(str4);
  int res5 = solution.lengthOfLongestSubstring(str5);

  cout << "str: " << str1 << " output: " << res1 << endl;
  cout << "str: " << str2 << " output: " << res2 << endl;
  cout << "str: " << str3 << " output: " << res3 << endl;
  cout << "str: " << str4 << " output: " << res4 << endl;
  cout << "str: " << str5 << " output: " << res5 << endl;

  return 0;
}