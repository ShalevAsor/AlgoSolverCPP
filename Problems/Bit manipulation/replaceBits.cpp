#include "../../Utils/utils.h"

/*
You are given two 32-bit numbers,N and M, and two bit
positions i and j (starting at index j). implement a function that set all
bits between i and j in N equal to M.
(M becomes a substring of N)

Example :
N = 10000000000
M = 10101
i = 2, j = 6
Output : 10001010100
*/

void clearBitsInRange(int &num, int i, int j) {
  int a = (~0) << (j + 1);
  int b = (1 << i) - 1;
  int mask = a | b;
  num = num & mask;
}
void replaceBits(int &num, int i, int j, int m) {
  clearBitsInRange(num, i, j);
  int mask = (m << i);
  num = num | mask;
}

int main() {

  int N = 15;
  int M = 2;
  int i = 1, j = 3;
  replaceBits(N, i, j, M);
  cout << "output: " << N << endl;
  return 0;
}