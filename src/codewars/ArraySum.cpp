/**********************************************************************************************

Get the sum of two arrays... actually the sum of all their elements.

P.S. Each array includes only integer numbers. Output is a integer too.

***********************************************************************************************/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int arrayPlusArray(vector<int> a, vector<int> b) {
  int sum_a = 0, sum_b = 0;
  for (int i : a) {
    sum_a += i;
  }
  for (int j : b) {
    sum_b += j;
  }
  return sum_a + sum_b; 
}

int main() {
  cout << arrayPlusArray({1, 2, 3}, {4, 5, 6}) << endl;
  cout << arrayPlusArray({1, -2, -3}, {4, -5, 6}) << endl;
}