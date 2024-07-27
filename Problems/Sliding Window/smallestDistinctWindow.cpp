#include "../../Utils/utils.h"

/*
Given a string, find the smallest window (substring) which contains all distinct
characters of the given input string.

Sample Inputs

aabcbcdbcaaad
aaaa
Sample Outputs

dbca
a

*/
class Solution {
public:
  string minWindow(string str) {
    // Set of all distinct characters in the string
    unordered_set<char> uniqueChars(str.begin(), str.end());
    int required = uniqueChars.size();

    // Frequency map for characters in the current window
    unordered_map<char, int> windowCounts;
    int l = 0, r = 0;
    int formed = 0; // number of unique characters in the current window with
                    // correct frequency
    int minLen = INT_MAX, start = 0;

    while (r < str.size()) {
      char c = str[r];
      windowCounts[c]++;

      if (windowCounts[c] ==
          1) { // We found a unique character with correct frequency
        formed++;
      }

      // Try to contract the window
      while (l <= r && formed == required) {
        c = str[l];
        if (r - l + 1 < minLen) {
          minLen = r - l + 1;
          start = l;
        }

        windowCounts[c]--;
        if (windowCounts[c] ==
            0) { // Unique character frequency is not satisfied
          formed--;
        }
        l++;
      }
      r++;
    }

    return minLen == INT_MAX ? "" : str.substr(start, minLen);
  }
};
int main() {
  /*

Sample Inputs

aabcbcdbcaaad
aaaa
Sample Outputs

dbca
a


  */
  vector<string> s = {"aabcbcdbcaaad", "aaaa"};

  Solution solution;
  for (int i = 0; i < s.size(); ++i) {
    string res = solution.minWindow(s[i]);
    cout << "input" << (i + 1) << ": " << s[i] << " output" << (i + 1) << ": "
         << res << endl;
  }

  return 0;
}