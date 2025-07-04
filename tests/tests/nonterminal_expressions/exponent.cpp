#include "nonterminal_expressions/exponent.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class ExponentExpressionTest : public ::testing::Test {};

TEST_F(ExponentExpressionTest, InterpretPositive) {
    Context context("e+123");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("e+123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExponentExpressionTest, InterpretNegative) {
    Context context("e-456");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("e-456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExponentExpressionTest, InterpretUnsigned) {
    Context context("e789");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("e789", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExponentExpressionTest, InterpretUppercase) {
    Context context("E123");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_FALSE(context.isFinished());
}

TEST_F(ExponentExpressionTest, InterpretZero) {
    Context context("e0");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("e0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExponentExpressionTest, InterpretWithRemaining) {
    Context context("e+123abc");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("e+123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(ExponentExpressionTest, InterpretEOnly) {
    Context context("e");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("e", context.get(1));
}

TEST_F(ExponentExpressionTest, InterpretInvalid) {
    Context context("abc");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(ExponentExpressionTest, InterpretEmpty) {
    Context context("");
    ExponentExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}
