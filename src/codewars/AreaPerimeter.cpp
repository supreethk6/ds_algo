/**********************************************************************************************

You are given the length and width of a 4-sided polygon. 
The polygon can either be a rectangle or a square.
If it is a square, return its area. 
If it is a rectangle, return its perimeter.

area_or_perimeter(6, 10) --> 32
area_or_perimeter(3, 3) --> 9

Note: for the purposes of this kata you will assume that it is a square if its 
length and width are equal, otherwise it is a rectangle.

***********************************************************************************************/

#include <iostream>

using std::cout;
using std::endl;

int area_or_perimeter(int l , int w) {
  if (l == w) {
    return l * w;
  }
  else {
    return 2 * l + 2 * w;
  }
}

int main() {
  cout << area_or_perimeter(4, 4) << endl;
  cout << area_or_perimeter(6, 10) << endl;
}