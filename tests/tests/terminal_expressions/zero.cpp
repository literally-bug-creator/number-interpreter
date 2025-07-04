#include "terminal_expressions/zero.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class ZeroExpressionTest : public ::testing::Test {};

TEST_F(ZeroExpressionTest, InterpretValidZero) {
    Context context("0");
    ZeroExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}

TEST_F(ZeroExpressionTest, InterpretInvalidInput) {
    Context context("1");
    ZeroExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
    EXPECT_EQ("1", context.get(1));
}

TEST_F(ZeroExpressionTest, InterpretWithFollowingCharacters) {
    Context context("0123");
    ZeroExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("0", result.getValue());
    EXPECT_FALSE(result.isEmpty());
    EXPECT_EQ("123", context.get(3));
}

TEST_F(ZeroExpressionTest, InterpretEmptyString) {
    Context context("");
    ZeroExpression expression;
    Token result = expression.interpret(context);

    EXPECT_TRUE(result.isEmpty());
    EXPECT_TRUE(context.isFinished());
}
