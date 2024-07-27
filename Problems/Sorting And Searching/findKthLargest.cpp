#include "../../Utils/utils.h"
#include <queue>
/*
Given an integer array nums and an integer k, return the kth largest element in
the array.

Note that it is the kth largest element in the sorted order, not the kth
distinct element.

Can you solve it without sorting?

Example:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/
class Solution {
public:
  /*
    Approach: Using a max-heap priority queue and pop k-1 elements in the
   queue Time: O(n log n) Space: O(n)
  */
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    int i = 1;
    int kLargest = 0;
    while (i < k) {
      pq.pop();
      i++;
    }
    return pq.top();
  }
  /*
     Approach: Using a min-heap priority queue of size k
     Time: O(n log k)
     Space: O(k)
   */
  int findKthLargestMinHeap(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
      minHeap.push(num);
      if (minHeap.size() > k) {
        minHeap.pop(); // remove the smallest element
      }
    }
    return minHeap.top(); // return the k'th largest element
  }
  /*
     Approach: Based on quick sort algorithm
     Time: O(n) on average, O(n^2) in the worst case
     Space: O(1)
   */
  int partition(vector<int> &arr, int start, int end) {
    int i = start - 1;
    int pivot = arr[end];
    for (int j = start; j < end; j++) {
      if (arr[j] > pivot) { // note the '>' for kth largest
        i++;
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[i + 1], arr[end]); // set the pivot in the correct position
    return i + 1;
  }

  int quickSelect(vector<int> &arr, int start, int end, int k) {
    int p = partition(arr, start, end);
    if (p == k) { // we found the k'th largest element
      return arr[p];
    } else if (k < p) {
      return quickSelect(arr, start, p - 1, k);
    } else {
      return quickSelect(arr, p + 1, end, k);
    }
  }

  int findKthLargestQuickSelect(vector<int> &nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k - 1);
  }
};

int main() {
  /*
Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
  */
  Solution solution;
  vector<int> arr1 = {3, 2, 1, 5, 6, 4};
  int k1 = 2;
  int res1 = solution.findKthLargest(arr1, k1);
  vector<int> arr2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k2 = 4;
  int res2 = solution.findKthLargest(arr2, k2);

  cout << "input: " << endl;
  printArray(arr1);

  cout << "output: " << res1 << endl;
  cout << "input: " << endl;
  printArray(arr2);

  cout << "output: " << res2 << endl;
  return 0;
}