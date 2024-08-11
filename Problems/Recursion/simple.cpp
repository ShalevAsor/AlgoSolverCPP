#include "../../Utils/utils.h"
/*
 * Description:
 *    This file contains implementations of simple recursion problems
 *    as part of the AlgoSolver project. Each function in this file 
 *    solves a specific problem using recursive techniques, which are 
 *    fundamental for understanding more complex algorithms. 
 *    The problems covered include basic recursive patterns and are 
 *    intended to build a strong foundation in recursive thinking.
 *
 * Problems:
 * - Counting Ways to Climb a Ladder
 * - Finding All Subsets of a String
 * - Generating Permutations
 * 
 */


/*
 * Problem: Counting Ways to Climb a Ladder
 * Description:
 *    Given a ladder with N steps, you can take a jump of 1, 2, or 3 steps 
 *    at each move. The task is to find the number of different ways to 
 *    reach the top of the ladder (i.e., the Nth step).
 *
 * Example:
 *    Input: N = 3
 *    Output: 4
 *    Explanation:
 *      The four ways to reach the 3rd step are:
 *        1. 1 step + 1 step + 1 step
 *        2. 1 step + 2 steps
 *        3. 2 steps + 1 step
 *        4. 3 steps
 *
 * Approach:
 *    The problem can be solved using a simple recursive approach.
 *    The idea is to consider that to reach the Nth step, you could have 
 *    arrived from either the (N-1)th, (N-2)th, or (N-3)th step. Therefore, 
 *    the number of ways to reach the Nth step is the sum of the ways to reach 
 *    the (N-1)th, (N-2)th, and (N-3)th steps.
 *
 *    The base case occurs when N equals 0, where there is exactly 1 way to 
 *    stay at the ground (by doing nothing). If N becomes negative, it means 
 *    the step is invalid, so the function should return 0.
 *
 * Time Complexity:
 *    The time complexity of this solution is O(3^N), where N is the number 
 *    of steps. This is because at each step, the function makes three 
 *    recursive calls.
 *
 * Space Complexity:
 *    The space complexity is O(N) due to the recursion stack, where N is the 
 *    depth of the recursion. The maximum depth of recursion is equal to the 
 *    number of steps N.
 */

int countWays(int n){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}


/*
 * Problem: Finding All Subsets of a String
 * Description:
 *    Given a string, the task is to find and print all possible subsets 
 *    (or power sets) of the string. A subset is defined as any combination 
 *    of the characters in the string, including the empty set and the set 
 *    containing all characters.
 *
 * Example:
 *    Input: "abc"
 *    Output:
 *      ""
 *      "c"
 *      "b"
 *      "bc"
 *      "a"
 *      "ac"
 *      "ab"
 *      "abc"
 *
 * Approach:
 *    The problem can be solved using a recursive approach. The idea is to 
 *    explore all possible combinations of characters by making a choice at 
 *    each step to either include the current character in the subset or to 
 *    exclude it. The recursion continues until all characters are processed.
 *
 *    The base case occurs when we have processed all characters in the string, 
 *    at which point we print the current subset.
 *
 * Time Complexity:
 *    The time complexity of this solution is O(2^N), where N is the length 
 *    of the string. This is because there are 2^N possible subsets for a 
 *    string of length N.
 *
 * Space Complexity:
 *    The space complexity is O(N), which is the space required for the 
 *    recursion stack. The depth of the recursion stack is equal to the 
 *    length of the string N.
 */

#include <iostream>
#include <string>

using namespace std;

void findSubsets(string &str, string current, int index) {
    if (index == str.length()) {// Base case: all characters processed
        cout << "\"" << current << "\"" << endl;
        return;
    }

    // Exclude the current character and move to the next
    findSubsets(str, current, index + 1);

    // Include the current character and move to the next
    findSubsets(str, current + str[index], index + 1);
}

void findAllSubsets(string str) {
    findSubsets(str, "", 0);
}

