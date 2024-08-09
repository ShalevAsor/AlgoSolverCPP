#include "../../Utils/utils.h"
#include <numeric>


/*

Game of Greed
You are playing a game with your 'k' friends. 
You have an array of N coins, at each index i you have a coin of value a[i].
Your task is to divide the coins,
among a group of K friends by doing consecutive segments (k-subarrays) of the array.
Each friend will get a total sum of the coins in that subarray.
Since all your friends are greedy, and they will pick the largest k-1 segments and you will get the smallest segment.
Find out the maximum value you can make by making an optimal partition.
Note : The coins array may or may not be sorted!

*/




bool canSplit(const vector<int>& arr, int k, int minSegmentSum) {
    int currentSum = 0;// Current sum of coins in the current segment
    int segments = 0;// Number of segments formed so far

    for (int coin : arr) {// Iterate through the coins
        currentSum += coin;// Add the current coin to the current sum

        if (currentSum >= minSegmentSum) {// If the current sum is greater than or equal to the minimum segment sum
            segments++;// Increment the number of segments
            currentSum = 0;// Reset the current sum for the next segment
        }
    }

    return segments >= k;// Return true if the number of segments is greater than or equal to k
}

int getCoins(vector<int> arr, int k) {
    int low = *min_element(arr.begin(), arr.end());// Minimum possible value for a segment
    int high = accumulate(arr.begin(), arr.end(), 0);// Maximum possible value for a segment
    int result = low;

    while (low <= high) {// Binary search
        int mid = low + (high - low) / 2;

        if (canSplit(arr, k, mid)) {// If it's possible to split the array into k segments with a minimum segment sum of mid
            result = mid;// Update the result to the current mid
            low = mid + 1;// Try to find a larger minimum segment sum (go right)
        } else {// If it's not possible to split the array into k segments with a minimum segment sum of mid
            high = mid - 1;// Try to find a smaller minimum segment sum (go left)
        }
    }

    return result;
}


int main(){

/*
Example:
Input:
K = 3
coins = {1,2,3,4};
Output:
3
*/
    vector<int> coins = {1,2,3,4};
    int k = 3;
    cout << getCoins(coins, k) << endl;//3
    return 0;
}