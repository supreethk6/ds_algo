/**********************************************************************************************

Bob needs a fast way to calculate the volume of a cuboid with three values: 
the length, width and height of the cuboid. Write a function to help Bob 
with this calculation.

***********************************************************************************************/

#include <iostream>

using std::cout;
using std::endl;

double getVolumeOfCubiod(double length, double width, double height) {
  return length * width * height;
}

int main() {
  cout << getVolumeOfCubiod(1, 2, 2) << endl;
  cout << getVolumeOfCubiod(6.3, 2, 5) << endl;
}