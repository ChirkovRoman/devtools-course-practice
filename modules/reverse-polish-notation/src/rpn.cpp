// Copyright 2021 Chirkov Roman

#include "include/rpn.h"

#include <iterator>
#include <stack>
#include <string>

RPN::RPN() { rpn = ""; }

RPN::RPN(std::string s) {
  if (s == "") {
    rpn += s;
    return;
  }

  for (auto i = 0; i < s.size(); i++) {
    if (isDigit(s[i])) {
      rpn += s[i];
      continue;
    }
    if (isVar(s[i])) {
      rpn += s[i];
      continue;
    }
  }
}

bool RPN::isDigit(char c) { return (c >= '0' && c <= '9'); }
bool RPN::isVar(char c) { return (c >= 'a' && c <= 'z'); }