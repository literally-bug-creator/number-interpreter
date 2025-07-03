#include "number_parts.hpp"

#include <algorithm>
#include <cctype>
#include <string>

namespace number_interpreter {
namespace {
bool parseSign(const string& str) {
    return !str.empty() && str == "-";
}

Digits parseDigitString(const string& str) {
    Digits digits;
    digits.reserve(str.size());
    for (char letter : str) {
        if (std::isdigit(letter) == 0) {
            return {};
        }
        digits.push_back(static_cast<uint8_t>(letter - '0'));
    }
    return digits;
}

Exponent parseExponent(const string& str) {
    if (str.empty() || !std::ranges::all_of(str, [](char letter) {
            return std::isdigit(letter) != 0;
        })) {
        return 0;
    }
    return std::stoull(str);
}

Digits parseSignificantDigits(const string& beforeDot, const string& afterDot) {
    Digits beforeDigits = parseDigitString(beforeDot);
    if (beforeDigits.empty() && !beforeDot.empty()) {
        return {};
    }

    Digits afterDigits = parseDigitString(afterDot);
    if (afterDigits.empty() && !afterDot.empty()) {
        return {};
    }

    beforeDigits.reserve(beforeDigits.size() + afterDigits.size());
    beforeDigits.insert(beforeDigits.end(),
                        std::make_move_iterator(afterDigits.begin()),
                        std::make_move_iterator(afterDigits.end()));

    return beforeDigits;
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
