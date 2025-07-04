#include "terminal_expressions/infinity.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class InfinityExpressionTest : public ::testing::Test {};

TEST_F(InfinityExpressionTest, InterpretValidInfinity) {
    Context context("inf");
    InfinityExpression expression;
    string expected = "inf";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInvalidCharacter) {
    Context context("x");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretNumber) {
    Context context("123");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInfAtBeginning) {
    Context context("infinity");
    InfinityExpression expression;
    string expected = "inf";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInfAtMiddle) {
    Context context("123inf456");
    InfinityExpression expression;
    context.next(3);
    string expected = "inf";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretEmptyString) {
    Context context("");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretWhenContextFinished) {
    Context context("123");
    InfinityExpression expression;
    context.next(3);
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretUppercaseInf) {
    Context context("INF");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretMixedCaseInf) {
    Context context("Inf");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretPartialInf) {
    Context context("in");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInfWithExtraCharacters) {
    Context context("inf123");
    InfinityExpression expression;
    string expected = "inf";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretDoesNotAdvanceContext) {
    Context context("infinity");
    InfinityExpression expression;
    string expectedToken = "inf";
    string expectedRemaining = "infinity";

    Token result = expression.interpret(context);
    string remaining = context.get(8);

    EXPECT_EQ(expectedToken, result.getValue());
    EXPECT_EQ(expectedRemaining, remaining);
}

TEST_F(InfinityExpressionTest, InterpretOnlyI) {
    Context context("i");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretTwoCharacters) {
    Context context("if");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretAlmostInf) {
    Context context("ini");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInfWhenNotEnoughCharacters) {
    Context context("ab");
    InfinityExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInfFollowedByDot) {
    Context context("inf.");
    InfinityExpression expression;
    string expected = "inf";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(InfinityExpressionTest, InterpretInfFollowedBySpace) {
    Context context("inf ");
    InfinityExpression expression;
    string expected = "inf";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}
