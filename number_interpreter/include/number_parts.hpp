#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace number_interpreter {
using std::string;
using Exponent = uint64_t;
using Digits = std::vector<uint8_t>;

class NumberParts {
  public:
    explicit NumberParts(const string& sign, const string& beforeDot,
                         const string& afterDot, const string& exp, bool isInf,
                         bool isNan);

    [[nodiscard]] bool isInf() const;
    [[nodiscard]] bool isNan() const;
    [[nodiscard]] bool isNegative() const;
    [[nodiscard]] Exponent getExponent() const;
    [[nodiscard]] Digits getSignificantDigits() const;

  private:
    Exponent exp_;
    bool isNegative_;
    Digits significantDigits_;
    bool isInf_ = false;
    bool isNan_ = false;
};
}  // namespace number_interpreter
