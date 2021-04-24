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
  if (isOperator(s[0])) {
    throw "wrong source string: the first simbol is operator";
  }

  for (auto i = 0; i < s.size(); i++) {
    if (isVar(s[i]) || isDigit(s[i])) {
      rpn += s[i];
      continue;
    }

    if (isOperator(s[i])) {
      putSpaceIfNeeded();

      while (!op_stack.empty()) {
        if (priority(s[i]) <= priority(op_stack.top())) {
          putSpaceIfNeeded();
          rpn += op_stack.top();
          op_stack.pop();
        } else {
          break;
        }
      }

      putSpaceIfNeeded();
      op_stack.push(s[i]);
      continue;
    }

    if (s[i] == '(') {
      op_stack.push(s[i]);
      continue;
    }

    if (s[i] == ')') {
      while (op_stack.top() != '(') {
        putSpaceIfNeeded();
        rpn += op_stack.top();
        op_stack.pop();
      }
      putSpaceIfNeeded();
      op_stack.pop();
    }
  }

  while (!op_stack.empty()) {
    putSpaceIfNeeded();
    rpn += op_stack.top();
    op_stack.pop();
  }
}

bool RPN::isDigit(char c) { return (c >= '0' && c <= '9'); }

bool RPN::isVar(char c) { return (c >= 'a' && c <= 'z'); }

bool RPN::isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int RPN::priority(char c) {
  switch (c) {
    case '(':
      return 1;
    case '-':
      return 2;
    case '+':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    case '^':
      return 4;
  }
}
void RPN::putSpaceIfNeeded() {
  if (rpn[rpn.size() - 1] != ' ') {
    rpn += " ";
  }
}