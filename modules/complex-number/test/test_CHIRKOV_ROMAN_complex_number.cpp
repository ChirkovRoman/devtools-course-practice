// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

TEST(Chirkov_Roman_ComplexNumberTest, division_by_approximately_zero) {
  ComplexNumber z1(123.45011, 321);
  double eps = std::numeric_limits<double>::epsilon();
  double lessThanEpsilon = eps / 2;
  ComplexNumber z2(0.0, lessThanEpsilon);

  ASSERT_ANY_THROW(z1 / z2);
}

TEST(Chirkov_Roman_ComplexNumberTest, check_compare) {
  ComplexNumber z1(1, 15.0034);
  ComplexNumber z2(1, 15.0034);

  EXPECT_TRUE(z1 == z2);
  ASSERT_EQ(z1.getRe(), z2.getRe());
  ASSERT_EQ(z1.getIm(), z2.getIm());
}

TEST(Chirkov_Roman_ComplexNumberTest, multiplication_then_division) {
  ComplexNumber z1(100, -100.1);
  ComplexNumber z2(-10, -123.456);

  ComplexNumber multExp(-13357.9456, -11344.6);
  ComplexNumber multRes = z1 * z2;

  ASSERT_TRUE(multExp == multRes);

  ComplexNumber divRes = multRes / z2;
  ASSERT_TRUE(z1 == divRes);
}
