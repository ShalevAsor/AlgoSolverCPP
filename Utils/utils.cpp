#include "utils.h"

// Template function definition
template <typename T> void printArray(const vector<T> &arr) {
  for (size_t i = 0; i < arr.size(); ++i) {
    cout << arr[i];
    if (i != arr.size() - 1) {
      cout << ", ";
    }
  }
  cout << std::endl;
}
template <typename T> T getIndex(const vector<T> &arr, T target) {
  auto it = find(arr.begin(), arr.end(), target);
  int index = -1;
  // If element was found
  if (it != arr.end()) {

    // calculating the index
    // of K
    index = it - arr.begin();
  }
  return index;
}
template <typename T> string vectorToString(const vector<T> &vec) {
  string result = "[";
  for (int i = 0; i < vec.size(); i++) {
    result += to_string(vec[i]);
    if (i < vec.size() - 1) {
      result += ", ";
    }
  }
  result += "]";
  return result;
}
template <typename T> void print2DArray(const std::vector<vector<T>> &arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << vectorToString(arr[i]);
    if (i < arr.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}
template <typename T> string arrayToString(T arr[], int size) {
  stringstream ss;
  ss << "[";
  for (int i = 0; i < size; ++i) {
    ss << arr[i];
    if (i < size - 1) {
      ss << ", ";
    }
  }
  ss << "]";
  return ss.str();
}
template <typename T> bool equals(const vector<T> &a, const vector<T> &b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}