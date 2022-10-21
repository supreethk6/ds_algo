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
    /**
     * @brief Function to test all the vectors and show
     *        the result on the terminal output
     * 
     * @param n Testable integer vector
     */
    void testVector(vector<int> &n) {
      cout << "Vector = ";
      printVector(n);
      if (containsDuplicate(n) == 1) 
        cout << "Yes, vector consists of duplicate values!" << endl;
      else
        cout << "No, vector does not consists of duplicate values!" << endl;  
      cout << endl;

      return;
    }

    /**
     * @brief Print vector type onto the terminal output
     * 
     * @param v Printable integer vector
     */
    void printVector(vector<int> v) {
      for (int i : v)
        cout << i << ' ';
      cout << endl;

      return;
    }

    /**
     * @brief Logic to check if the given integer vector consists of 
     *        any duplicate integer values
     * 
     * @param nums Given integer vector
     * @return true 
     * @return false 
     */
    bool containsDuplicate(vector<int> &nums) {
      for (int i=0; i<nums.size(); ++i) {
        for (int j=0; j<i; ++j) {
          if (nums[j] == nums[i])
            return true;
        }
      }
      
      return false;
    }
};

int main() {
  Solution sol;

  vector<int> nums {1,2,3,1};
  vector<int> nums1 {1,2,3,4};
  vector<int> nums2 {1,1,1,3,3,4,3,2,4,2}; 

  sol.testVector(nums);
  sol.testVector(nums1);
  sol.testVector(nums2);
  
  return 0;
}