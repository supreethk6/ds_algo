/**
 * @file MaxSubsetSumNoAdjacent.cpp
 * @author skk
 * @brief 
 * 
 * Write a function that takes in an array of positive integers and 
 * returns the maximum sum of non-adjacent elements in the array.
 * 
 * If the input array is empty, the function should return 0.
 * 
 * Sample Input
 * array = [75, 105, 120, 75, 90, 135]
 * 
 * Sample Output
 * 330 // 75 + 120 + 135
 *  
 * @version 0.1
 * @date 2023-01-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::max;

/**
 * @brief return the maximum sum of non-adjacent elements in the array
 * 
 * @param array 
 * @return int 
 */
int maxSubsetSumNoAdjacent(vector<int> array) {
	if (array.size() == 0) return 0;
	if (array.size() == 1) return array[0];
	int firstMaxSum = array[0];
	int secondMaxSum = max(firstMaxSum, array[1]);
	for (int i = 2; i < array.size(); i++) {
		int curr = max(secondMaxSum, firstMaxSum + array[i]);
		firstMaxSum = secondMaxSum;
		secondMaxSum = curr;
	}
	return secondMaxSum;
}

int main() {
	vector<int> input {75, 105, 120, 75, 90, 135};
	cout << maxSubsetSumNoAdjacent(input) << endl;
	return 0;
}