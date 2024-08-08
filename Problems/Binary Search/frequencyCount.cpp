#include "../../Utils/utils.h"

/**
 * Given a sorted array nums and a target value target, 
 * write a function to count the number of occurrences of target in the array.
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: 2
 */


/**
 * Approach: Binary Search
 * 
 * Steps:
 * 1. Perform a binary search to find an occurrence of `target`.
 * 2. Once found, expand to the left and right from the found index to count all occurrences of `target`.
 * 
 * Time Complexity:
 * - O(log n) for the binary search to find an occurrence of `target`.
 * - O(k) to count the occurrences where k is the number of occurrences of `target`.
 * - Overall time complexity is O(log n + k).
 * 
 * Space Complexity:
 * - O(1) since we are using only a few extra variables.
 * 
 * @param nums: A reference to a sorted vector of integers.
 * @param target: The target integer value to count in the vector.
 * @return The number of occurrences of `target` in `nums`.
 */
int frequencyCount(vector<int> & nums,int target){
    int start = 0;
    int end = nums.size() - 1;
    while(start <=end){
        int mid = start + (end - start)/2;
        if(nums[mid]==target){
            int fo = mid;
            int lo = mid;
            while( fo>=0 and nums[fo]==target){
                fo--;
            }
            while(lo<nums.size() and nums[lo]==target){
                lo++;
            }
            return (lo-fo-1);
        }
        else if(nums[mid]< target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

return 0;
}


/**
 * Approach: Binary Search for Lower and Upper Bounds
 * 
 * Steps:
 * 1. Use binary search to find the lower bound (first occurrence) of `target`.
 * 2. Use binary search to find the upper bound (last occurrence) of `target`.
 * 3. Calculate the number of occurrences based on the positions of the lower and upper bounds.
 * 
 * Time Complexity:
 * - O(log n) for finding the lower bound.
 * - O(log n) for finding the upper bound.
 * - Overall time complexity is O(log n).
 * 
 * Space Complexity:
 * - O(1) since we are using only a few extra variables.
 * 
 * @param nums: A reference to a sorted vector of integers.
 * @param target: The target integer value to count in the vector.
 * @return The number of occurrences of `target` in `nums`.
 */
int lowerBound(vector<int> & nums,int target){
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;
    while(start <=end){
        int mid = start + (end - start)/2;
        if(nums[mid]==target){
            ans = mid;
            end = mid-1;
        }
        else if(nums[mid] > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int> & nums,int target){
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;
    while(start <=end){
        int mid = start + (end - start)/2;
        if(nums[mid]==target){
            ans = mid;
            start = mid+1;
        }
        else if(nums[mid] > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int frequencyCount2(vector<int> & nums,int target){
    int lower = lowerBound(nums,target);
    int upper = upperBound(nums,target);
    if(lower == -1){
        return 0;
    }
    return upper - lower + 1;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;
    int res = frequencyCount(nums, target); // 1
    cout << "res1: " << res << endl;
    cout << "res2: " << frequencyCount2(nums, target) << endl;
    vector<int> nums2 = {1,1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
    int target2 = 5;
    int res2 = frequencyCount(nums2, target2); // 5
    cout << "res1: " << res2 << endl;
    cout<<"res2: " << frequencyCount2(nums2, target2) << endl;
    return 0;
}