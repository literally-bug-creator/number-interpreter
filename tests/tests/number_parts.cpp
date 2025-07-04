#include "number_parts.hpp"

#include <gtest/gtest.h>

using namespace number_interpreter;

class NumberPartsTest : public ::testing::Test {};

TEST_F(NumberPartsTest, EmptyInputReturnsDefaults) {
    NumberParts parts("", "", "", "", false, false);
    bool expectedNegative = false;
    Exponent expectedExponent = 0;
    bool expectedEmpty = true;
    bool expectedInf = false;
    bool expectedNan = false;

    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());
    EXPECT_EQ(expectedEmpty, parts.getSignificantDigits().empty());
    EXPECT_EQ(expectedInf, parts.isInf());
    EXPECT_EQ(expectedNan, parts.isNan());
}

TEST_F(NumberPartsTest, PositiveSignRecognized) {
    NumberParts parts("+", "123", "", "", false, false);
    bool expected = false;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, NegativeSignRecognized) {
    NumberParts parts("-", "123", "", "", false, false);
    bool expected = true;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, EmptySignIsPositive) {
    NumberParts parts("", "123", "", "", false, false);
    bool expected = false;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, InvalidSignIsPositive) {
    NumberParts parts("invalid", "123", "", "", false, false);
    bool expected = false;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, MultipleSignsIgnored) {
    NumberParts parts("--", "123", "", "", false, false);
    bool expected = false;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, ValidExponentParsed) {
    NumberParts parts("", "123", "456", "10", false, false);
    Exponent expected = 10;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, EmptyExponentIsZero) {
    NumberParts parts("", "123", "456", "", false, false);
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, ZeroExponentParsed) {
    NumberParts parts("", "123", "456", "0", false, false);
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, LargeExponentParsed) {
    NumberParts parts("", "123", "456", "999", false, false);
    Exponent expected = 999;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, MaxExponentParsed) {
    NumberParts parts("", "1", "", "18446744073709551615", false, false);
    Exponent expected = 18446744073709551615ULL;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, InvalidExponentIsZero) {
    NumberParts parts("", "123", "456", "abc", false, false);
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, ExponentWithLeadingZeros) {
    NumberParts parts("", "1", "", "0123", false, false);
    Exponent expected = 123;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, ExponentWithOnlyZeros) {
    NumberParts parts("", "1", "", "000", false, false);
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, ExponentWithMixedInvalidChars) {
    NumberParts parts("", "1", "", "1a2b3", false, false);
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, BeforeDotDigitsParsed) {
    NumberParts parts("", "123", "", "", false, false);
    size_t expectedSize = 3;
    uint8_t expectedFirst = 1;
    uint8_t expectedSecond = 2;
    uint8_t expectedThird = 3;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    EXPECT_EQ(expectedFirst, digits[0]);
    EXPECT_EQ(expectedSecond, digits[1]);
    EXPECT_EQ(expectedThird, digits[2]);
}

TEST_F(NumberPartsTest, AfterDotDigitsParsed) {
    NumberParts parts("", "", "456", "", false, false);
    size_t expectedSize = 3;
    uint8_t expectedFirst = 4;
    uint8_t expectedSecond = 5;
    uint8_t expectedThird = 6;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    EXPECT_EQ(expectedFirst, digits[0]);
    EXPECT_EQ(expectedSecond, digits[1]);
    EXPECT_EQ(expectedThird, digits[2]);
}

TEST_F(NumberPartsTest, AllDigitsCombined) {
    NumberParts parts("", "123", "456", "", false, false);
    size_t expectedSize = 6;
    std::vector<uint8_t> expectedDigits = {1, 2, 3, 4, 5, 6};

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    for (size_t i = 0; i < expectedSize; ++i) {
        EXPECT_EQ(expectedDigits[i], digits[i]);
    }
}

TEST_F(NumberPartsTest, EmptyDigitsReturnEmpty) {
    NumberParts parts("", "", "", "", false, false);
    bool expectedEmpty = true;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedEmpty, digits.empty());
}

TEST_F(NumberPartsTest, InvalidDigitsReturnEmpty) {
    NumberParts parts("", "1a2b", "3c4d", "", false, false);
    size_t expectedSize = 0;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
}

