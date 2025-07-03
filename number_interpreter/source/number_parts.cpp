#include "number_parts.hpp"

#include <algorithm>
#include <cctype>
#include <string>

namespace number_interpreter {
namespace {
bool parseSign(const string& str) {
    return !str.empty() && str == "-";
}

bool isNumericString(const string& str) {
    if (str.empty()) {
        return false;
    }
    return std::ranges::all_of(
        str, [](char letter) { return std::isdigit(letter) != 0; });
}

Exponent parseExponent(const string& str) {
    if (!isNumericString(str)) {
        return 0;
    }
    return std::stoull(str);
}

Digits parseSignificantDigits(const string& beforeDot, const string& afterDot) {
    string allDigits = beforeDot + afterDot;
    if (!isNumericString(allDigits)) {
        return {};
    }
    Digits significantDigits;
    significantDigits.reserve(allDigits.size());
    for (char letter : allDigits) {
        significantDigits.push_back(static_cast<uint8_t>(letter - '0'));
    }
    return significantDigits;
}
}  // namespace

NumberParts::NumberParts(const string& sign, const string& beforeDot,
                         const string& afterDot, const string& exp)
    : exp_(parseExponent(exp)), isNegative_(parseSign(sign)),
      significantDigits_(parseSignificantDigits(beforeDot, afterDot)) {}

bool NumberParts::isNegative() const {
    return isNegative_;
}

Exponent NumberParts::getExponent() const {
    return exp_;
}

Digits NumberParts::getSignificantDigits() const {
    return significantDigits_;
}
}  // namespace number_interpreter
