#include "../../Utils/utils.h"

/*
Merge sort algorithm example :

Input : [10,5,2,0,7,6,4]
1.Divide

[10,5,2] and [0,7,6,4]

2.mergeSort(left) and mergeSort(right) (recursively)

[2,5,10] [0,4,6,7]

3.merge into single sorted array

[0,2,4,5,6,7,10]


*/

void merge(vector<int> &arr, int start, int end) {
  vector<int> temp;
  int i = start;
  int m = (start + end) / 2;
  int j = m + 1;
  while (i <= m and j <= end) {
    if (arr[i] < arr[j]) {
      temp.push_back(arr[i]);
      i++;
    } else {
      temp.push_back(arr[j]);
      j++;
    }
  }
  // copy remaining elements from first array
  while (i <= m) {
    temp.push_back(arr[i++]);
  }

  // copy remaining elements from second array
  while (j <= end) {
    temp.push_back(arr[j++]);
  }
  // copy back the elements from temp to original array
  int k = 0;
  for (int idx = start; idx <= end; idx++) {
    arr[idx] = temp[k++];
  }
  return;
}

void mergeSort(vector<int> &arr, int start, int end) {
  // base case
  if (start >= end)
    return;

  // rec case
  int mid = (start + end) / 2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  return merge(arr, start, end);
}

int main() {

  vector<int> arr1 = {5, 4, 3, 2, 1};
  vector<int> arr2 = {1, 5, 2, 4, 3};

  cout << "input: " << endl;
  printArray(arr1);
  cout << "output: " << endl;
  mergeSort(arr1, 0, arr1.size() - 1);
  printArray(arr1);
  cout << "input: " << endl;
  printArray(arr2);
  cout << "output: " << endl;
  mergeSort(arr2, 0, arr2.size() - 1);
  printArray(arr2);

  return 0;
}