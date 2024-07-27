#include "../Utils/utils.h"

int main() {
  vector<int> arr;

  // push_back O(1)
  arr.push_back(1);
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(2);

  // Capacity of the vector - (actuall memory allocated) . each time the vector
  // is full , and we push new elements its allocate *2 of the current size
  cout << "The capacity:" << arr.capacity() << endl;
  // Size of the vector
  cout << "The size:" << arr.size() << endl;

  // Print all the elemets
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << endl;
  }
  // remove the last elements - O(1)
  arr.pop_back();
  cout << "The size:" << arr.size() << endl;

  // fill constructor
  // init the array with 10 elemets , each with the value 55
  vector<int> arr2(10, 55);
  for (int i = 0; i < arr2.size(); i++) {
    cout << arr2[i] << ',';
  }
  cout << endl;
  // 2D vector
  vector<vector<int>> arr3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9, 10}, {11, 12}};
  for (int i = 0; i < arr3.size(); i++) {
    for (int j = 0; j < arr3[0].size(); j++) {
      cout << arr3[i][j] << endl;
    }
  }
  // for each loop
  for (int number : arr) {
    cout << number << ",";
  }
  cout << endl;

  // copy
  vector<int> nums = {2, 7, 11, 15};
  vector<int> numsCopy(nums.size());
  copy(nums.begin(), nums.end(), numsCopy.begin());
  printArray(numsCopy);

  return 0;
}