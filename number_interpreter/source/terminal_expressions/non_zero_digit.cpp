#include "terminal_expressions/non_zero_digit.hpp"

#include <string>

using std::string;

namespace number_interpreter {
const array<string, MAX_TOKENS>& NonZeroDigitExpression::getTokens() const {
    static constexpr array<string, MAX_TOKENS> TOKENS = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    return TOKENS;
}

uint8_t NonZeroDigitExpression::getMaxTokenLength() const {
    return 1;
}
}  // namespace number_interpreter
