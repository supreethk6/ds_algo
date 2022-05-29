/************************************************************************************************************************

Your task is to sum the differences between consecutive pairs in the array in descending order.
Example

[2, 1, 10]  -->  9

In descending order: [10, 2, 1]

Sum: (10 - 2) + (2 - 1) = 8 + 1 = 9

If the array is empty or the array has only one element the result should be 0 (Nothing in Haskell, None in Rust).

*************************************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

int sumOfDifferences(const vector<int>& arr) {
  if(arr.empty() || (sizeof(arr) == 1)) {
    return 0;
  }
  else {
    int sum = 0;
    vector<int> arr_temp = arr;
    // Descending order sorting    
    std::sort(arr_temp.begin(), arr_temp.end(), std::greater<int>());
    // Sum logic
    for (int i = 0; i < (int)arr_temp.size() - 1; i++) {
      cout << "arr[" << i << "] : " << arr_temp[i] << endl;
      if (i == (int)arr_temp.size() - 2) {
        cout << "arr[" << i+1 << "] : " << arr_temp[i+1] << endl;
      }
      sum = sum + (arr_temp[i] - arr_temp[i + 1]);
    }

    return sum;
  }
}

/*
int sumOfDifferences(const std::vector<int>& arr) {
  if (arr.empty()) return 0;
  auto p = std::minmax_element(arr.cbegin(), arr.cend());
  return *p.second - *p.first;
}
*/

int main() {
  vector<int> arr {};
  int v_values;
  cout << "Enter the vector elements and enter 'end' to exit adding vector elements: " << endl;
  while (std::cin >> v_values) {
    arr.push_back(v_values);
  }
  int result = sumOfDifferences(arr);
  cout << "Result = " << result << endl;
}