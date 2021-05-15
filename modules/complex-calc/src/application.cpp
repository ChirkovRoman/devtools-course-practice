// Copyright 2021 Chirkov Roman

#include "include/application.h"

#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>

#include "include/complex_number.h"


char parseOperation(const char* arg) {
  char op;
  if (strcmp(arg, "+") == 0) {
    op = '+';
  } else if (strcmp(arg, "-") == 0) {
    op = '-';
  } else if (strcmp(arg, "*") == 0) {
    op = '*';
  } else if (strcmp(arg, "/") == 0) {
    op = '/';
  } else {
    throw std::string("Wrong operation format! Try to use '' or \\");
  }
  return op;
}

Complex parseOperand(char* argReal, char* argIm) {
  double real = stod(std::string(argReal));
  double im = stod(std::string(argIm));

  return Complex(real, im);
}

Application::Application() {
  leftOperand = Complex();
  rightOperand = Complex();
}

char Application::checkMode(int argc, char** argv) {
  if (argc == 1) {
    error = "ERROR: You need to provide arguments.\n\n";
    return 1;
  }

  // --------------------------------------------------------
  // You can add more parameter checks here for another modes
  // --------------------------------------------------------
  if (argc == 2) {
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      return 1;
    } else {
      error = "ERROR: wrong parameter.\n\n";
      return 1;
    }
    return 1;
  }

  if (argc != 6) {
    error = "ERROR: Should be 1 or 5 arguments.\n\n";
    return 1;
  }

  return 2;
}

void Application::help(const char* appname, std::string message) {
  helpMessage =
      message +
      "This is a complex number calculator application. The app currently " +
      "supports two modes.\n\n" +

      "To get just this help message you can use -h or --help parameters\n" +
      "E.g. $ " + appname + " --help\n\n" +

      "To get the result of calculating an operation on two complex numbers, " +
      "enter three arguments. Please provide arguments in the following " +
      "format:\n\n" +

      "  $ " + appname + " <z1_real> <z1_imaginary> " +
      "<operation> <z2_real> <z2_imaginary>\n\n" +

      "Where <z1_real>, <z1_imaginary>, <z2_real>, <z2_imaginary>" +
      "are double-precision numbers (use the dot symbol to separate " +
      "the fractional part.), and <operation> is one of '+', '-', '*', '/'.\n" +
      "E.g. $ " + appname + " 176.471 0.42 + 7 95.000034\n\n" +

      "'*', '/' operations may need to use '' or \\" + "E.g. $ " + appname +
      " 176.471 0.42 \\* 7 95.000034\n\n";
}

std::string Application::init(int argc, char** argv) {
  char mode = checkMode(argc, argv);

  // display errors and help
  if (mode == 1) {
    help(argv[0], error);
    return helpMessage;
  }

  // calculating an operation on two complex numbers
  if (mode != 2) {
    throw "Unsupported mode";
  }

  // farther code is outside of "if" because function has to return something by
  // default put it in "if" if you adding new mode
  try {
    leftOperand = parseOperand(argv[1], argv[2]);
    operation = parseOperation(argv[3]);
    rightOperand = parseOperand(argv[4], argv[5]);
  } catch (std::string& e) {
    error = "ERROR: " + e;
    help(argv[0], error);
    return helpMessage;
  }

  Complex result;
  switch (operation) {
    case '+':
      result = leftOperand + rightOperand;
      break;
    case '-':
      result = leftOperand - rightOperand;
      break;
    case '*':
      result = leftOperand * rightOperand;
      break;
    case '/':
      result = leftOperand / rightOperand;
      break;
  }

  std::ostringstream stream;
  std::string resultString;

  stream << "(" << result.getReal() << ";" << result.getImag() << ")";
  resultString = stream.str();

  return resultString;
}
