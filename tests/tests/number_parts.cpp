#include "number_parts.hpp"

#include <gtest/gtest.h>

namespace number_interpreter {
class NumberPartsTest : public ::testing::Test {};

TEST_F(NumberPartsTest, EmptyStringsConstructor) {
    NumberParts parts("", "", "", "");
    bool expectedNegative = false;
    Exponent expectedExponent = 0;
    bool expectedEmpty = true;

    EXPECT_EQ(expectedNegative, parts.isNegative());
    EXPECT_EQ(expectedExponent, parts.getExponent());
    EXPECT_EQ(expectedEmpty, parts.getSignificantDigits().empty());
}

TEST_F(NumberPartsTest, PositiveSignConstructor) {
    NumberParts parts("+", "123", "", "");
    bool expected = false;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, NegativeSignConstructor) {
    NumberParts parts("-", "123", "", "");
    bool expected = true;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, EmptySignConstructor) {
    NumberParts parts("", "123", "", "");
    bool expected = false;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, IsNegativeWithMinus) {
    NumberParts parts("-", "123", "456", "");
    bool expected = true;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, IsNegativeWithPlus) {
    NumberParts parts("+", "123", "456", "");
    bool expected = false;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, IsNegativeWithoutSign) {
    NumberParts parts("", "123", "456", "");
    bool expected = false;

    EXPECT_EQ(expected, parts.isNegative());
}

TEST_F(NumberPartsTest, GetValidExponent) {
    NumberParts parts("", "123", "456", "10");
    Exponent expected = 10;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, GetEmptyExponent) {
    NumberParts parts("", "123", "456", "");
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, GetZeroExponent) {
    NumberParts parts("", "123", "456", "0");
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, GetLargeExponent) {
    NumberParts parts("", "123", "456", "999");
    Exponent expected = 999;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, GetInvalidExponent) {
    NumberParts parts("", "123", "456", "abc");
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, GetBeforeDotDigits) {
    NumberParts parts("", "123", "", "");
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

TEST_F(NumberPartsTest, GetAfterDotDigits) {
    NumberParts parts("", "", "456", "");
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

TEST_F(NumberPartsTest, GetAllDigits) {
    NumberParts parts("", "123", "456", "");
    size_t expectedSize = 6;
    std::vector<uint8_t> expectedDigits = {1, 2, 3, 4, 5, 6};

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    for (size_t i = 0; i < expectedSize; ++i) {
        EXPECT_EQ(expectedDigits[i], digits[i]);
    }
}

TEST_F(NumberPartsTest, GetEmptyDigits) {
    NumberParts parts("", "", "", "");
    bool expectedEmpty = true;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedEmpty, digits.empty());
}

TEST_F(NumberPartsTest, GetDigitsFiltersNonDigits) {
    NumberParts parts("", "1a2b", "3c4d", "");
    size_t expectedSize = 0;
    std::vector<uint8_t> expectedDigits = {};

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    for (size_t i = 0; i < expectedSize; ++i) {
        EXPECT_EQ(expectedDigits[i], digits[i]);
    }
}

TEST_F(NumberPartsTest, GetZeroDigits) {
    NumberParts parts("", "000", "000", "");
    size_t expectedSize = 6;
    uint8_t expectedDigit = 0;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    for (auto digit : digits) {
        EXPECT_EQ(expectedDigit, digit);
    }
}

TEST_F(NumberPartsTest, CompletePositiveNumber) {
    NumberParts parts("+", "123", "456", "10");
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
    NumberParts parts("-", "789", "012", "5");
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

TEST_F(NumberPartsTest, IntegerOnly) {
    NumberParts parts("-", "42", "", "3");
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

TEST_F(NumberPartsTest, FractionalOnly) {
    NumberParts parts("+", "", "25", "7");
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

TEST_F(NumberPartsTest, SingleDigitNumber) {
    NumberParts parts("", "5", "", "");
    size_t expectedSize = 1;
    uint8_t expectedDigit = 5;

    Digits digits = parts.getSignificantDigits();

    EXPECT_EQ(expectedSize, digits.size());
    EXPECT_EQ(expectedDigit, digits[0]);
}

TEST_F(NumberPartsTest, MaxExponent) {
    NumberParts parts("", "1", "", "18446744073709551615");
    Exponent expected = 18446744073709551615ULL;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}

TEST_F(NumberPartsTest, ExponentParsesValidPrefix) {
    NumberParts parts("", "1", "", "123abc");
    Exponent expected = 0;

    Exponent exp = parts.getExponent();

    EXPECT_EQ(expected, exp);
}
}  // namespace number_interpreter
