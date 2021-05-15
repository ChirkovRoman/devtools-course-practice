// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include "include/application.h"
#include "include/complex_number.h"

TEST(Complex_calc_application, can_create_just_app) {
  ASSERT_NO_THROW(Application app);
}

TEST(Complex_calc_application, can_initialize_app) {
  Application app;
  int argc = 1;
  char** argv = new char*[argc];

  argv[0] = "complex_calculator";

  ASSERT_NO_THROW(app.init(argc, argv));
}

TEST(Complex_calc_application, can_get_help_without_throws_short_form) {
  Application app;
  int argc = 2;
  char** argv = new char*[argc];

  argv[0] = "complex_calculator";
  argv[1] = "-h";

  ASSERT_NO_THROW(app.init(argc, argv));
}

TEST(Complex_calc_application, can_get_help_without_throws_long_form) {
  Application app;
  int argc = 2;
  char** argv = new char*[argc];

  argv[0] = "complex_calculator";
  argv[1] = "--help";

  ASSERT_NO_THROW(app.init(argc, argv));
}

TEST(Complex_calc_application, can_add) {
  Application app;
  int argc = 6;
  char** argv = new char*[argc];

  argv[0] = "complex_calculator";
  argv[1] = "1.5";
  argv[2] = "2";
  argv[3] = "+";
  argv[4] = "3.02";
  argv[5] = "3";

  std::string exp = "(4.52;5)";
  std::string res = app.init(argc, argv);

  ASSERT_EQ(exp, res);
}

TEST(Complex_calc_application, can_subtract) {
  Application app;
  int argc = 6;
  char** argv = new char*[argc];

  argv[0] = "complex_calculator";
  argv[1] = "1.5";
  argv[2] = "2";
  argv[3] = "-";
  argv[4] = "3.02";
  argv[5] = "3";

  std::string exp = "(-1.52;-1)";
  std::string res = app.init(argc, argv);

  ASSERT_EQ(exp, res);
}

TEST(Complex_calc_application, can_multiply) {
  Application app;
  int argc = 6;
  char** argv = new char*[argc];

  argv[0] = "complex_calculator";
  argv[1] = "1.5";
  argv[2] = "2";
  argv[3] = "*";
  argv[4] = "3.02";
  argv[5] = "3";

  std::string exp = "(-1.47;10.54)";
  std::string res = app.init(argc, argv);

  ASSERT_EQ(exp, res);
}

TEST(Complex_calc_application, can_divide) {
  Application app;
  int argc = 6;
  char** argv = new char*[argc];

  argv[0] = "complex_calculator";
  argv[1] = "1.5";
  argv[2] = "2";
  argv[3] = "/";
  argv[4] = "3.02";
  argv[5] = "3";

  std::string exp = "(0.581113;0.0849871)";
  std::string res = app.init(argc, argv);

  ASSERT_EQ(exp, res);
}

TEST(Complex_calc_application, cannot_divide_by_zero) {
  Application app;
  int argc = 6;
  char** argv = new char*[argc];

  argv[0] = "complex_calculator";
  argv[1] = "1.5";
  argv[2] = "2";
  argv[3] = "/";
  argv[4] = "0";
  argv[5] = "0";

  app.init(argc, argv);

  std::string exp = "ERROR: Can't divide by zero";
  std::string res = app.getError();

  ASSERT_EQ(exp, res);
}
