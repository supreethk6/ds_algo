/**********************************************************************************************

Write a function named setAlarm which receives two parameters. 
The first parameter, employed, is true whenever you are employed and the second parameter, 
vacation is true whenever you are on vacation.

The function should return true if you are employed and not on vacation 
(because these are the circumstances under which you need to set an alarm). 
It should return false otherwise. Examples:

setAlarm(true, true) -> false
setAlarm(false, true) -> false
setAlarm(false, false) -> false
setAlarm(true, false) -> true

***********************************************************************************************/

#include <iostream>

using std::cout;

bool set_alarm(const bool& employed, const bool& vacation){
  if ((employed && vacation) || (!employed && vacation) || (!employed && !vacation)) {
    return false;
  }
  else {
    return true;
  }
}

// bool set_alarm( const bool& employed, const bool& vacation )
// {
//   return (employed && !vacation);
// }

int main() {
  cout << set_alarm(true, true) << std::endl;
  cout << set_alarm(false, true) << std::endl;
  cout << set_alarm(false, false) << std::endl;
  cout << set_alarm(true, false) << std::endl;
}