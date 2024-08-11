#include <iostream>
#include <vector>
#include <numeric>
#include <limits.h>
using namespace std;




/*
Oswald and Henry are playing the game of coins.
 They have a row of 'n' coins [C1,C2,C3...Cn] with values [V1,V2,V3...Vn]
  where Ci coin has Vi value. They take turns alternatively. In one turn the player can pick either the first or the last coin of the row.
   Given both Oswald and Henry are very smart players, you need to find the maximum possible value Oswald can earn if he plays first.
*/
int maxValueHelper(vector<int>& vals, int start, int end) {
    // Base Case
    if (start > end) {
        return 0;
    }

    if (start == end) {
        return vals[start];
    }

    // Oswald's optimal choices:
    // Pick the start coin and face the worst-case scenario for the rest
    int pickStart = vals[start] + min(maxValueHelper(vals, start + 2, end),
                                      maxValueHelper(vals, start + 1, end - 1));

    // Pick the end coin and face the worst-case scenario for the rest
    int pickEnd = vals[end] + min(maxValueHelper(vals, start + 1, end - 1),
                                  maxValueHelper(vals, start, end - 2));

    // Return the maximum of these two choices
    return max(pickStart, pickEnd);
}

int MaxValue(int n, vector<int> v){
    return maxValueHelper(v, 0, n - 1);
}

/*
Oswald and Henry are again playing the game of coins. 
They have a row of 'n' coins [C1,C2,C3...Cn] with values [V1,V2,V3...Vn] where Ci coin has Vi value. 
They take turns alternatively. In one turn the player can pick either the first or the last coin of the row and he is supposed to do it 'k' times in a turn. 
Given both Oswald and Henry are very smart players, you need to find the maximum possible value Oswald can earn if he plays first.

Input Format:
In the function you are given an integer N i.e. the number of coins,
 an integer K which is number of pickups in one turn and a vector V which represents the values of each coin in the row respectively.

Output Format:
Return a single integer which is the maximum possible value as asked in the question.
*/
int maxValueHelper(vector<int>& vals, int start, int end, int k) {
    // Base Case
    if (start > end || k == 0) {
        return 0;
    }
    // Oswald's optimal choices:
    for(int i = 1; i<=k ; i++){
        

    }
}

int maxValue2(int n, vector<int> v, int k) {
    return maxValue2Helper(v, 0, n - 1, k);
}

int main(){

/*
Example 1:
Input:
4
1 2 3 4
Output:
6

Example 2:
Input:
6 2
10 15 20 9 2 5
Output:
32
*/
vector<int> v = {1, 2, 3, 4};
cout << MaxValue(4, v) << endl;//6

v = {10, 15, 20, 9, 2, 5};
cout << "MaxValue2: " << maxValue2(6, v, 2) << endl;//32


    return 0;
}