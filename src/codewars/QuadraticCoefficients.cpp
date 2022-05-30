/**********************************************************************************************

In this Kata you are expected to find the coefficients of quadratic equation of the given
 two roots (x1 and x2).

Equation will be the form of ax^2 + bx + c = 0

Return type is a Vector (tuple in Rust, Array in Ruby) containing coefficients of 
the equations in the order (a, b, c).

Since there are infinitely many solutions to this problem, we fix a = 1.

Remember, the roots can be written like (x-x1) * (x-x2) = 0
Example

quadratic(1,2) = (1, -3, 2)

This means (x-1) * (x-2) = 0; when we do the multiplication this becomes x^2 - 3x + 2 = 0
Example 2

quadratic(0,1) = (1, -1, 0)

This means (x-0) * (x-1) = 0; when we do the multiplication this becomes x^2 - x + 0 = 0
Notes

    Inputs will be integers.
    When x1 == x2, this means the root has the multiplicity of two

***********************************************************************************************/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> quadratic(int a,int b){
  return {1, - (a + b), a * b};
}

int main() {
  vector<int> test1 = quadratic(0,1);
  cout << "test1: ";
  for (auto i : test1) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> test2 = quadratic(1,1);
  cout << "test2: ";
  for (auto i : test2) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> test3 = quadratic(-4,-9);
  cout << "test3: ";
  for (auto i : test3) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> test4 = quadratic(-5,-4);
  cout << "test4: ";
  for (auto i : test4) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> test5 = quadratic(4,-9);
  cout << "test5: ";
  for (auto i : test5) {
    cout << i << " ";
  }
  cout << endl;

  vector<int> test6 = quadratic(5,-4);
  cout << "test6: ";
  for (auto i : test6) {
    cout << i << " ";
  }
  cout << endl;
}












