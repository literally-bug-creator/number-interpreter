#include "nonterminal_expressions/special.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class SpecialExpressionTest : public ::testing::Test {};

TEST_F(SpecialExpressionTest, InterpretInfinity) {
    Context context("inf");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SpecialExpressionTest, InterpretInfinityLong) {
    Context context("infinity");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_FALSE(context.isFinished());
}

TEST_F(SpecialExpressionTest, InterpretSignedInf) {
    Context context("+inf");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("+inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SpecialExpressionTest, InterpretNegativeInf) {
    Context context("-infinity");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("-inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_FALSE(context.isFinished());
}

TEST_F(SpecialExpressionTest, InterpretNaN) {
    Context context("nan");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("nan", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SpecialExpressionTest, InterpretSignedNan) {
    Context context("+nan");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("+nan", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SpecialExpressionTest, InterpretNegativeNan) {
    Context context("-nan");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("-nan", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(SpecialExpressionTest, InterpretWithRemaining) {
    Context context("infabc");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(SpecialExpressionTest, InterpretInvalid) {
    Context context("abc");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(SpecialExpressionTest, InterpretEmpty) {
    Context context("");
    SpecialExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}
