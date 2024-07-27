#include "../../Utils/utils.h"

/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters
in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be
stored in the input character array chars. Note that group lengths that are 10
or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the
array.

You must write an algorithm that uses only constant extra space.
Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be:
["a","2","b","2","c","3"] Explanation: The groups are "aa", "bb", and "ccc".
This compresses to "a2b2c3".

Note: There are two different variant for this
problem . we solve both of them.

*/
class Solution {
public:
  int compress(vector<char> &chars) {
    int write = 0;
    int n = chars.size();

    for (int read = 0; read < n; ++read) {
      int count = 1;
      while (read + 1 < n && chars[read] == chars[read + 1]) {
        ++read;
        ++count;
      }

      chars[write++] = chars[read];

      if (count > 1) {
        string countStr = to_string(count);
        for (char c : countStr) {
          chars[write++] = c;
        }
      }
    }

    return write;
  }

  string compressString(const string &str) {
    if (str.empty()) {
      return str;
    }

    string out;
    char curr = str[0];
    int counter = 1;

    for (size_t i = 1; i < str.size(); ++i) {
      if (str[i] == curr) {
        ++counter;
      } else {
        out += curr;
        out += to_string(counter);
        curr = str[i];
        counter = 1;
      }
    }

    // Add the last character and its count
    out += curr;
    out += to_string(counter);

    return (out.size() < str.size()) ? out : str;
  }
};

int main() {
  /*

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be:
["a","2","b","2","c","3"] Explanation: The groups are "aa", "bb", and "ccc".
This compresses to "a2b2c3".

Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a
single character.

Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be:
["a","b","1","2"]. Explanation: The groups are "a" and "bbbbbbbbbbbb". This
compresses to "ab12".
  */
  vector<char> arr1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  cout << "arr1:" << endl;
  printArray(arr1);
  vector<char> arr2 = {'a'};
  cout << "arr2:" << endl;
  printArray(arr2);
  vector<char> arr3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b',
                       'b', 'b', 'b', 'b', 'b', 'b'};
  cout << "arr3:" << endl;
  printArray(arr3);
  Solution solution;
  int res1 = solution.compress(arr1);
  int res2 = solution.compress(arr2);
  int res3 = solution.compress(arr3);

  cout << "output:" << res1 << endl;
  cout << "output:" << res2 << endl;
  cout << "output:" << res3 << endl;

  string s = "bbbaaaadexxxxxx";
  string res = solution.compressString(s);
  cout << "input: " << s << "output: " << res << endl;

  return 0;
}