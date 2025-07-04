#include "terminal_expressions/dot.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class DotExpressionTest : public ::testing::Test {};

TEST_F(DotExpressionTest, InterpretValidDot) {
    Context context(".");
    DotExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ(".", result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretInvalidInput) {
    Context context("x");
    DotExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretWithFollowingCharacters) {
    Context context(".123");
    DotExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ(".", result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretEmptyString) {
    Context context("");
    DotExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
}
