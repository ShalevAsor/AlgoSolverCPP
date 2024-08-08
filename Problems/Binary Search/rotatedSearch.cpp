#include "../../Utils/utils.h"

/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, 
return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[start] <= nums[mid]){ // mid is in the left part
                if(target >= nums[start] && target <= nums[mid]){// target is in the left part
                    end = mid - 1;//go to the left part
                }else{// target is in the right part
                    start = mid + 1;//go to the right part
                }
            }else{// mid is in the right part (nums[mid] < nums[end])
                if(target >= nums[mid] && target <= nums[end]){// target is in the right part
                    start = mid + 1;//go to the right part
                }else{// target is in the left part
                    end = mid - 1;//go to the left part
                }
            }

        }      
        return -1;
    }
};

int main(){
/*
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/
Solution sol;

    vector<int> nums = {4,5,6,7,0,1,2};
    int res = sol.search(nums, 0); // 4
    cout << "res: " << res << endl;
    cout << "res: " << sol.search(nums, 3) << endl; // -1
    nums = {1};
    cout << "res: " << sol.search(nums, 0) << endl; // -1

    return 0;
}



