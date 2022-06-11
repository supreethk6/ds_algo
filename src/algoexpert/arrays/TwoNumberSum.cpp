/**********************************************************************************************

Write a function that takes in a non-empty array of distinct integers and an integer 
representing a target sum. If any two numbers in the input array sum up to the target sum, 
the function should return them in an array, in sorted order. If no two numbers sum up to 
the target sum, the function should return an empty array. 

Note that the target sum has to be obtained by summing two different integers in the array; 
you can't add a single integer to itself in order to obtain the target sum.

You can assume that there will be at most one pair of numbers summing up to the target sum.

Sample input: 
array = [3, 5, -4, 8, 11, 1, -1, 6]
targetSum = 10 

Sample output: 
[-1, 11]  --> the numbers could be in reverse order

***********************************************************************************************/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> twoNumberSum (vector<int> array, int targetSum) {
  for (auto i = 0; i < array.size(); i++) {
    for (auto j = 0; j < array.size(); j++) {
      if (array.at(i) + array.at(j) == targetSum && array.at(i) != array.at(j)) {
        return {array.at(i), array.at(j)};
      }
    }
  }
}

int main () {
  cout << "TwoNumberSum output: " << endl;
  vector<int> output = twoNumberSum({3, 5, -4, 8, 11, 1, -1, 6}, 10);
  cout << "[ " ;
  for ( auto i : output) { 
    cout << i << " ";
  }
  cout << " ]" << endl;
}