#include "terminal_expressions/non_zero_digit.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class NonZeroDigitExpressionTest : public ::testing::Test {};

TEST_F(NonZeroDigitExpressionTest, InterpretValidDigits) {
    for (char digit = '1'; digit <= '9'; ++digit) {
        Context context(string(1, digit));
        NonZeroDigitExpression expression;
        Token result = expression.interpret(context);

        EXPECT_EQ(string(1, digit), result.getValue());
        EXPECT_FALSE(result.isEmpty());
        EXPECT_TRUE(context.isFinished());
    }
}

TEST_F(NonZeroDigitExpressionTest, InterpretZero) {
    Context context("0");
    NonZeroDigitExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("0", context.get(1));
}

TEST_F(NonZeroDigitExpressionTest, InterpretInvalidInput) {
    Context context("a");
    NonZeroDigitExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("a", context.get(1));
}

TEST_F(NonZeroDigitExpressionTest, InterpretWithFollowingCharacters) {
    Context context("5abc");
    NonZeroDigitExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("5", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(NonZeroDigitExpressionTest, InterpretEmptyString) {
    Context context("");
    NonZeroDigitExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}
