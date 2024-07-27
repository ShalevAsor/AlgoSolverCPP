#include "../../Utils/utils.h"

// Complete this method, don't write main
vector<string> fizzbuzz(int n) {
  vector<string> results;
  for (int i = 1; i <= n; i++) {
    if (i % 15 == 0) {
      results.push_back("FizzBuzz");
    } else if (i % 5 == 0) {
      results.push_back("Buzz");
    } else if (i % 3 == 0) {
      results.push_back("Fizz");
    } else {
      results.push_back(to_string(i));
    }
  }
  return results;
}
int main() {

  /*
Example:
fizzbuzz(15) == {
"1", "2", "Fizz", "4", "Buzz",
"Fizz", "7", "8", "Fizz", "Buzz",
"11", "Fizz", "13", "14", "FizzBuzz"
}
*/
  const vector<string> res = fizzbuzz(15);
  printArray(res);
  return 0;
}