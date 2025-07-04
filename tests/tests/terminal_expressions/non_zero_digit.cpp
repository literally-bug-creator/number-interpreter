#include "terminal_expressions/non_zero_digit.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class NonZeroDigitExpressionTest : public ::testing::Test {};

TEST_F(NonZeroDigitExpressionTest, InterpretDigitOne) {
    Context context("1");
    NonZeroDigitExpression expression;
    string expected = "1";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitTwo) {
    Context context("2");
    NonZeroDigitExpression expression;
    string expected = "2";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitThree) {
    Context context("3");
    NonZeroDigitExpression expression;
    string expected = "3";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitFour) {
    Context context("4");
    NonZeroDigitExpression expression;
    string expected = "4";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitFive) {
    Context context("5");
    NonZeroDigitExpression expression;
    string expected = "5";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitSix) {
    Context context("6");
    NonZeroDigitExpression expression;
    string expected = "6";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitSeven) {
    Context context("7");
    NonZeroDigitExpression expression;
    string expected = "7";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitEight) {
    Context context("8");
    NonZeroDigitExpression expression;
    string expected = "8";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitNine) {
    Context context("9");
    NonZeroDigitExpression expression;
    string expected = "9";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretZero) {
    Context context("0");
    NonZeroDigitExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretInvalidCharacter) {
    Context context("x");
    NonZeroDigitExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitAtBeginning) {
    Context context("5abc");
    NonZeroDigitExpression expression;
    string expected = "5";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDigitAtMiddle) {
    Context context("abc7def");
    NonZeroDigitExpression expression;
    context.next(3);
    string expected = "7";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretEmptyString) {
    Context context("");
    NonZeroDigitExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretWhenContextFinished) {
    Context context("123");
    NonZeroDigitExpression expression;
    context.next(3);
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretLetter) {
    Context context("a");
    NonZeroDigitExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretSymbol) {
    Context context(".");
    NonZeroDigitExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretDoesNotAdvanceContext) {
    Context context("3456");
    NonZeroDigitExpression expression;
    string expectedToken = "3";
    string expectedRemaining = "3456";

    Token result = expression.interpret(context);
    string remaining = context.get(4);

    EXPECT_EQ(expectedToken, result.getValue());
    EXPECT_EQ(expectedRemaining, remaining);
}

TEST_F(NonZeroDigitExpressionTest, InterpretMultipleDigits) {
    Context context("12");
    NonZeroDigitExpression expression;
    string expected = "1";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretSign) {
    Context context("+");
    NonZeroDigitExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NonZeroDigitExpressionTest, InterpretMinusSign) {
    Context context("-");
    NonZeroDigitExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}
