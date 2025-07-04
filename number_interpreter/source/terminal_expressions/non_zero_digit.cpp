#include "terminal_expressions/non_zero_digit.hpp"

#include <array>

#include "exceptions.hpp"

using std::ranges::find;

namespace number_interpreter {
Token NonZeroDigitExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static constexpr uint8_t DIGIT_LENGTH = 1;
    static constexpr std::array<string, 9> DIGITS{"1", "2", "3", "4", "5",
                                                  "6", "7", "8", "9"};
    string token;
    try {
        token = ctx.get(DIGIT_LENGTH);
    } catch (const OutOfRangeException&) {
        return Token(EMPTY_STR);
    }
    const auto* findIterator = find(DIGITS.begin(), DIGITS.end(), token);
    if (findIterator != DIGITS.end()) {
        ctx.next(DIGIT_LENGTH);
        return Token(*findIterator);
    }
    return Token(EMPTY_STR);
}
}  // namespace number_interpreter
