#include "../../Utils/utils.h"
#include <iomanip>
#include <sstream>
/*
You are building a logic for a clock that requires you convert absolute time in
minutes into a format supported by a digital clock. See examples below.
125 minutes can be displayed as 2:05

155 minutes can be displayed as 2:35


(You can assume the maximum value of minutes will be less than 24 X 60)

Example:
Input

Input is a single integer.

1180
Output

Output is a string denoting the digital clock time.

19:40
*/
class Solution {
public:
  string convert_to_digital_time(int minutes) {
    string time = "";
    int hours = minutes / 60;
    int min = minutes % 60;
    ostringstream oss;
    oss << hours << ":" << std::setw(2) << std::setfill('0') << min;

    return oss.str();
  }
};

int main() {

  Solution solution;
  int minutes = 1180;
  string res = solution.convert_to_digital_time(minutes);
  cout << "input:" << minutes << endl;
  cout << "output:" << res << endl;
  return 0;
}