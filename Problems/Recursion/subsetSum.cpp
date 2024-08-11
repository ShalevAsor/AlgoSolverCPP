#include "../../Utils/utils.h"
/*
Given an array of integers and a target sum, 
find all unique combinations in the array where the sum of the elements in the combination equals the target sum.
*/

/*
Variant 1:
Given an array of integers and a target sum,
Count the number of unique combinations in the array where the sum of the elements in the combination equals the target sum.
*/

int CountSubsetsWithSum(const vector<int>& arr, int targetSum, int index) {
    
//Base case:
    if(targetSum == 0) {
        return 1;
    }
    if(index == arr.size() || targetSum < 0) {
        return 0;
    }
//Recursive case:
    int includeCurrent = CountSubsetsWithSum(arr, targetSum - arr[index], index + 1);
    int excludeCurrent = CountSubsetsWithSum(arr, targetSum, index + 1);
    return includeCurrent + excludeCurrent;

}

/*
Varriant 2:
Given an array of integers and a target sum,
return all unique combinations in the array where the sum of the elements in the combination equals the target sum.
*/

void findCombinations(vector<int>& arr, int targetSum, int index, vector<int>& current, vector<vector<int>>& result) {
    // Base case: If target sum is 0, add the current combination to the result
    if (targetSum == 0) {
        result.push_back(current);
        return;
    }
    
    // If target sum becomes negative or no more elements to process, stop
    if (targetSum < 0 || index == arr.size()) {
        return;
    }
    
    // Include the current element and move to the next
    current.push_back(arr[index]);
    findCombinations(arr, targetSum - arr[index], index + 1, current, result);
    
    // Exclude the current element and move to the next
    current.pop_back();
    findCombinations(arr, targetSum, index + 1, current, result);
}

vector<vector<int>> findAllCombinations(vector<int>& arr, int targetSum) {
    vector<vector<int>> result;
    vector<int> current;
    // Start the recursion from the first index
    findCombinations(arr, targetSum, 0, current, result);
    return result;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int targetSum = 9;
    int result = CountSubsetsWithSum(arr, targetSum, 0);
    cout << "Number of subsets with sum " << targetSum << ": " << result << endl;
    vector<vector<int>> combinations = findAllCombinations(arr, targetSum);
    cout << "Combinations with sum " << targetSum << ":" << endl;
    print2DArray(combinations);
   
return 0;
}