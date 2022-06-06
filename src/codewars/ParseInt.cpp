/**********************************************************************************************

You ask a small girl,"How old are you?" She always says, "x years old", 
where x is a random number between 0 and 9.

Write a program that returns the girl's age (0-9) as an integer.

Assume the test input string is always a valid string. For example, 
the test input may be "1 year old" or "5 years old". 
The first character in the string is always a number.

***********************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;

int get_age(const std::string& she_said) {
  std::istringstream str_stream(she_said);
  int age;
  char sentence;
  while (str_stream >> age >> sentence) {
    return age;
  }
  return 0;
}

int main() {
  cout << get_age("5 years old") << endl;
  cout << get_age("9 years old") << endl;
  cout << get_age("1 year old") << endl;
}