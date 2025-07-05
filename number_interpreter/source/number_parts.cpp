#include "number_parts.hpp"

#include <algorithm>
#include <cctype>
#include <string>

namespace number_interpreter {
namespace {
bool parseSign(const string& str) {
    return !str.empty() && str.front() == '-';
}

string extractSignFromBeforeDot(const string& str) {
    if (!str.empty() && (str.front() == '-' || str.front() == '+')) {
        return str.substr(0, 1);
    }
    return "";
}

string removeSignFromBeforeDot(const string& str) {
    if (!str.empty() && (str.front() == '-' || str.front() == '+')) {
        return str.substr(1);
    }
    return str;
}

string removeDotFromAfterDot(const string& str) {
    if (!str.empty() && str.front() == '.') {
        return str.substr(1);
    }
    return str;
}

string removeExpFromExponent(const string& str) {
    if (!str.empty() && (str.front() == 'e' || str.front() == 'E')) {
        return str.substr(1);
    }
    return str;
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
    string cleanStr = removeExpFromExponent(str);
    if (cleanStr.empty() || !std::ranges::all_of(cleanStr, [](char letter) {
            return std::isdigit(letter) != 0;
        })) {
        return 0;
    }
    return std::stoull(cleanStr);
}

Digits parseSignificantDigits(const string& beforeDot, const string& afterDot) {
    string cleanBeforeDot = removeSignFromBeforeDot(beforeDot);
    string cleanAfterDot = removeDotFromAfterDot(afterDot);

    Digits beforeDigits = parseDigitString(cleanBeforeDot);
    if (beforeDigits.empty() && !cleanBeforeDot.empty()) {
        return {};
    }

    Digits afterDigits = parseDigitString(cleanAfterDot);
    if (afterDigits.empty() && !cleanAfterDot.empty()) {
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
                         const string& afterDot, const string& exp, bool isInf,
                         bool isNan)
    : exp_(parseExponent(exp)),
      isNegative_(
          parseSign(sign.empty() ? extractSignFromBeforeDot(beforeDot) : sign)),
      significantDigits_(parseSignificantDigits(beforeDot, afterDot)),
      isInf_(isInf), isNan_(isNan) {}

bool NumberParts::isInf() const {
    return isInf_;
}

bool NumberParts::isNan() const {
    return isNan_;
}

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
