#include "terminal_expressions/dot.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class DotExpressionTest : public ::testing::Test {};

TEST_F(DotExpressionTest, InterpretValidDot) {
    Context context(".");
    DotExpression expression;
    string expected = ".";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretInvalidCharacter) {
    Context context("x");
    DotExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretNumber) {
    Context context("1");
    DotExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretDotAtBeginning) {
    Context context(".123");
    DotExpression expression;
    string expected = ".";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretDotAtMiddle) {
    Context context("123.456");
    DotExpression expression;
    context.next(3);
    string expected = ".";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretEmptyString) {
    Context context("");
    DotExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretWhenContextFinished) {
    Context context("123");
    DotExpression expression;
    context.next(3);
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretCommaInsteadOfDot) {
    Context context(",");
    DotExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretMultipleDots) {
    Context context("..");
    DotExpression expression;
    string expected = ".";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(DotExpressionTest, InterpretDoesNotAdvanceContext) {
    Context context(".abc");
    DotExpression expression;
    string expectedToken = ".";
    string expectedRemaining = ".abc";

    Token result = expression.interpret(context);
    string remaining = context.get(4);

    EXPECT_EQ(expectedToken, result.getValue());
    EXPECT_EQ(expectedRemaining, remaining);
}
