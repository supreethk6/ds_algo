/**********************************************************************************************

Write function RemoveExclamationMarks which removes all exclamation marks from a given string.

***********************************************************************************************/

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
// #include <algorithm>
// #include <sstream>

using std::cout;
using std::string;
// using std::istringstream;

/*
string removeExclamationMarks(string str) {
  str.erase(std::remove(str.begin(), str.end(), "!"), str.end());
}
*/


string removeExclamationMarks(string str) {
  boost::erase_all(str, "!");

  return str;
}


/*
string removeExclamationMarks(std::string str){
  istringstream my_stream(str);
  string out_str;
  char str_extracts;

  while (my_stream >> str_extracts) {
    char del = ' ';
    if (str_extracts != '!' || str_extracts == ' ') {
      out_str.push_back(str_extracts);
    }
  }

  return out_str;
}
*/

/*
string removeExclamationMarks(string str) {
  size_t exclamation = str.find('!');
  while(exclamation) {
    str.erase(str.begin()+exclamation);
  }
  return str;
}
*/

int main() {
  cout << removeExclamationMarks("Hello World!") << std::endl;
  cout << removeExclamationMarks("Hello World!!!") << std::endl;
  cout << removeExclamationMarks("Hi! Hello!") << std::endl;
  cout << removeExclamationMarks("Hi!!! Hello!") << std::endl;
  cout << removeExclamationMarks("Hi! He!l!lo!") << std::endl;
}