#include "../../Utils/utils.h"

/*
Given a list of n strings, s0,s1,...,sn-1. each consisting of digits and spaces
, the number of spaces is the same for each entry
the goal is to implement a variation of a sort command. None of the strings
contains consecutive spaces.also no string start with space nor end with it.
spaces are used to divide string into columns which can be used as keys in
comprasions.


Example:

Input:
3
92 022
82 12
77 13
2 false numeric
Output:
82 12
77 13
92 022

*/
int convertToInt(string s) {
  int ans = 0;
  int p = 1;
  for (int i = s.length() - 1; i >= 0; i--) {
    ans += ((s[i] - '0') * p);
    p *= 10;
  }
  return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
  string key1, key2;
  key1 = s1.second;
  key2 = s2.second;
  return convertToInt(key1) < convertToInt(key2);
}
bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
  string key1, key2;
  key1 = s1.second;
  key2 = s2.second;
  return key1 < key2;
}
string extractStringAtKey(string str, int key) {
  // string tokeniser
  char *s = strtok((char *)str.c_str(), " ");
  while (key > 1) {
    s = strtok(NULL, " ");
    key--;
  }
  return (string)s;
}
class Solution {
public:
  string sortString(int key, vector<string> &arr, string) { return ""; }
};

int main() {
  /*

Example:

Input:
s1= "92 022"
s2= "82 12"
s3= "77 13"
2 false numeric
Output:
"82 12"
"77 13"
"92 022"

  */
  //   string s1 = "92 022";
  //   string s2 = "82 12";
  //   string s3 = "77 13";
  //   vector<string> arr = {s1, s2, s3};
  //   Solution solution;
  //   string res = solution.sortString(arr);

  //   cout << "arr:";
  //   printArray(arr);
  //   cout << "output:" << res << endl;
  int n;
  cin >> n;
  cin.get(); // consume the extra \n
  string temp;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    getline(cin, temp); // include white spaces
    v.push_back(temp);
  }
  int key;
  string reversal, ordering;
  cin >> key >> reversal >> ordering;

  // 1. extract keys for comprasion and store them
  vector<pair<string, string>> vp;
  for (int i = 0; i < n; i++) {
    vp.push_back({v[i], extractStringAtKey(v[i], key)});
  }
  // 2.sorting
  if (ordering == "numeric") {
    sort(vp.begin(), vp.end(), numericCompare);
  } else {
    sort(vp.begin(), vp.end(), lexicoCompare);
  }
  // 3.reversale
  if (reversal == "true") {
    reverse(vp.begin(), vp.end());
  }
  // 4.output
  for (int i = 0; i < n; i++) {
    cout << vp[i].first << endl;
  }
  return 0;
}