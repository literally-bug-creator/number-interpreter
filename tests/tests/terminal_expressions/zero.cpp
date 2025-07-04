#include "terminal_expressions/zero.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class ZeroExpressionTest : public ::testing::Test {};

TEST_F(ZeroExpressionTest, InterpretValidZero) {
    Context context("0");
    ZeroExpression expression;
    string expected = "0";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretInvalidCharacter) {
    Context context("x");
    ZeroExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretNonZeroDigit) {
    Context context("1");
    ZeroExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretZeroAtBeginning) {
    Context context("0123");
    ZeroExpression expression;
    string expected = "0";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretZeroAtMiddle) {
    Context context("1230456");
    ZeroExpression expression;
    context.next(3);
    string expected = "0";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretEmptyString) {
    Context context("");
    ZeroExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretWhenContextFinished) {
    Context context("123");
    ZeroExpression expression;
    context.next(3);
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretLetter) {
    Context context("a");
    ZeroExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretSymbol) {
    Context context(".");
    ZeroExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretDoesNotAdvanceContext) {
    Context context("0123");
    ZeroExpression expression;
    string expectedToken = "0";
    string expectedRemaining = "0123";

    Token result = expression.interpret(context);
    string remaining = context.get(4);

    EXPECT_EQ(expectedToken, result.getValue());
    EXPECT_EQ(expectedRemaining, remaining);
}

TEST_F(ZeroExpressionTest, InterpretMultipleZeros) {
    Context context("00");
    ZeroExpression expression;
    string expected = "0";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretZeroFollowedByDigits) {
    Context context("0456");
    ZeroExpression expression;
    string expected = "0";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ZeroExpressionTest, InterpretAllDigitsExceptZero) {
    Context context("1");
    ZeroExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}
