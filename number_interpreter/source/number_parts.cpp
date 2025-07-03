#include "number_parts.hpp"

#include <cctype>

namespace number_interpreter {
namespace {
bool isNumericString(const string& str) {
    if (str.empty()) {
        return true;
    }
    for (char letter : str) {
        if (std::isdigit(letter) == 0) {
            return false;
        }
    }
    return true;
}
}  // namespace

NumberParts::NumberParts(const string& sign, const string& beforeDot,
                         const string& afterDot, const string& exp)
    : exp_(0), isNegative_(false) {

    // Parse sign
    if (!sign.empty() && sign == "-") {
        isNegative_ = true;
    }

    // Parse exponent
    if (!exp.empty() && isNumericString(exp)) {
        try {
            exp_ = std::stoull(exp);
        } catch (const std::exception&) {
            exp_ = 0;
        }
    }

    // Parse significant digits from beforeDot and afterDot
    string allDigits = beforeDot + afterDot;
    for (char letter : allDigits) {
        if (std::isdigit(letter) != 0) {
            significantDigits_.push_back(static_cast<uint8_t>(letter - '0'));
        }
    }
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
