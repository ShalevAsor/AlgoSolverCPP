#include "../../Utils/utils.h"
#include <limits.h>


/*
Given two non-empty arrays, find the pair of numbers (one from each array)
whose absolute difference is minimum.
print the any one pair with the smallest difference.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> minPair(vector<int>& a1, vector<int>& a2) {
    sort(a2.begin(), a2.end());// Sort the second array (not matter which)
    int p1 = 0, p2 = 0;// Initialize pointers
    int diff = INT_MAX;

    for (const int num : a1) {// Iterate through the first array
        auto lb = lower_bound(a2.begin(), a2.end(), num);// Find the lower bound of num in the second array

        // Check the smaller element (left of lb)
        if (lb != a2.begin()) {// If lb is not the first element then check the left element
            int left = *(lb - 1); // Get the left element
            if (num - left < diff) {// If the difference is smaller than the current difference
                diff = num - left;// Update the difference and the pair
                p1 = num;
                p2 = left;
            }
        }

        // Check the greater element (at or right of lb)
        if (lb != a2.end()) {// If lb is not the last element then check the right element
            int right = *lb;// Get the right element
            if (right - num < diff) {// If the difference is smaller than the current difference
                diff = right - num;// Update the difference and the pair
                p1 = num;
                p2 = right;
            }
        }
    }

    cout << "MIN DIFF: " << diff << " Pair: {" << p1 << ", " << p2 << "}" << endl;
    return {p1, p2};
}




int main(){

/*
Example 1:
Input: 
a1 = [-1,5,10,20,3]
a2 = [26,134,135,15,17]
Output:
[20,17]
Explanation:
20 and 17 have the smallest difference.
*/    

    vector<int> a1 = {-1,5,10,20,3};
    sort(a1.begin(), a1.end());
    printArray(a1);
    vector<int> a2 = {26,134,135,15,17};
    vector<int> res = minPair(a1, a2);
    cout << "res:" << endl;
    printArray(res);
    return 0;
}