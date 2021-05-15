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
