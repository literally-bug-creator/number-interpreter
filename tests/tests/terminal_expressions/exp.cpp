#include "terminal_expressions/exp.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class ExpExpressionTest : public ::testing::Test {};

TEST_F(ExpExpressionTest, InterpretLowercaseE) {
    Context context("e");
    ExpExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("e", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ExpExpressionTest, InterpretUppercaseE) {
    Context context("E");
    ExpExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(!context.isFinished());
}

TEST_F(ExpExpressionTest, InterpretInvalidInput) {
    Context context("x");
    ExpExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("x", context.get(1));
}

TEST_F(ExpExpressionTest, InterpretWithFollowingCharacters) {
    Context context("e123");
    ExpExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("e", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("123", context.get(3));
}

TEST_F(ExpExpressionTest, InterpretEmptyString) {
    Context context("");
    ExpExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}
