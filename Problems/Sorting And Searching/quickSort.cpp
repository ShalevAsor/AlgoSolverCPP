#include "../../Utils/utils.h"

/*
Quick Sort :
Divide and conquer algorithm.
1.choose a pivot  (in this implementation we choose the last element)
2.partition
3.recursively sort left and right
*/

int partition(vector<int> &arr, int start, int end) {
  int i = start - 1;
  int pivot = arr[end];
  for (int j = start; j < end; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[end]); // set the pivot in the correct position
  return i + 1;
}
void quickSort(vector<int> &arr, int start, int end) {
  // base case
  if (start >= end)
    return;

  // recursive case
  int p = partition(arr, start, end);
  quickSort(arr, start, p - 1);
  quickSort(arr, p + 1, end);
}

int main() {

  vector<int> arr1 = {5, 4, 3, 2, 1};
  vector<int> arr2 = {1, 5, 2, 4, 3};
  vector<int> arr3 = {1};
  vector<int> arr4 = {};

  cout << "input: " << endl;
  printArray(arr1);
  cout << "output: " << endl;
  quickSort(arr1, 0, arr1.size() - 1);
  printArray(arr1);
  cout << "input: " << endl;
  printArray(arr2);
  cout << "output: " << endl;
  quickSort(arr2, 0, arr2.size() - 1);
  printArray(arr2);
  cout << "input: " << endl;
  printArray(arr3);
  cout << "output: " << endl;
  quickSort(arr3, 0, arr3.size() - 1);
  printArray(arr3);
  cout << "input: " << endl;
  printArray(arr4);
  cout << "output: " << endl;
  quickSort(arr4, 0, arr4.size() - 1);
  printArray(arr4);

  return 0;
}