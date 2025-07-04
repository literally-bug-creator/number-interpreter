#include "terminal_expressions/not_a_number.hpp"

#include <gtest/gtest.h>

#include "context.hpp"

using namespace number_interpreter;

class NotANumberExpressionTest : public ::testing::Test {};

TEST_F(NotANumberExpressionTest, InterpretValidNan) {
    Context context("nan");
    NotANumberExpression expression;
    string expected = "nan";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretInvalidCharacter) {
    Context context("x");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNumber) {
    Context context("123");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNanAtBeginning) {
    Context context("nanana");
    NotANumberExpression expression;
    string expected = "nan";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNanAtMiddle) {
    Context context("123nan456");
    NotANumberExpression expression;
    context.next(3);
    string expected = "nan";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretEmptyString) {
    Context context("");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretWhenContextFinished) {
    Context context("123");
    NotANumberExpression expression;
    context.next(3);
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretUppercaseNan) {
    Context context("NAN");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretMixedCaseNan) {
    Context context("Nan");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretPartialNan) {
    Context context("na");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNanWithExtraCharacters) {
    Context context("nan123");
    NotANumberExpression expression;
    string expected = "nan";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretDoesNotAdvanceContext) {
    Context context("nanana");
    NotANumberExpression expression;
    string expectedToken = "nan";
    string expectedRemaining = "nanana";

    Token result = expression.interpret(context);
    string remaining = context.get(6);

    EXPECT_EQ(expectedToken, result.getValue());
    EXPECT_EQ(expectedRemaining, remaining);
}

TEST_F(NotANumberExpressionTest, InterpretOnlyN) {
    Context context("n");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretTwoCharacters) {
    Context context("no");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretAlmostNan) {
    Context context("nab");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNanWhenNotEnoughCharacters) {
    Context context("ab");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNanFollowedByDot) {
    Context context("nan.");
    NotANumberExpression expression;
    string expected = "nan";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretNanFollowedBySpace) {
    Context context("nan ");
    NotANumberExpression expression;
    string expected = "nan";

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_FALSE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretInf) {
    Context context("inf");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}

TEST_F(NotANumberExpressionTest, InterpretRandomString) {
    Context context("xyz");
    NotANumberExpression expression;
    string expected;

    Token result = expression.interpret(context);

    EXPECT_EQ(expected, result.getValue());
    EXPECT_TRUE(result.isEmpty());
}
