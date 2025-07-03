#pragma once

#include <cstdint>
#include <string>
#include <vector>

using std::string;
using Exponent = uint64_t;
using Digits = std::vector<uint8_t>;

class NumberParts {
  public:
    NumberParts(string sign, string beforeDot, string afterDot, string exp);

    bool isNegative();
    Exponent getExponent();
    Digits getSignificantDigits();

  private:
    Exponent exp_;
    bool isNegative_;
    Digits significantDigits_;
};
