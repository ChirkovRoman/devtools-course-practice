// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include "include/application.h"
#include "include/complex_number.h"

TEST(Complex_calc_application, can_create_just_app) {
  ASSERT_NO_THROW(Application app);
}
