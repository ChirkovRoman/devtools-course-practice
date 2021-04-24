// Copyright 2021 Chirkov Roman
#include <stack>
#include <string>

class RPN {
 public:
  std::string rpn;
  std::stack<char> op_stack;
  RPN();
  RPN(std::string s);
  static bool isDigit(char c);
  static bool isVar(char c);
  static bool isOperator(char c);
  static int priority(char c);
  void putSpaceIfNeeded();
};