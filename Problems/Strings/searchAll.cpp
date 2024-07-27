#include "../../Utils/utils.h"

vector<int> stringSearch(string big, string small) {
  // store the occurrences in the result vector
  vector<int> result;
  int i = 0;
  int occ = big.find(small, i);
  while (occ != string::npos) {
    result.push_back(occ);
    // Update i to start the search from the next character after the found
    // substring
    i = occ + 1;
    occ = big.find(small, i);
  }
  return result;
}

int main() {
  string big =
      "this is a test to check if we find two occurences of the word test";
  string small = "test";
  printArray(stringSearch(big, small));
  return 0;
}