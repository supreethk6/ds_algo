/**********************************************************************************************
 
Given an array of integers, return a new array with each value doubled.

For example:

[1, 2, 3] --> [2, 4, 6]

***********************************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

std::vector<int> maps(const std::vector<int> & values) {
  std::vector<int> values_copy{values};
  for(int i=0; i<(int)values_copy.size(); i++) {
    values_copy[i]*=2;
  }

  return values_copy;
}

int main() {
  vector<int> values {};
  int v_values;
  cout << "Enter the vector elements and enter 'end' to exit adding vector elements: " << endl;
  while (std::cin >> v_values) {
    values.push_back(v_values);
  }
  vector<int> doubled_vectors = maps(values);
  for(auto j : doubled_vectors) {
    std::cout << j << " ";
  }
  cout << endl;
}