#include "../../Utils/utils.h"

/*

Along one side of a road there is a sequence of vacant plots of land.
Each plot has different area (non-zero).
the areas form a sequence A[1],A[2],...,A[N].

you want to buy K acres of land to build a house.
you want to find all segments of continuous plots
(subsection int the sequence) of whose sum is exactly k
 */

vector<vector<int>> housing(vector<int> arr, int target) {
  vector<vector<int>> result;
  int n = arr.size();
  int i = 0, j = 0;
  int currWindowSum = 0;

  while (j < n) {
    currWindowSum += arr[j];
    while (currWindowSum > target && i < j) {
      currWindowSum -= arr[i];
      i++;
    }
    if (currWindowSum == target) {
      result.push_back({i, j});
    }
    j++;
  }
  return result;
}
/*
same approach , slightly different method
*/
void housing(int *arr, int n, int k) {
  int i = 0;
  int j = 0;
  int currSum = 0;
  while (j < n) {
    // expand to right
    currSum += arr[j];
    j++;
    // remove elements from the left
    while (currSum > k && i < j) {
      currSum -= arr[i];
      i++;
    }
    // check if sum = target
    if (currSum == k) {
      cout << i << " - " << j - 1 << endl;
    }
  }
}

int main() {
  /*
  Example:
  input : {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2}
  output: {2,5},{4,6},{5,9}
  */
  vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
  int target = 8;
  vector<vector<int>> res = housing(arr, target);
  cout << "arr:" << endl;
  printArray(arr);
  cout << "output:" << endl;
  print2DArray(res);
  // second method
  int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
  int n = sizeof(plots) / sizeof(int);
  int k = 8;
  housing(plots, n, k);
  return 0;
}