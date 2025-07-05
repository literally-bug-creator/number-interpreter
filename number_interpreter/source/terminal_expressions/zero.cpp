#include "terminal_expressions/zero.hpp"

#include <string>

using std::string;

namespace number_interpreter {
const array<string, MAX_TOKENS>& ZeroExpression::getTokens() const {
    static constexpr array<string, MAX_TOKENS> TOKENS = {"0"};
    return TOKENS;
}

uint8_t ZeroExpression::getMaxTokenLength() const {
    return 1;
}
}  // namespace number_interpreter
