#pragma clang diagnostic ignored "-Wunused-result"

#include "context.hpp"

#include <gtest/gtest.h>

#include "exceptions.hpp"
#include "number_parts.hpp"

using namespace number_interpreter;

class ContextTest : public ::testing::Test {};

TEST_F(ContextTest, EmptyStringIsFinished) {
    Context context("");
    bool expected = true;

    EXPECT_EQ(expected, context.isFinished());
}

TEST_F(ContextTest, NonEmptyStringNotFinished) {
    Context context("12345");
    bool expected = false;

    EXPECT_EQ(expected, context.isFinished());
}

TEST_F(ContextTest, FinishedAfterProcessing) {
    Context context("123");
    context.next(3);
    bool expected = true;

    EXPECT_EQ(expected, context.isFinished());
}

TEST_F(ContextTest, FinishedBeyondEnd) {
    Context context("12");
    context.next(5);
    bool expected = true;

    EXPECT_EQ(expected, context.isFinished());
}

TEST_F(ContextTest, GetSingleCharacter) {
    Context context("hello");
    string expected = "h";

    string result = context.get(1);

    EXPECT_EQ(expected, result);
}

TEST_F(ContextTest, GetMultipleCharacters) {
    Context context("hello");
    string expected = "hel";

    string result = context.get(3);

    EXPECT_EQ(expected, result);
}

TEST_F(ContextTest, GetFromMiddle) {
    Context context("hello");
    context.next(2);
    string expected = "ll";

    string result = context.get(2);

    EXPECT_EQ(expected, result);
}

TEST_F(ContextTest, GetWithZeroLength) {
    Context context("hello");
    string expected;

    string result = context.get(0);

    EXPECT_EQ(expected, result);
}

TEST_F(ContextTest, GetExactLength) {
    Context context("hello");
    string expected = "hello";

    string result = context.get(5);

    EXPECT_EQ(expected, result);
}

TEST_F(ContextTest, GetThrowsOutOfRange) {
    Context context("hi");

    EXPECT_THROW(context.get(3), OutOfRangeException);
}

TEST_F(ContextTest, GetThrowsWhenFinished) {
    Context context("hi");
    context.next(2);

    EXPECT_THROW(context.get(1), OutOfRangeException);
}

TEST_F(ContextTest, GetThrowsOnEmptyStringWithNonZeroLength) {
    Context context("");

    EXPECT_THROW(context.get(1), OutOfRangeException);
}

TEST_F(ContextTest, GetThrowsWhenIndexPlusLengthOverflows) {
    Context context("test");

    EXPECT_THROW(context.get(SIZE_MAX), OutOfRangeException);
}

TEST_F(ContextTest, GetStateUnchangedAfterException) {
    Context context("hello");
    context.next(2);
    context.setSign("-");

    EXPECT_THROW(context.get(4), OutOfRangeException);

    // Context state should remain unchanged after exception
    EXPECT_EQ("l", context.get(1));
    EXPECT_FALSE(context.isFinished());
    NumberParts parts = context.buildNumberParts();
    EXPECT_TRUE(parts.isNegative());
}

TEST_F(ContextTest, NextMovesForward) {
    Context context("hello");
    context.next(2);
    string expected = "l";

    string result = context.get(1);

    EXPECT_EQ(expected, result);
}

TEST_F(ContextTest, NextWithZero) {
    Context context("hello");
    context.next(0);
    string expected = "h";

    string result = context.get(1);

    EXPECT_EQ(expected, result);
}

TEST_F(ContextTest, NextBeyondEnd) {
    Context context("hi");
    context.next(10);
    bool expected = true;

    EXPECT_EQ(expected, context.isFinished());
}

TEST_F(ContextTest, SetSignNegative) {
    Context context("test");
    context.setSign("-");
    bool expected = true;

    NumberParts parts = context.buildNumberParts();

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(ContextTest, SetBeforeDot) {
    Context context("test");

    context.setBeforeDot("123");
    NumberParts parts = context.buildNumberParts();

    EXPECT_NO_THROW(parts.getSignificantDigits());
}

TEST_F(ContextTest, SetAfterDot) {
    Context context("test");

    context.setAfterDot("456");
    NumberParts parts = context.buildNumberParts();

    EXPECT_NO_THROW(parts.getSignificantDigits());
}

TEST_F(ContextTest, SetExp) {
    Context context("test");

    context.setExp("10");
    NumberParts parts = context.buildNumberParts();

    EXPECT_NO_THROW(parts.getExponent());
}

TEST_F(ContextTest, SetIsInfTrue) {
    Context context("test");
    context.setIsInf(true);

    NumberParts parts = context.buildNumberParts();

    EXPECT_TRUE(parts.isInf());
}

TEST_F(ContextTest, SetIsInfFalse) {
    Context context("test");
    context.setIsInf(false);

    NumberParts parts = context.buildNumberParts();

    EXPECT_FALSE(parts.isInf());
}

TEST_F(ContextTest, SetIsNanTrue) {
    Context context("test");
    context.setIsNan(true);

    NumberParts parts = context.buildNumberParts();

    EXPECT_TRUE(parts.isNan());
}

TEST_F(ContextTest, SetIsNanFalse) {
    Context context("test");
    context.setIsNan(false);

    NumberParts parts = context.buildNumberParts();

    EXPECT_FALSE(parts.isNan());
}

TEST_F(ContextTest, BuildEmptyNumberParts) {
    Context context("test");
    bool expectedNegative = false;
    Exponent expectedExponent = 0;

    NumberParts parts = context.buildNumberParts();

    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());
}

