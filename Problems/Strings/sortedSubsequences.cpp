#include "../../Utils/utils.h"

/*
Given a string,you need to print all subsequneces of the string
sorted by length and lexicographic sorted order
if legth is the same



Example :

Input: str = "abcd"
Output: ,a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,bcd,abcd

*/
class Solution {
public:
  void allsubsetsSorted(string str, string output, vector<string> &v) {
    // base case
    if (str.size() == 0) { // we are at a leaf node
      v.push_back(output);
      return;
    }
    // recursive case
    char ch = str[0];
    string reducedInput = str.substr(1);
    // include current letter
    allsubsetsSorted(reducedInput, output + ch, v);
    // exclude current letter
    allsubsetsSorted(reducedInput, output, v);
  }
};
bool compare(string s1, string s2) {
  if (s1.length() == s2.length()) {
    return s1 < s2; // lexicographic
  }
  return s1.length() < s2.length(); // size
}
int main() {

  Solution solution;

  string s;
  cin >> s;
  vector<string> v;
  string output = "";
  solution.allsubsetsSorted(s, output, v);
  sort(v.begin(), v.end(), compare);
  for (const auto s : v) {
    cout << s << ",";
  }
  return 0;
}