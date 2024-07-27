#include "../../Utils/utils.h"

/*
Given a string , write a function to replace all spaces in a string with "%20".
ot os govem that the string has sufficient space at the end to hold the
additional characters.


Sample Input:
hello world, how are you?
Output:
hello%20world,%20how%20are%20you?

*/
class Solution {
public:
  /*
     Solution:


     */

  void replaceSpace(char *str) {
    const char target = ' ';
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == target) {
        spaces++;
      }
    }
    int index = strlen(str) + (2 * spaces);
    str[index] = '\0';
    for (int i = strlen(str) - 1; i >= 0; i--) {
      if (str[i] == target) {
        str[index - 1] = '0';
        str[index - 2] = '2';
        str[index - 3] = '%';
        index -= 3;
      } else {
        str[index - 1] = str[i];
        index--;
      }
    }
  }
};

int main() {
  /*

 Sample Input:
hello world, how are you?
Output:
hello%20world,%20how%20are%20you?
  */
  Solution solution;
  char input[10000];
  cin.getline(input, 10000);
  solution.replaceSpace(input);

  cout << "output:" << input << endl;

  return 0;
}