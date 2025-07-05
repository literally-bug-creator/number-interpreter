#include "terminal_expressions/sign.hpp"

#include <string>

using std::string;

namespace number_interpreter {
const array<string, MAX_TOKENS>& SignExpression::getTokens() const {
    static constexpr array<string, MAX_TOKENS> TOKENS = {"-", "+"};
    return TOKENS;
}

uint8_t SignExpression::getMaxTokenLength() const {
    return 1;
}
}  // namespace number_interpreter
