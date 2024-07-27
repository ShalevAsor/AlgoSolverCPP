#include "../../Utils/utils.h"

/*
Given a palindromic string of lowercase English letters palindrome, replace
exactly one character with any lowercase English letter so that the resulting
string is not a palindrome and that it is the lexicographically smallest one
possible.

Return the resulting string. If there is no way to replace a character to make
it not a palindrome, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if
in the first position where a and b differ, a has a character strictly smaller
than the corresponding character in b. For example, "abcc" is lexicographically
smaller than "abcd" because the first position they differ is at the fourth
character, and 'c' is smaller than 'd'.



Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as
"zbccba", "aaccba", and "abacba". Of all the ways, "aaccba" is the
lexicographically smallest.

*/
class Solution {
public:
  string breakPalindrome(string palindrome) {
    int n = palindrome.size();
    // If the length is 1, we cannot make it non-palindromic
    if (n == 1)
      return "";

    // Iterate through the first half of the string
    for (int i = 0; i < n / 2; ++i) {
      // If we find a character that is not 'a'
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a'; // Change it to 'a'
        return palindrome;   // Return the modified string
      }
    }

    // If all characters in the first half are 'a'
    palindrome[n - 1] = 'b'; // Change the last character to 'b'
    return palindrome;
  }
};
int main() {
  /*

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as
"zbccba", "aaccba", and "abacba". Of all the ways, "aaccba" is the
lexicographically smallest.

Example 2:
test
Input: palindrome = "a"
Output: ""
Explanation: There is no way to replace a single character to make "a" not a
palindrome, so return an empty string.


  */
  string str1 = "abccba";

  string str2 = "a";

  Solution solution;
  string res1 = solution.breakPalindrome(str1);
  string res2 = solution.breakPalindrome(str2);

  cout << "str1: " << str1 << " output: " << res1 << endl;
  cout << "str2: " << str2 << " output: " << res2 << endl;

  return 0;
}