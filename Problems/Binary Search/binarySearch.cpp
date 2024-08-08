#include "../../Utils/utils.h"

/**
 * @brief Binary Search
 * @param nums
 * @param target
 * @return int
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 */
int binarySearch(vector<int> & nums,int target){
    int n = nums.size();
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left + (right - left)/2; // to avoid overflow - equivalent to (left + right)/2
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}




int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;
    int res = binarySearch(nums, target); // 4
    cout << "res: " << res << endl; 
    return 0;
}