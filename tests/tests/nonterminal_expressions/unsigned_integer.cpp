#include "nonterminal_expressions/unsigned_integer.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class UnsignedIntegerExpressionTest : public ::testing::Test {};

TEST_F(UnsignedIntegerExpressionTest, InterpretZero) {
    Context context("0");
    UnsignedIntegerExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ("0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(UnsignedIntegerExpressionTest, InterpretMultiple) {
    Context context("123");
    UnsignedIntegerExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ("123", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(UnsignedIntegerExpressionTest, InterpretWithRemaining) {
    Context context("456abc");
    UnsignedIntegerExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ("456", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(UnsignedIntegerExpressionTest, InterpretZeroOnly) {
    Context context("0123");
    UnsignedIntegerExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_EQ("0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("123", context.get(3));
}

TEST_F(UnsignedIntegerExpressionTest, InterpretInvalid) {
    Context context("abc");
    UnsignedIntegerExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("abc", context.get(3));
}

TEST_F(UnsignedIntegerExpressionTest, InterpretEmpty) {
    Context context("");
    UnsignedIntegerExpression expression;
    Token result = expression.interpret(context);
    
    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}