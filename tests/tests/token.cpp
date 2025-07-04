#include <gtest/gtest.h>

#include "abstract_expression.hpp"

using namespace number_interpreter;

class TokenTest : public ::testing::Test {};

TEST_F(TokenTest, EmptyTokenIsEmpty) {
    Token token("");
    bool expected = true;

    bool result = token.isEmpty();

    EXPECT_EQ(expected, result);
}

TEST_F(TokenTest, NonEmptyTokenIsNotEmpty) {
    Token token("hello");
    bool expected = false;

    bool result = token.isEmpty();

    EXPECT_EQ(expected, result);
}

TEST_F(TokenTest, GetValueReturnsEmptyString) {
    Token token("");
    string expected;

    string result = token.getValue();

    EXPECT_EQ(expected, result);
}

TEST_F(TokenTest, GetValueReturnsStoredValue) {
    Token token("hello world");
    string expected = "hello world";

    string result = token.getValue();

    EXPECT_EQ(expected, result);
}

TEST_F(TokenTest, MergeEmptyTokens) {
    Token token1("");
    Token token2("");
    string expected;

    Token result = token1.merge(token2);

    EXPECT_EQ(expected, result.getValue());
}

TEST_F(TokenTest, MergeEmptyWithNonEmpty) {
    Token token1("");
    Token token2("hello");
    string expected = "hello";

    Token result = token1.merge(token2);

    EXPECT_EQ(expected, result.getValue());
}

TEST_F(TokenTest, MergeNonEmptyWithEmpty) {
    Token token1("hello");
    Token token2("");
    string expected = "hello";

    Token result = token1.merge(token2);

    EXPECT_EQ(expected, result.getValue());
}

TEST_F(TokenTest, MergeNonEmptyTokens) {
    Token token1("hello");
    Token token2("world");
    string expected = "helloworld";

    Token result = token1.merge(token2);

    EXPECT_EQ(expected, result.getValue());
}

TEST_F(TokenTest, MergeChaining) {
    Token token1("a");
    Token token2("b");
    Token token3("c");
    string expected = "abc";

    Token result = token1.merge(token2).merge(token3);

    EXPECT_EQ(expected, result.getValue());
}

TEST_F(TokenTest, MergeDoesNotModifyOriginals) {
    Token token1("hello");
    Token token2("world");
    string expectedOriginal1 = "hello";
    string expectedOriginal2 = "world";
    string expectedMerged = "helloworld";

    Token merged = token1.merge(token2);

    EXPECT_EQ(expectedOriginal1, token1.getValue());
    EXPECT_EQ(expectedOriginal2, token2.getValue());
    EXPECT_EQ(expectedMerged, merged.getValue());
}

TEST_F(TokenTest, MergedEmptyTokenIsEmpty) {
    Token token1("");
    Token token2("");
    bool expected = true;

    Token result = token1.merge(token2);

    EXPECT_EQ(expected, result.isEmpty());
}

TEST_F(TokenTest, MergedNonEmptyTokenIsNotEmpty) {
    Token token1("a");
    Token token2("b");
    bool expected = false;

    Token result = token1.merge(token2);

    EXPECT_EQ(expected, result.isEmpty());
}
