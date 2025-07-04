#include "terminal_expressions/sign.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class SignExpressionTest : public ::testing::Test {};

TEST_F(SignExpressionTest, InterpretPlusSign) {
    Context context("+");
    SignExpression expression;
    string expected = "+";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretMinusSign) {
    Context context("-");
    SignExpression expression;
    string expected = "-";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretInvalidCharacter) {
    Context context("x");
    SignExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretNumber) {
    Context context("1");
    SignExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretPlusAtBeginning) {
    Context context("+123");
    SignExpression expression;
    string expected = "+";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretMinusAtBeginning) {
    Context context("-456");
    SignExpression expression;
    string expected = "-";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretMinusAtMiddle) {
    Context context("123-456");
    SignExpression expression;
    context.next(3);
    string expected = "-";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretEmptyString) {
    Context context("");
    SignExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretWhenContextFinished) {
    Context context("123");
    SignExpression expression;
    context.next(3);
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretOtherSymbols) {
    Context context("*");
    SignExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretEqualsSign) {
    Context context("=");
    SignExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretDoesNotAdvanceContext) {
    Context context("+123");
    SignExpression expression;
    string expectedToken = "+";
    string expectedRemaining = "+123";

    Token result = expression.interpret(context);
    string remaining = context.get(4);

    EXPECT_EQ(expectedToken, result.getValue());
    EXPECT_EQ(expectedRemaining, remaining);
}

TEST_F(SignExpressionTest, InterpretMultipleSigns) {
    Context context("++");
    SignExpression expression;
    string expected = "+";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(SignExpressionTest, InterpretMixedSigns) {
    Context context("+-");
    SignExpression expression;
    string expected = "+";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}
