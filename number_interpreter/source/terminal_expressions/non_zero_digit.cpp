#include "terminal_expressions/non_zero_digit.hpp"

#include <array>
#include <string>

using std::ranges::find;

namespace number_interpreter {
std::string NonZeroDigitExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static constexpr uint8_t DIGIT_LENGTH = 1;
    static constexpr std::array<string, 9> DIGITS{"1", "2", "3", "4", "5",
                                                  "6", "7", "8", "9"};
    string token = ctx.get(DIGIT_LENGTH);
    const auto* findIterator = find(DIGITS.begin(), DIGITS.end(), token);
    return (findIterator == DIGITS.end()) ? EMPTY_STR : *findIterator;
}
}  // namespace number_interpreter
