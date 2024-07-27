#include "../../Utils/utils.h"

/*
We define the usage of capitals in a word to be right when one of the following
cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.



Example:

Input: word = "USA"
Output: true

*/
class Solution {
public:
  bool detectCapitalUse(const string &word) {
    if (word.size() <= 1) {
      return true;
    }
    int firstLetter = word[0];
    if (isupper(firstLetter)) {
      return handleUpper(word);
    } else {
      return handleLower(word);
    }
  }

  bool handleUpper(const string &word) {
    int counter = 1;
    for (int i = 1; i < word.size(); i++) {
      if (isupper(word[i])) {
        counter++;
      }
    }
    if (counter == 1 or counter == word.size()) {
      return true;
    }
    return false;
  }
  bool handleLower(string word) {
    for (int i = 1; i < word.size(); i++) {
      if (isupper(word[i])) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  /*

Example 1:

Input: word = "USA"
Output: true

Example 2:

Input: word = "FlaG"
Output: false


  */
  string str1 = "USA";
  string str2 = "FlaG";

  Solution solution;
  bool res1 = solution.detectCapitalUse(str1);
  bool res2 = solution.detectCapitalUse(str2);

  cout << "str1: " << str1 << " output: " << res1 << endl;
  cout << "str2: " << str2 << " output: " << res2 << endl;

  return 0;
}