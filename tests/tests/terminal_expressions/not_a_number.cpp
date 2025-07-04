#include "terminal_expressions/not_a_number.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class NotANumberExpressionTest : public ::testing::Test {};

TEST_F(NotANumberExpressionTest, InterpretNanLowercase) {
    Context context("nan");
    NotANumberExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("nan", result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNanUppercase) {
    Context context("NaN");
    NotANumberExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("NaN", result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNanAllCaps) {
    Context context("NAN");
    NotANumberExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("NAN", result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretInvalidInput) {
    Context context("abc");
    NotANumberExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretIncomplete) {
    Context context("na");
    NotANumberExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretEmptyString) {
    Context context("");
    NotANumberExpression expression;
    Token result = expression.interpret(context);

    EXPECT_EQ("", result.getValue());
    EXPECT_TRUE(result.isEmpty());
}
