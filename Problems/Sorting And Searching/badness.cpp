#include "../../Utils/utils.h"

/*
ICPC Standings
Usually, results of competitions are based on the scores of participants.
However, we are planning a change for the next year of ICPC. During the
registration each team will be able to enter a single positive integer : their
preferred place in the ranklist. We would take all these preferences into
account, and at the end of the competition we will simply announce a ranklist
that would please all of you.

But wait... How would that ranklist look like if it won't be possible to satisfy
all the requests?

Suppose that we already have a ranklist. For each team, compute the distance
between their preferred place and their place in the ranklist. The sum of these
distances will be called the badness of this ranklist.

Goal

Given team names and their preferred placements find one ranklist with the
minimal possible badness.

Input

The input is stored in a vector<pair<string,int> > where the each pair stores
the team name & its preferred rank.

WinOrBooze 1
BallOfDuty 2
WhoKnows 2
BholeChature 1
DCECoders 5
StrangeCase 7
WhoKnows 7
Output

5
*/

/*
Approach: sorting the teams according to their preferred place in the ranklist
Time: O(nlogn)
Space: O(1)
*/
bool compare(const pair<string, int> &a, const pair<string, int> &b) {
  return a.second < b.second;
}
int badness(vector<pair<string, int>> teams) {
  sort(teams.begin(), teams.end(), compare);
  int badness = 0;
  for (int i = 0; i < teams.size(); i++) {
    badness += abs(teams[i].second - 1 - i); // -1 for 0 indexed
  }
  return badness;
}

/*
Approach:
Time: O(n)
Space:
*/
int badnessFast(vector<pair<string, int>> teams) {
  int n = teams.size();
  vector<int> count(
      n + 1,
      0); // count array to store the number of teams preferring each rank

  // Count the number of teams preferring each rank
  for (const auto &team : teams) {
    count[team.second]++;
  }

  int badness = 0;
  int currentRank = 1;

  // Assign teams to ranks and calculate badness
  for (int i = 1; i <= n; i++) {
    while (count[i] > 0) {
      badness += abs(i - currentRank);
      count[i]--;
      currentRank++;
    }
  }

  return badness;
}

int main() {

  /*
  Example:

Input:

WinOrBooze 1
BallOfDuty 2
WhoKnows 2
BholeChature 1
DCECoders 5
StrangeCase 7
WhoKnows 7

Output:
5
  */
  vector<pair<string, int>> teams = {{"WinOrBooze", 1}, {"BallOfDuty", 2},
                                     {"WhoKnows", 2},   {"BholeChature", 1},
                                     {"DCECoders", 5},  {"StrangeCase", 7},
                                     {"WhoKnows", 7}};
  cout << "Output:" << badness(teams) << endl;
  cout << "Output:" << badnessFast(teams) << endl;

  return 0;
}