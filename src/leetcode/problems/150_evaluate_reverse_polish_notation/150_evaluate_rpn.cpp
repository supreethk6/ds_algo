/**
 * @file 150_evaluate_rpn.cpp
 * @author skk
 * @brief 
 * 
 * You are given an array of strings tokens that represents an arithmetic 
 * expression in a Reverse Polish Notation.
 * Evaluate the expression. Return an integer that represents the value 
 * of the expression.
 * 
 * Note that:
 *     The valid operators are '+', '-', '*', and '/'.
 *     Each operand may be an integer or another expression.
 *     The division between two integers always truncates toward zero.
 *     There will not be any division by zero.
 *     The input represents a valid arithmetic expression in a reverse polish notation.
 *     The answer and all the intermediate calculations can be represented in a 32-bit integer.
 * 
 * Example 1:
 * Input: tokens = ["2","1","+","3","*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * Example 2:
 * Input: tokens = ["4","13","5","/","+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * Example 3:
 * Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * Constraints:
 * 
 *     1 <= tokens.length <= 104
 *     tokens[i] is either an operator: "+", "-", "*", or "/", 
 *     or an integer in the range [-200, 200].
 * 
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
// #include <typeinfo>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::stack;

template<typename T>
void print_vector(vector<T> vect) {
  cout << "Vector: " ;
  for (T row : vect) {
    cout << row << " ";
  }
  cout << endl;
}

template<typename T>
void print_stack(stack<T> stac) {
  if (stac.empty()) {
    return;
  }
  T element = stac.top();
  stac.pop();
  print_stack(stac);
  cout << element << " ";
  stac.push(element);
} 

int evalRPN(vector<string>& tokens) {
  stack<int> numerals;
  for (auto index : tokens) {
    if (index != "+" && index != "-" && index != "*" && index != "/") {
      numerals.push(std::stoi(index));
      continue;
    }
    
    int num2 = numerals.top();
    numerals.pop();
    int num1 = numerals.top();
    numerals.pop();

    int result = 0;
    if (index == "+") {
      result = num1 + num2;
    }
    else if (index == "-") {
      result = num1 - num2;
    }
    else if (index == "*") {
      result = num1 * num2;
    }
    else if (index == "/") {
      result = int(num1 / num2);
    }
    numerals.push(result);
  }

  return numerals.top();
}

int main() {
  int solution;
  vector<string> arithmetic_exp {};
  cout << "------> Test Case 1 <------" << endl;
  arithmetic_exp = {"2","1","+","3","*"};
  print_vector(arithmetic_exp);
  solution = evalRPN(arithmetic_exp);
  cout << "Output: " << solution << endl;

  cout << "------> Test Case 2 <------" << endl;
  arithmetic_exp = {"4","13","5","/","+"};
  print_vector(arithmetic_exp);
  solution = evalRPN(arithmetic_exp);
  cout << "Output: " << solution << endl;

  cout << "------> Test Case 3 <------" << endl;
  arithmetic_exp = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  print_vector(arithmetic_exp);
  solution = evalRPN(arithmetic_exp);
  cout << "Output: " << solution << endl;
}