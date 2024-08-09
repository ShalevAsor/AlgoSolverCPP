#include "../../Utils/utils.h"

/*

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket.
 Rick has n empty baskets, the ith basket is at position[i],
  Morty has m balls and needs to distribute the balls into the baskets 
  such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.
*/

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 0;
        int end = position[position.size()-1] - position[0];
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(position, m, mid)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
    bool isPossible(vector<int>& position, int m, int mid){
        int count = 1;
        int lastPos = position[0];//first ball is always in the first basket
        for(int i = 1; i < position.size(); i++){//start from the second ball
            if(position[i] - lastPos >= mid){//if the distance between the current ball and the last ball is greater than or equal to mid
                count++;//add a new basket
                lastPos = position[i];//update the last ball position
            }
        }//if the number of baskets is greater than or equal to m, then it is possible to distribute the balls
        return count >= m;
    }

};



int main(){

/*
Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. 
The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

Example 2:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
*/
Solution sol;
vector<int> position = {1,2,3,4,7};
int m = 3;
int res = sol.maxDistance(position, m);
cout << "res:" << res << endl;//3

position = {5,4,3,2,1,1000000000};
m = 2;
res = sol.maxDistance(position, m);
cout << "res:" << res << endl;//999999999

    return 0;
}