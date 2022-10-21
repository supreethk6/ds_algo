/**
 * @file 217_contains_duplicate.cpp
 * @author skk
 * @version 0.1
 * @date 2022-10-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * @brief
 * Given an integer array nums, return true if any value appears at least twice in the array, 
 * and return false if every element is distinct.
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 *
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 *
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 * Constraints:
 *    1 <= nums.length <= 105
 *   -109 <= nums[i] <= 109
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unique;

class Solution {
  public:
    void printVector(vector<int> v) {
      for (int i : v)
        std::cout << i << ' ';
      std::cout << '\n';
    }

    bool containsDuplicate(vector<int> &nums) {
      // TODO: add logic 
      printVector(v);
      return 0;
    }
};

int main() {
  Solution sol;
  vector<int> nums {1,2,3,4};
  
  cout << sol.containsDuplicate(nums) << endl;

  return 0;
}