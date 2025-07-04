#include "nonterminal_expressions/fractional_part.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class FractionalPartExpressionTest : public ::testing::Test {};

TEST_F(FractionalPartExpressionTest, InterpretSingle) {
    Context context(".5");
    FractionalPartExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ(".5", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(FractionalPartExpressionTest, InterpretMultiple) {
    Context context(".123");
    FractionalPartExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ(".123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(FractionalPartExpressionTest, InterpretWithRemaining) {
    Context context(".456abc");
    FractionalPartExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ(".456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(FractionalPartExpressionTest, InterpretMixed) {
    Context context(".102030");
    FractionalPartExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ(".102030", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(FractionalPartExpressionTest, InterpretDotOnly) {
    Context context(".");
    FractionalPartExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ(".", context.get(1));
}

TEST_F(FractionalPartExpressionTest, InterpretInvalid) {
    Context context("abc");
    FractionalPartExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(FractionalPartExpressionTest, InterpretEmpty) {
    Context context("");
    FractionalPartExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}