// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Chirkov_Roman_ComplexNumberTest, ){
  ComplexNumber z1(123, 321);
  ComplexNumber z2(0.0, 0.0);

  ASSERT_ANY_THROW(z1/z2);
}