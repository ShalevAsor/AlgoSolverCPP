#include "../../Utils/utils.h"

/*
This demo demonstrates bit manipulation techniques

*/

int getIthBit(int num, int pos) {
  int mask = (1 << pos); // left shift so the only bit with 1 will be in pos
  return (num & mask) > 0 ? 1 : 0;
}
void setIthBit(int &num, int pos) {
  int mask = (1 << pos);
  num = (num | mask);
}
void clearIthBit(int &num, int pos) {
  int mask = ~(1 << pos);
  num = (num & mask);
}
void updateIthBit(int &num, int pos, int val) {
  clearIthBit(num, pos);
  int mask = (val << pos);
  num = num | mask; // set the right val
}
void clearLastIBits(int &num, int pos) {
  int mask = (-1 << pos);

  num = num & mask;
}
bool isPowerOfTwo(int &num) { return ((num - 1) & (num)) == 0; }
/*
return the number of set bits (1's)
O(log(n))
*/
int countBits(int n) {
  int count = 0;
  while (n > 0) {

    int lastBit = (n & 1);
    count += lastBit;
    n = (n >> 1);
  }
  return count;
}
/*
return the number of set bits (1's)
O(m) where m is the amount of set bits
*/
int countBitsFast(int n) {
  int count = 0;
  while (n > 0) {
    // removes the last set bit from the current number
    n = n & (n - 1);
    count++;
  }
  return count;
}
/*
calc exponentiation in O(log(n))
*/
int fastExponentiation(int a, int n) {
  int ans = 1;
  while (n > 0) {
    int lastBit = (n & 1);
    if (lastBit) { // the last bit is 1
      ans *= a;
    }
    a = a * a;
    n = (n >> 1); // discard 1 bit from the right
  }
  return ans;
}
int decimalToBinary(int num) {
  int power = 0;
  int ans = 0;
  while (num > 0) {
    int rem = num % 2;
    num = num / 2;
    ans += rem * fastExponentiation(10, power);
    power++;
  }
  return ans;
}

int main() {
  cout << "bitwise operators" << endl;
  int a = 0;
  cout << (~a) << endl; // -1

  // Binary left shift - each left shift is like multiply by two
  a = 5;
  cout << (a << 2) << endl; // 20 = 5 * 2^2
  // Binary right shift - each right shift is like divide by two
  a = 10;
  cout << (a >> 1) << endl; // 5 = 10 / 2
  a = 20;
  cout << (a >> 2) << endl; // 5 = 20 / 2^2
  cout << "check even or odd" << endl;
  // check even or odd (Bitwise)
  // even numbers -last bit is zero . odd numbers - last bit is 1
  a = 10;
  if (a & 1) { // find out the last bit
    cout << "Odd" << endl;
  } else {
    cout << "Even" << endl;
  }

  // get i'th bit
  cout << "get i'th bit" << endl;
  // the 2 bit here : 000101 is 000[1]01 . we count from right to left
  a = 5;
  cout << "num: " << a << " output: " << getIthBit(a, 2) << endl;
  cout << "num: " << a << " output: " << getIthBit(a, 0) << endl;
  cout << "num: " << a << " output: " << getIthBit(a, 1) << endl;

  // set i'th bit
  a = 5;
  cout << "set i'th bit" << endl;
  cout << "num: " << a << endl;
  setIthBit(a, 1);
  cout << "new num: " << a << endl; // 7
  cout << "clear i'th bit" << endl;
  a = 7;
  cout << "num: " << a << endl;
  clearIthBit(a, 1);
  cout << "new num: " << a << endl; // 5
  cout << "update i'th bit" << endl;
  a = 4;
  cout << "num: " << a << endl;
  updateIthBit(a, 0, 1);
  cout << "new num: " << a << endl; // 5
  a = 4;
  cout << "num: " << a << endl;
  updateIthBit(a, 1, 1);
  cout << "new num: " << a << endl; // 6
  a = 4;
  cout << "num: " << a << endl;
  updateIthBit(a, 2, 0);
  cout << "new num: " << a << endl; // 0
  cout << "clear last i bits" << endl;
  a = 7;
  cout << "num: " << a << endl;
  clearLastIBits(a, 2);
  cout << "new num: " << a << endl; // 4
  cout << "is power of 2" << endl;
  a = 8;
  cout << "num: " << a << endl;
  bool res = isPowerOfTwo(a);
  cout << "output: " << res << endl; // true
  a = 7;
  cout << "num: " << a << endl;
  res = isPowerOfTwo(a);
  cout << "output: " << res << endl; // false
  cout << "count bits" << endl;
  a = 7;
  cout << "num: " << a << endl;
  int setBits = countBits(a);
  cout << "output: " << setBits << endl; // 3
  a = 4;
  cout << "num: " << a << endl;
  setBits = countBits(a);
  cout << "output: " << setBits << endl; // 1
  cout << "count bits fast" << endl;
  a = 7;
  cout << "num: " << a << endl;
  setBits = countBitsFast(a);
  cout << "output: " << setBits << endl; // 3
  a = 4;
  cout << "num: " << a << endl;
  setBits = countBitsFast(a);
  cout << "output: " << setBits << endl; // 1
  cout << "fast exponentiation" << endl;
  a = 4;
  cout << "num: " << a << endl;
  int ans = fastExponentiation(a, 2);
  cout << "output: " << ans << endl; // 16
  cout << "num: " << a << endl;
  ans = fastExponentiation(a, 3);
  cout << "output: " << ans << endl; // 64
  cout << "num: " << a << endl;
  ans = fastExponentiation(a, 0);
  cout << "output: " << ans << endl; // 1
  cout << "decimal to binary" << endl;
  a = 4;
  cout << "num: " << a << endl;
  ans = decimalToBinary(a);
  cout << "output: " << ans << endl; // 100
  a = 7;
  cout << "num: " << a << endl;
  ans = decimalToBinary(a);
  cout << "output: " << ans << endl; // 111
  a = 10;
  cout << "num: " << a << endl;
  ans = decimalToBinary(a);
  cout << "output: " << ans << endl; // 1010

  return 0;
}