/*
 * Problem: Generating All Permutations of an Array
 * Description:
 *    Given an array of distinct integers, the task is to find and return 
 *    all possible permutations of the array. Each permutation should be 
 *    a distinct arrangement of the array elements.
 *
 * Example:
 *    Input: [1, 2, 3]
 *    Output: 
 *      [[1, 2, 3], 
 *       [1, 3, 2], 
 *       [2, 1, 3], 
 *       [2, 3, 1], 
 *       [3, 1, 2], 
 *       [3, 2, 1]]
 *
 * Approach:
 *    The problem can be solved using a backtracking approach. The idea is 
 *    to recursively build permutations by swapping elements at each step.
 *    Each position in the array is swapped with every other position, 
 *    generating all possible arrangements. Once a complete permutation is 
 *    built, it is added to the result list.
 *
 *    The base case occurs when the current index reaches the length of the 
 *    array, indicating a complete permutation has been formed.
 *
 * Time Complexity:
 *    The time complexity of this solution is O(N!), where N is the number 
 *    of elements in the array. This is because there are N! possible 
 *    permutations for an array of length N.
 *
 * Space Complexity:
 *    The space complexity is O(N) for the recursion stack, where N is the 
 *    length of the array. The result list requires O(N * N!) space to store 
 *    all permutations.
 */

void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
    if (start == nums.size()) {// Base case: a permutation is formed
        result.push_back(nums);// Add the permutation to the result
        return;
    }
    for (int i = start; i < nums.size(); ++i) {// Swap elements
        swap(nums[start], nums[i]);
        backtrack(nums, result, start + 1);// Recursively generate permutations
        swap(nums[start], nums[i]); // Restore the original order
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, result, 0);
    return result;
}

/*
write a function to generate all possible n pairs of balanced parentheses. '(' and ')'
*/


void generateParenthesesHelper(int n, int open, int close, string current, vector<string>& result) {
    // Base case: If the current string has reached the length of 2*n
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    
    // If we can still add an open parenthesis
    if (open < n) {
        generateParenthesesHelper(n, open + 1, close, current + "(", result);
    }
    
    // If we can add a close parenthesis (must be less than open)
    if (close < open) {
        generateParenthesesHelper(n, open, close + 1, current + ")", result);
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    generateParenthesesHelper(n, 0, 0, "", result);
    return result;
}

/*
Given a number N and a modern phone keypad. Find out all the possible strings generated using that number.
*/
void generateCombinations(string input,string keypad[],int index,string curr,vector<string> &result){
    //base case: 
    if(index == input.length()){
        result.push_back(curr);
        return;
    }
    //recursive case:
    int currentDigit = input[index] -'0';
    if(currentDigit == 0 || currentDigit == 1){//skip the current digit
        generateCombinations(input,keypad,index + 1,curr,result);
    }
    for(int i = 0; i < keypad[currentDigit].length(); i++){
        generateCombinations(input,keypad,index + 1,curr + keypad[currentDigit][i],result);
    }
}

vector<string> letterCombinations(string digits,string keypad[]){
    vector<string> result;
    generateCombinations(digits,keypad,0,"",result);
    return result;
}

/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

double myPow(double x, int n) {
    if (n == 0) return 1;  // Base case

    double half = myPow(x, n / 2);

    // Handle the exponentiation by squaring
    if (n % 2 == 0) {
        return half * half;
    } else {
        if (n > 0) {
            return x * half * half;
        } else {
            return (half * half) / x;
        }
    }
}
/*
You are given two numbers a and b,
your task is to compute a raised to power b.

As this value can be very large compute it to modulo 1000000007.
*/
long long int powerModulo(int a, int b) {
    const int MOD = 1000000007;
    long long int result = 1;
    long long int base = a % MOD;  // Take the initial modulo to ensure base is within range

    while (b > 0) {// Exponentiation by squaring
        if (b % 2 == 1) {  // If b is odd, multiply result by base and take modulo
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;  // Square the base and take modulo
        b = b / 2;  // Divide b by 2 (right shift by 1)
    }
    return result;
}

int main(){
    cout<< "Counting Ways to Climb a Ladder" << endl;

    int n = 3;
    cout << countWays(n) << endl;//4
    n = 4;
    cout << countWays(n) << endl;//7
    n = 5;
    cout << countWays(n) << endl;//13

    cout<< "Finding All Subsets of a String" << endl;
    string str = "abc";
    findAllSubsets(str);
    cout << "Generating Permutations" << endl;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);
    print2DArray(permutations);
    cout << "Generating All Possible Parentheses Combinations" << endl;
    printArray(generateParentheses(3));
     cout <<"Keypad Problem" << endl;
    string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string input = "23";
    vector<string> combinations = letterCombinations(input, keypad);
    printArray(combinations);
    cout<< "Power Function" << endl;
    cout << myPow(2.0, 10) << endl;//1024
    cout << myPow(2.1, 3) << endl;//9.261
    cout << myPow(2.0, -2) << endl;//0.25
    cout<< "Modulo Exponentiation" << endl;
    cout << powerModulo(2, 10) << endl;//1024
    cout << powerModulo(5,3) << endl;//125
    return 0;
}