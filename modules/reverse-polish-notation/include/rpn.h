// Copyright 2021 Chirkov Roman

#ifndef MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_H_
#define MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_H_

#include <stack>
#include <string>

class RPN {
 public:
  std::string rpn;
  std::stack<char> op_stack;
  RPN();
  explicit RPN(std::string s);
  static bool isDigit(char c);
  static bool isVar(char c);
  static bool isOperator(char c);
  static int priority(char c);
  void putSpaceIfNeeded();
};

#endif  // MODULES_REVERSE_POLISH_NOTATION_INCLUDE_RPN_H_
