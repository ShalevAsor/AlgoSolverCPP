#include "../../Utils/utils.h"
/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/

class Solution {
public:
/*
Approach:
1. **Binary Search for Square Root:**
   - The problem can be solved using binary search to efficiently find the integer part of the square root of `x`.
   - The search space is between 0 and `x`.
   - Calculate the mid-point and check if `mid * mid` equals `x`. If true, `mid` is the exact square root.
   - If `mid * mid` is less than `x`, it means the square root is larger, so move the search to the right half of the current search space. Store `mid` as the potential answer (`ans`).
   - If `mid * mid` is greater than `x`, move the search to the left half to find a smaller square root.
   - Continue this process until the search space is exhausted. The value stored in `ans` will be the integer part of the square root.

Time Complexity: O(log x)
- The binary search runs in O(log x) time, which is efficient for large values of `x`.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space, making it space-efficient.
*/
   

    int mySqrt(int x) {
        int start = 0;
        int end = x;
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid*mid == x){
                return mid;
            }
            if(mid*mid <x){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};

/*
Problem Description:
Given an integer `N` and a precision `P`, the task is to find the square root of `N` up to `P` decimal places. The solution involves finding both the integer and fractional parts of the square root.

Approach:
1. **Binary Search for Integer Part:**
   - Use binary search to find the integer part of the square root of `N`. The search space is between 0 and `N`.
   - The mid-point is calculated, and if the square of `mid` is equal to `N`, then `mid` is the exact square root.
   - If the square of `mid` is less than `N`, the search moves to the right half (to find a larger integer).
   - Otherwise, it moves to the left half (to find a smaller integer).
   - The integer part of the square root is stored in the variable `ans`.

2. **Linear Search for Decimal Part:**
   - After finding the integer part, use a linear search to refine the square root up to `P` decimal places.
   - Start by adding small increments (starting from 0.1) to `ans` and check if the square of `ans` is still less than or equal to `N`.
   - When `ans * ans` exceeds `N`, undo the last increment and reduce the increment size by a factor of 10.
   - Repeat this process for `P` decimal places.

Time Complexity: O(log N + P)
- The binary search runs in O(log N) time to find the integer part.
- The linear search runs in O(P) time to find the decimal part.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space.
*/

float squareRoot(int N,int P){
    int start = 0;
    int end = N;
    float ans = 0;
    //Binary Search for the integer part (Search space is [0, N])
    while(start <= end){
        int mid = start + (end - start)/2;
        if(mid*mid == N){
            return mid;
        }
        if(mid*mid < N){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    //Linear Search for the decimal part
    float inc = 0.1;
    for(int place = 1; place <= P; place++){
        while(ans*ans <= N){
            ans += inc;
        }
        ans -= inc;//undo the last increment
        inc /= 10;//decrease the decimal place
    }
    return ans;
}

int main(){

/*
Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

Solution sol;
int x = 4;
int res = sol.mySqrt(x);
cout << "res1: " << res << endl;//2
cout << "res2: " << squareRoot(x, 2) << endl;//2.00
x = 8;
res = sol.mySqrt(x);
cout << "res1: " << res << endl;//2
cout << "res2: " << squareRoot(x, 2) << endl;//2.82
return 0;
}