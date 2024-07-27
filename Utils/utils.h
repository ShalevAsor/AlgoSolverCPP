#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// Function declaration
template <typename T> void printArray(const std::vector<T> &arr);
template <typename T> void print2DArray(const std::vector<vector<T>> &arr);
template <typename T> T getIndex(const vector<T> &arr, T target);
template <typename T> string vectorToString(const vector<T> &vec);
template <typename T> string arrayToString(T arr[], int size);
#include "utils.cpp" // Include the implementation

#endif // UTILS_H