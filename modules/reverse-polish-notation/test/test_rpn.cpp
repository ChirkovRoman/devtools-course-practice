// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>
#include <include/rpn.h>

#include <string>


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
  std::string exp = "18923";
  RPN notation("18923");
  std::string res = notation.rpn;

  ASSERT_EQ(exp, res);
}

TEST(RPN, addition_of_two_numbers) {
  std::string exp = "123 321 +";
  RPN notation("123+321");
  std::string res = notation.rpn;

  ASSERT_EQ(exp, res);
}

TEST(RPN, cannot_create_notation_with_operator_at_the_beginning) {
  ASSERT_ANY_THROW(RPN notation("/451*7+9"));
}

TEST(RPN, bunch_of_additions_and_subtitutions) {
  std::string exp = "45 89 + 21 + 75 - 4 + 987 -";
  RPN notation("45+89+21-75+4-987");
  std::string res = notation.rpn;

  ASSERT_EQ(exp, res);
}

TEST(RPN, bunch_of_multiplications_and_divisions) {
  std::string exp = "12 46 * 72 / 4 * 9 /";
  RPN notation("12*46/72*4/9");
  std::string res = notation.rpn;

  ASSERT_EQ(exp, res);
}

TEST(RPN, priority_of_operations_is_considered) {
  std::string exp = "1 2 3 * + 7 45 / 4 * +";
  RPN notation("1+2*3+7/45*4");
  std::string res = notation.rpn;

  ASSERT_EQ(exp, res);
}

TEST(RPN, parentheses_are_considered) {
  std::string exp = "7 11 + 15 13 / /";
  RPN notation("(7+11)/(15/(13))");
  std::string res = notation.rpn;

  ASSERT_EQ(exp, res);
}