TEST_F(NumberPartsTest, OnlyBeforeDotInvalid) {
    NumberParts parts("", "1a2", "", "", false, false);
    bool expectedEmpty = true;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedEmpty, digits.empty());
}

TEST_F(NumberPartsTest, OnlyAfterDotInvalid) {
    NumberParts parts("", "", "1a2", "", false, false);
    bool expectedEmpty = true;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedEmpty, digits.empty());
}

TEST_F(NumberPartsTest, ZeroDigitsParsed) {
    NumberParts parts("", "000", "000", "", false, false);
    size_t expectedSize = 6;
    uint8_t expectedDigit = 0;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    for (auto digit : digits) {
        EXPECT_EQ(expectedDigit, digit);
    }
}

TEST_F(NumberPartsTest, SingleDigitParsed) {
    NumberParts parts("", "5", "", "", false, false);
    size_t expectedSize = 1;
    uint8_t expectedDigit = 5;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    EXPECT_EQ(expectedDigit, digits[0]);
}

TEST_F(NumberPartsTest, IntegerOnlyParsed) {
    NumberParts parts("-", "42", "", "3", false, false);
    bool expectedNegative = true;
    Exponent expectedExponent = 3;
    size_t expectedSize = 2;
    uint8_t expectedFirst = 4;
    uint8_t expectedSecond = 2;

    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());

    Digits digits = parts.getSignificantDigits();
    EXPECT_EQ(expectedSize, digits.size());
    EXPECT_EQ(expectedFirst, digits[0]);
    EXPECT_EQ(expectedSecond, digits[1]);
}

TEST_F(NumberPartsTest, FractionalOnlyParsed) {
    NumberParts parts("+", "", "25", "7", false, false);
    bool expectedNegative = false;
    Exponent expectedExponent = 7;
    size_t expectedSize = 2;
    uint8_t expectedFirst = 2;
    uint8_t expectedSecond = 5;

    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());

    Digits digits = parts.getSignificantDigits();
    EXPECT_EQ(expectedSize, digits.size());
    EXPECT_EQ(expectedFirst, digits[0]);
    EXPECT_EQ(expectedSecond, digits[1]);
}

TEST_F(NumberPartsTest, CompletePositiveNumber) {
    NumberParts parts("+", "123", "456", "10", false, false);
    bool expectedNegative = false;
    Exponent expectedExponent = 10;
    size_t expectedSize = 6;
    std::vector<uint8_t> expectedDigits = {1, 2, 3, 4, 5, 6};

    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());

    Digits digits = parts.getSignificantDigits();
    EXPECT_EQ(expectedSize, digits.size());
    for (size_t i = 0; i < expectedSize; ++i) {
        EXPECT_EQ(expectedDigits[i], digits[i]);
    }
}

TEST_F(NumberPartsTest, CompleteNegativeNumber) {
    NumberParts parts("-", "789", "012", "5", false, false);
    bool expectedNegative = true;
    Exponent expectedExponent = 5;
    size_t expectedSize = 6;
    std::vector<uint8_t> expectedDigits = {7, 8, 9, 0, 1, 2};

    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());

    Digits digits = parts.getSignificantDigits();
    EXPECT_EQ(expectedSize, digits.size());
    for (size_t i = 0; i < expectedSize; ++i) {
        EXPECT_EQ(expectedDigits[i], digits[i]);
    }
}

TEST_F(NumberPartsTest, IsInfWhenSet) {
    NumberParts parts("", "123", "456", "", true, false);
    bool expected = true;

    bool result = parts.isInf();

    EXPECT_EQ(expected, result);
}

TEST_F(NumberPartsTest, IsInfWhenNotSet) {
    NumberParts parts("", "123", "456", "", false, false);
    bool expected = false;

    bool result = parts.isInf();

    EXPECT_EQ(expected, result);
}

TEST_F(NumberPartsTest, IsNanWhenSet) {
    NumberParts parts("", "123", "456", "", false, true);
    bool expected = true;

    bool result = parts.isNan();

    EXPECT_EQ(expected, result);
}

TEST_F(NumberPartsTest, IsNanWhenNotSet) {
    NumberParts parts("", "123", "456", "", false, false);
    bool expected = false;

    bool result = parts.isNan();

    EXPECT_EQ(expected, result);
}