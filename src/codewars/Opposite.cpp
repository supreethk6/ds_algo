/**********************************************************************************************
 
Very simple, given an integer or a floating-point number, find its opposite.

Examples:

1: -1
14: -14
-34: 34

***********************************************************************************************/

#include <iostream>

int opposite(int number) 
{
  return -number;
}

int main() {
  int num;
  std::cout << "Enter an integer number: " << std::endl;
  std::cin >> num;
  std::cout << "Opposite of " << num << " is: " << opposite(num) << std::endl;
}