#include "terminal_expressions/exp.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class ExpExpressionTest : public ::testing::Test {};

TEST_F(ExpExpressionTest, InterpretValidExp) {
    Context context("e");
    ExpExpression expression;
    string expected = "e";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretInvalidCharacter) {
    Context context("x");
    ExpExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretNumber) {
    Context context("1");
    ExpExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretExpAtBeginning) {
    Context context("e10");
    ExpExpression expression;
    string expected = "e";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretExpAtMiddle) {
    Context context("123e10");
    ExpExpression expression;
    context.next(3);
    string expected = "e";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretEmptyString) {
    Context context("");
    ExpExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretWhenContextFinished) {
    Context context("123");
    ExpExpression expression;
    context.next(3);
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretUppercaseE) {
    Context context("E");
    ExpExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretOtherLetters) {
    Context context("f");
    ExpExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretSymbol) {
    Context context(".");
    ExpExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretDoesNotAdvanceContext) {
    Context context("e123");
    ExpExpression expression;
    string expectedToken = "e";
    string expectedRemaining = "e123";

    Token result = expression.interpret(context);
    string remaining = context.get(4);

    EXPECT_EQ(expectedToken, result.getValue());
    EXPECT_EQ(expectedRemaining, remaining);
}

TEST_F(ExpExpressionTest, InterpretMultipleEs) {
    Context context("ee");
    ExpExpression expression;
    string expected = "e";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretExpFollowedByNumbers) {
    Context context("e+10");
    ExpExpression expression;
    string expected = "e";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretExpFollowedBySign) {
    Context context("e-5");
    ExpExpression expression;
    string expected = "e";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretSign) {
    Context context("+");
    ExpExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(ExpExpressionTest, InterpretMinusSign) {
    Context context("-");
    ExpExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}
