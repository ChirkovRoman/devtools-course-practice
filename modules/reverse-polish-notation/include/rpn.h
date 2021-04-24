// Copyright 2021 Chirkov Roman
#include <string>

class RPN {
 public:
  std::string rpn;
  RPN();
  RPN(std::string s);
  static bool isDigit(char c);
  static bool isVar(char c);
};