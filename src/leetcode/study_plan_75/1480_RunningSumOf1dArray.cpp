/**
 * @file 1480_RunningSumOf1dArray.cpp
 * @author skk
 * @brief 
 * Given an array nums. We define a running sum of an array as 
 * runningSum[i] = sum(nums[0]…nums[i]).
 * 
 * Return the running sum of nums.
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [1,3,6,10]
 * Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
 * 
 * Example 2:
 * Input: nums = [1,1,1,1,1]
 * Output: [1,2,3,4,5]
 * Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
 * 
 * Example 3:
 * Input: nums = [3,1,2,10,1]
 * Output: [3,4,6,16,17]
 * 
 * Constraints:
 * 1 <= nums.length <= 1000
 * -10^6 <= nums[i] <= 10^6
 * 
 * @version 0.1
 * @date 2023-01-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

/**
 * @brief A template function used to print 1d vectors
 * 
 * @tparam T 
 * @param vec input vector
 */
template<typename T>
void printVector(vector<T> &vec) {
  for (T i : vec) {
    cout << i << " ";
  }
  cout << endl;
}

/**
 * @brief A function used for calculating running sum
 * 
 * @param nums input vector
 * @return vector<int> 
 */
vector<int> runningSum(vector<int> &nums) {
  vector<int> result {};
  result.push_back(nums[0]);
  for (int num = 1; num < nums.size(); ++num) {
    result.push_back(nums[num] + result.back());
  }

  return result;
}

int main() {
  vector<int> nums {1, 2, 3, 4};
  vector<int> running_sum = runningSum(nums);
  printVector(running_sum);

  return 0;
}