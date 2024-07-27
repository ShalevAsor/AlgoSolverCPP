#include <bits/stdc++.h>
using namespace std;
/*
Earth Levels
The Planet Earth is under a threat from the aliens of the outer space and your
task is to defeat an enemy who is N steps above you (assume yourself to be at
ground level i.e. at the 0th level). You can take jumps in power of 2. In order
to defeat the enemy as quickly as possible you have to reach the Nth step in
minimum moves possible.

Input Format

In the function an integer is passed.

Output Format

Return an integer representing minimum jumps.



Sample Input

7


Sample Output

3


Explanation

0 -> 4 -> 6 -> 7

*/

int earthLevel(int k) {
  int bitPosition = 0; // To keep track of the bit position
  int moves = 0;
  while (k > 0) {
    if ((k & 1) != 0) {
      // bit at position bitPosition is 1
      moves++;
    }
    k >>= 1; // Shift right by 1 to process the next bit
    bitPosition++;
  }
  return moves;
}

int main() {

  int k = 7;
  int res = earthLevel(k);
  cout << "input: " << k << " output: " << res << endl;

  return 0;
}