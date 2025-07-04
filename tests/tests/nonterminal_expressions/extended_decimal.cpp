#include "nonterminal_expressions/extended_decimal.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class ExtendedDecimalExpressionTest : public ::testing::Test {};

TEST_F(ExtendedDecimalExpressionTest, InterpretDecimal) {
    Context context("123.456");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("123.456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExtendedDecimalExpressionTest, InterpretSigned) {
    Context context("-123.456e10");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("-123.456e10", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExtendedDecimalExpressionTest, InterpretUnsigned) {
    Context context("789");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("789", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExtendedDecimalExpressionTest, InterpretInfinity) {
    Context context("inf");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExtendedDecimalExpressionTest, InterpretSignedInf) {
    Context context("+infinity");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("+inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_FALSE(context.isFinished());
}

TEST_F(ExtendedDecimalExpressionTest, InterpretNaN) {
    Context context("nan");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("nan", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExtendedDecimalExpressionTest, InterpretSignedNan) {
    Context context("-nan");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("-nan", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExtendedDecimalExpressionTest, InterpretZero) {
    Context context("0");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExtendedDecimalExpressionTest, InterpretWithRemaining) {
    Context context("123.456abc");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("123.456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(ExtendedDecimalExpressionTest, InterpretInvalid) {
    Context context("abc");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(ExtendedDecimalExpressionTest, InterpretEmpty) {
    Context context("");
    ExtendedDecimalExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}
