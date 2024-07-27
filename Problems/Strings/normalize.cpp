#include "../../Utils/utils.h"
#include <cctype> // for tolower and toupper functions

/*
You are given a sentence with words separated by spaces.

Your task is to:

Write a function that returns a copy of this sentence where all the words:

start with a capital letter

the rest of the letters are lower case

Note:

Your function should not modify the sentence given as argument.

Sample Input

This is SO MUCH FUN!
Sample Output

This Is So Much Fun!

*/
class Solution {
public:
  string normalize(const string &sentence) {
    string copy = sentence;
    int n = copy.size();

    if (n == 0) {
      return copy;
    }

    bool newWord = true;

    for (int i = 0; i < n; i++) {
      if (newWord && isalpha(copy[i])) {
        copy[i] = toupper(copy[i]);
        newWord = false;
      } else {
        copy[i] = tolower(copy[i]);
      }

      if (copy[i] == ' ') {
        newWord = true;
      }
    }

    return copy;
  }
};
int main() {
  /*

Example 1:

Sample Input

This is SO MUCH FUN!
Sample Output

This Is So Much Fun!


  */
  string str = "This is SO MUCH FUN!";

  Solution solution;
  string res = solution.normalize(str);

  cout << "str1: " << str << " output: " << res << endl;

  return 0;
}