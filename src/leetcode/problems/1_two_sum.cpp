/**
 * @file 1_two_sum.cpp
 * @author skk
 * @brief 
 * Given an array of integers "nums" and an integer "target", return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 *     2 <= nums.length <= 104
 *     -109 <= nums[i] <= 109
 *     -109 <= target <= 109
 *     Only one valid answer exists.
 * 
 * Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 *
 * @version 0.1
 * @date 2022-10-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

// TODO: Complete this exersise
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
  // initialize map, Here map's key is number and value is index
    unordered_map<int,int> map;
    for(int i = 0;i<nums.size();i++){
      // if we got target - number 
      // return value which is our index and current index
      if(map.find(target-nums[i])!=map.end()){
        return {map[target-nums[i]],i};
      }
      // if we not find any number target-value we we insert current number and it's index in map
      // so that if this number is target - number = this.number then we can return it's index
      map[nums[i]]=i;
    }
    return {0};
  }
};

int main() {
  return 0;
}