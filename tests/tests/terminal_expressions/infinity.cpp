#include "terminal_expressions/infinity.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class InfinityExpressionTest : public ::testing::Test {};

TEST_F(InfinityExpressionTest, InterpretInfLowercase) {
    Context context("inf");
    InfinityExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInfUppercase) {
    Context context("Inf");
    InfinityExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("Inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInfinityFull) {
    Context context("infinity");
    InfinityExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("inf", result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInvalidInput) {
    Context context("abc");
    InfinityExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretIncomplete) {
    Context context("in");
    InfinityExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretEmptyString) {
    Context context("");
    InfinityExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
}
