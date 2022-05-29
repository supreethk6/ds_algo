/**********************************************************************************************
 
Write a function called repeatStr which repeats the given string string exactly n times.

repeat_str(6, "I") // "IIIIII"
repeat_str(5, "Hello") // "HelloHelloHelloHelloHello"

***********************************************************************************************/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string repeat_str(size_t repeat, const string& str) {
  string str_copy;
  for (size_t i = 0; i < repeat; i++) {
    str_copy += str;
  }
  return str_copy;
}

int main() {
  size_t repeat_num;
  string str_in;
  cout << "Enter the string to be repeated: " << std::flush;
  cin >> str_in;
  cout << "Enter number of times the string to be repeated: " << std::flush;
  cin >> repeat_num;
  string str_out = repeat_str(repeat_num, str_in);
  cout << "Repeated string output is '" << str_out << "'" << endl;
}