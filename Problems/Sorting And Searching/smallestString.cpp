#include "../../Utils/utils.h"
/*
You are given a list of n strings a1,a2,...,an .
you'd like you concatenate them together in some order s.t
the resulting string would be lexicographically smallest.
Given the list of string , output the lexicographically smallest concatenation

Example:
Input: a,ab,aba
Output:aabaab

*/

/*
Approach: Use custom comparator , if a+b < b+a then a comes before b
Time: O(nlogn)
Space:O(1)
*/
//
bool compare(const string &a, const string &b) { return (a + b) < (b + a); }
string smallestString(string arr[], int n) {
  string str = "";
  sort(arr, arr + n, compare);
  for (int i = 0; i < n; i++) {
    str += arr[i];
  }
  return str;
}
int main() {

  string arr[] = {"a", "ab", "aba"};
  int n = sizeof(arr) / sizeof(arr[0]);
  string output = smallestString(arr, n);
  cout << "input: " << arrayToString(arr, n) << endl;
  cout << "output: " << output << endl;
}