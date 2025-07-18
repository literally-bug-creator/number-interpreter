#include "terminal_expressions/sign.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class SignExpressionTest : public ::testing::Test {};

TEST_F(SignExpressionTest, InterpretPlusSign) {
    Context context("+");
    SignExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("+", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SignExpressionTest, InterpretMinusSign) {
    Context context("-");
    SignExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("-", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SignExpressionTest, InterpretInvalidInput) {
    Context context("x");
    SignExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("x", context.get(1));
}

TEST_F(SignExpressionTest, InterpretWithFollowingCharacters) {
    Context context("+123");
    SignExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("+", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("123", context.get(3));
}

TEST_F(SignExpressionTest, InterpretEmptyString) {
    Context context("");
    SignExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}
