#include "nonterminal_expressions/decimal.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class DecimalExpressionTest : public ::testing::Test {};

TEST_F(DecimalExpressionTest, InterpretInteger) {
    Context context("123");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DecimalExpressionTest, InterpretWithFraction) {
    Context context("123.456");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("123.456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DecimalExpressionTest, InterpretWithExponent) {
    Context context("123e10");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("123e10", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DecimalExpressionTest, InterpretComplete) {
    Context context("123.456e-10");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("123.456e-10", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DecimalExpressionTest, InterpretSigned) {
    Context context("+123");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("+123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DecimalExpressionTest, InterpretNegative) {
    Context context("-123.456");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("-123.456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DecimalExpressionTest, InterpretZero) {
    Context context("0");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DecimalExpressionTest, InterpretFraction) {
    Context context("0.123");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("0.123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DecimalExpressionTest, InterpretWithRemaining) {
    Context context("123.456abc");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("123.456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(DecimalExpressionTest, InterpretInvalid) {
    Context context("abc");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(DecimalExpressionTest, InterpretEmpty) {
    Context context("");
    DecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}