#include "../../Utils/utils.h"

/*
Given an array of integers. Find the Inversion Count in the array.  Two array
elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the
array is from being sorted. If the array is already sorted then the inversion
count is 0. If an array is sorted in the reverse order then the inversion count
is the maximum.

Example :
Input: n = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions
 (2, 1), (4, 1), (4,3).


*/
// Merge function to count inversions and merge two halves
long long merge(long long arr[], int start, int mid, int end) {
  vector<long long> temp;
  int i = start;
  int j = mid + 1;
  long long cnt = 0;

  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      temp.push_back(arr[i]);
      i++;
    } else {
      cnt += (mid - i + 1);
      temp.push_back(arr[j]);
      j++;
    }
  }

  // Copy remaining elements from first half
  while (i <= mid) {
    temp.push_back(arr[i++]);
  }

  // Copy remaining elements from second half
  while (j <= end) {
    temp.push_back(arr[j++]);
  }

  // Copy back the elements from temp to original array
  for (int idx = start; idx <= end; idx++) {
    arr[idx] = temp[idx - start];
  }

  return cnt;
}

// Recursive function to count inversions using merge sort
long long inversionCounter(long long arr[], int start, int end) {
  if (start >= end)
    return 0;

  int mid = (start + end) / 2;
  long long C1 = inversionCounter(arr, start, mid);
  long long C2 = inversionCounter(arr, mid + 1, end);
  long long CI = merge(arr, start, mid, end);

  return (C1 + C2 + CI);
}

// Function to count inversions in the array
long long int inversionCount(long long arr[], int n) {
  return inversionCounter(arr, 0, n - 1);
}

int main() {
  /*
  Examples:
  Input: n = 5, arr[] = {2, 4, 1, 3, 5}
  Output: 3
  Input: n = 5, arr[] = {2, 3, 4, 5, 6}
  Output: 0
  Input: n = 3, arr[]= {10, 10, 10}
  Output: 0
  */
  long long arr1[] = {2, 4, 1, 3, 5};
  int n1 = 5;
  long long arr2[] = {2, 3, 4, 5, 6};
  int n2 = 5;
  long long arr3[] = {10, 10, 10};
  int n3 = 3;

  cout << "input: " << arrayToString(arr1, n1) << endl;

  cout << "output: " << inversionCount(arr1, n1) << endl;
  cout << "input: " << arrayToString(arr2, n2) << endl;

  cout << "output: " << inversionCount(arr2, n2) << endl;
  cout << "input: " << arrayToString(arr3, n3) << endl;

  cout << "output: " << inversionCount(arr3, n3) << endl;
  return 0;
}