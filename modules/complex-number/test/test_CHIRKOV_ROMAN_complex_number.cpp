// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Chirkov_Roman_ComplexNumberTest, divide_by_zero) {
  ComplexNumber z1(123, 321);
  ComplexNumber z2(0.0, 0.0);

  ASSERT_ANY_THROW(z1 / z2);
}

TEST(Chirkov_Roman_ComplexNumberTest, multiplication_then_division) {
  ComplexNumber z1(100, -100.1);
  ComplexNumber z2(-10, -123.456);

  ComplexNumber multExp(-13357.9456, -11344.6);
  ComplexNumber multRes = z1 * z2;

  ASSERT_EQ(multExp, multRes);

  ComplexNumber divRes = multRes / z2;
  ASSERT_EQ(divRes, z1);
}
