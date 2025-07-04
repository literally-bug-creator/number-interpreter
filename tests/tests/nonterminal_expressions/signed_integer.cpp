#include "nonterminal_expressions/signed_integer.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class SignedIntegerExpressionTest : public ::testing::Test {};

TEST_F(SignedIntegerExpressionTest, InterpretPositive) {
    Context context("+123");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("+123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SignedIntegerExpressionTest, InterpretNegative) {
    Context context("-456");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("-456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SignedIntegerExpressionTest, InterpretUnsigned) {
    Context context("789");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("789", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SignedIntegerExpressionTest, InterpretZero) {
    Context context("0");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SignedIntegerExpressionTest, InterpretSignedZero) {
    Context context("+0");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("+0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SignedIntegerExpressionTest, InterpretWithRemaining) {
    Context context("-123abc");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("-123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(SignedIntegerExpressionTest, InterpretInvalid) {
    Context context("abc");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(SignedIntegerExpressionTest, InterpretSignOnly) {
    Context context("+");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("+", context.get(1));
}

TEST_F(SignedIntegerExpressionTest, InterpretEmpty) {
    Context context("");
    SignedIntegerExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}