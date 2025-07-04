#include "nonterminal_expressions/digit.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class DigitExpressionTest : public ::testing::Test {};

TEST_F(DigitExpressionTest, InterpretZero) {
    Context context("0");
    DigitExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ("0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DigitExpressionTest, InterpretNonZero) {
    Context context("5");
    DigitExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ("5", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(DigitExpressionTest, InterpretWithRemaining) {
    Context context("3abc");
    DigitExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ("3", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(DigitExpressionTest, InterpretInvalid) {
    Context context("x");
    DigitExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("x", context.get(1));
}

TEST_F(DigitExpressionTest, InterpretEmpty) {
    Context context("");
    DigitExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}