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
                         const string& afterDot, const string& exp);

    [[nodiscard]] bool isNegative() const;
    [[nodiscard]] Exponent getExponent() const;
    [[nodiscard]] Digits getSignificantDigits() const;

  private:
    Exponent exp_;
    bool isNegative_;
    Digits significantDigits_;
};
}  // namespace number_interpreter
