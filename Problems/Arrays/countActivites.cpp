#include "../../Utils/utils.h"

/*
Busy Life
You are actually very busy person. You have a long list of activities. Your aim
is to finish much as activities as possible.

In the given figure, if you go to date with crush, you cannot participate in the
coding contest and you can’t watch the movie. Also if you play DotA, you can’t
study for the exam. If you study for the exam you can’t sleep peacefully. The
maximum number of activities that you can do for this schedule is 3.

Either you can

watch movie, play DotA and sleep peacefully (or)

date with crush, play DotA and sleep peacefully

Given the start and finish times of activities, print the maximum number of
activities. Input is already store in a vector of pairs. Each pair contains the
start and end of the activity.

Sample Input

(7,9) (0,10) (4,5) (8,9) (4,10) (5,7)

Output
3


*/
class Solution {
public:
  /*
     Solution:


     */
  bool compare(pair<int, int> v1, pair<int, int> v2) {
    return v1.second < v2.second;
  }

  int countActivites(vector<pair<int, int>> v) {
    // Complete this method

    sort(v.begin(), v.end(), compare);
    int count = 1;
    int finish = v[0].second;

    for (int i = 1; i < v.size(); i++) {
      if (v[i].first >= finish) {
        count++;
        finish = v[i].second;
      }
    }
    return count;
  }
};

int main() {
  /*

  Example :
  Input: (7,9) (0,10) (4,5) (8,9) (4,10) (5,7)
  Output: 3

  */
  vector<pair<int, int>> arr = {{7, 9}, {0, 10}, {4, 5},
                                {8, 9}, {4, 10}, {5, 7}};
  Solution solution;
  int res = solution.countActivites(arr);
  cout << "arr:";
  printArray(arr);
  cout << "output:" << res << endl;

  return 0;
}