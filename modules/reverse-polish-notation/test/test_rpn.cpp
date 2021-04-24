// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>
#include <include/rpn.h>

TEST(RPN, can_create_notation_without_parameters) {
  ASSERT_NO_THROW(RPN notation());
}

TEST(RPN, can_create_notation_with_empty_string) {
  ASSERT_NO_THROW(RPN notation(""));
}

TEST(RPN, can_create_notation_with_one_digit_number) {
  ASSERT_NO_THROW(RPN notation("8"));
}

TEST(RPN, can_create_notation_with_one_variable) {
  ASSERT_NO_THROW(RPN notation("v"));
}

TEST(RPN, can_create_notation_with_just_number) {
  RPN notation("18923");
  std::string res = notation.rpn;
  std::string exp = "18923";
  ASSERT_EQ(exp, res);
}