TEST_F(ContextTest, BuildCompleteNumberParts) {
    Context context("test");
    context.setSign("-");
    context.setBeforeDot("123");
    context.setAfterDot("456");
    context.setExp("2");
    bool expectedNegative = true;
    Exponent expectedExponent = 2;

    NumberParts parts = context.buildNumberParts();

    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());
}

TEST_F(ContextTest, BackupAndRestore) {
    Context context("hello");
    context.next(2);
    context.setSign("-");
    context.setBeforeDot("123");
    ContextImage backup = context.backup();
    context.next(2);
    context.setSign("+");
    context.setBeforeDot("456");
    context.restore(backup);
    string expectedChar = "l";
    bool expectedNegative = true;

    EXPECT_EQ(expectedChar, context.get(1));
    NumberParts parts = context.buildNumberParts();
    EXPECT_EQ(expectedNegative, parts.isNegative());
}

TEST_F(ContextTest, BackupRestoreAllFields) {
    Context context("hello");
    context.next(1);
    context.setSign("-");
    context.setBeforeDot("123");
    context.setAfterDot("456");
    context.setExp("10");
    context.setIsInf(true);
    context.setIsNan(true);

    ContextImage backup = context.backup();

    context.next(2);
    context.setSign("+");
    context.setBeforeDot("789");
    context.setAfterDot("012");
    context.setExp("5");
    context.setIsInf(false);
    context.setIsNan(false);

    context.restore(backup);

    string expectedChar = "e";
    bool expectedNegative = true;
    Exponent expectedExponent = 10;

    EXPECT_EQ(expectedChar, context.get(1));
    NumberParts parts = context.buildNumberParts();
    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());
    EXPECT_TRUE(parts.isInf());
    EXPECT_TRUE(parts.isNan());
}

TEST_F(ContextTest, MultipleBackupRestore) {
    Context context("hello");
    context.next(1);
    context.setSign("-");
    ContextImage backup1 = context.backup();
    context.next(1);
    context.setSign("+");
    ContextImage backup2 = context.backup();
    context.next(1);
    context.restore(backup1);
    string expectedChar = "e";
    bool expectedNegative = true;

    EXPECT_EQ(expectedChar, context.get(1));
    NumberParts parts = context.buildNumberParts();
    EXPECT_EQ(expectedNegative, parts.isNegative());
}

TEST_F(ContextTest, MultipleSettersOverwrite) {
    Context context("test");
    context.setSign("-");
    context.setSign("+");
    context.setBeforeDot("123");
    context.setBeforeDot("456");

    NumberParts parts = context.buildNumberParts();

    EXPECT_FALSE(parts.isNegative());
    Digits digits = parts.getSignificantDigits();
    EXPECT_EQ(3, digits.size());
    EXPECT_EQ(4, digits[0]);
    EXPECT_EQ(5, digits[1]);
    EXPECT_EQ(6, digits[2]);
}

TEST_F(ContextTest, CompleteNumberParsing) {
    Context context("-123.456e10");
    context.setSign(context.get(1));
    context.next(1);
    context.setBeforeDot(context.get(3));
    context.next(3);
    context.next(1);
    context.setAfterDot(context.get(3));
    context.next(3);
    context.next(1);
    context.setExp(context.get(2));
    context.next(2);
    bool expectedFinished = true;
    bool expectedNegative = true;
    Exponent expectedExponent = 10;

    EXPECT_EQ(expectedFinished, context.isFinished());
    NumberParts parts = context.buildNumberParts();
    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());
}

TEST_F(ContextTest, SequentialOperations) {
    Context context("abcdef");
    string expectedFirst = "a";
    string expectedSecond = "b";
    string expectedThird = "cd";
    string expectedFourth = "ef";
    bool expectedFinished = true;

    EXPECT_EQ(expectedFirst, context.get(1));
    context.next(1);
    EXPECT_EQ(expectedSecond, context.get(1));
    context.next(1);
    EXPECT_EQ(expectedThird, context.get(2));
    context.next(2);
    EXPECT_EQ(expectedFourth, context.get(2));
    context.next(2);
    EXPECT_EQ(expectedFinished, context.isFinished());
}

TEST_F(ContextTest, EmptyStringOperations) {
    Context context("");
    bool expectedFinished = true;

    EXPECT_EQ(expectedFinished, context.isFinished());
    EXPECT_THROW(context.get(1), OutOfRangeException);
}

TEST_F(ContextTest, SingleCharacterString) {
    Context context("x");
    bool expectedInitialFinished = false;
    string expectedChar = "x";
    bool expectedFinalFinished = true;

    EXPECT_EQ(expectedInitialFinished, context.isFinished());
    EXPECT_EQ(expectedChar, context.get(1));
    context.next(1);
    EXPECT_EQ(expectedFinalFinished, context.isFinished());
}
