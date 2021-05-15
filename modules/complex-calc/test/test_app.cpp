// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include "include/application.h"
#include "include/complex_number.h"

TEST(Complex_calc_application, can_create_just_app) {
  ASSERT_NO_THROW(Application app);
}

TEST(Complex_calc_application, can_set_left_operand) {
  Application app;
  double re = 1.0605;
  double im = -7.0004;

  Complex exp(re, im);
  app.setLeftOperand(re, im);

  ASSERT_EQ(exp, app.getLeftOperand());
}

TEST(Complex_calc_application, can_set_right_operand) {
  Application app;
  double re = -7;
  double im = 86.09;

  Complex exp(re, im);
  app.setRightOperand(re, im);

  ASSERT_EQ(exp, app.getRightOperand());
}

TEST(Complex_calc_application, unsupported_operation_is_not_operation) {
  Application app;
  char operation = '%';

  ASSERT_FALSE(app.isOperation(operation));
}

TEST(Complex_calc_application, trying_set_unsupported_operation) {
  Application app;
  char operation = '$';

  ASSERT_ANY_THROW(app.setOperation(operation));
}

TEST(Complex_calc_application, trying_get_not_set_yet_operation) {
  Application app;

  ASSERT_ANY_THROW(app.getOperation());
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
