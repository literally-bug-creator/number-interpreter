#include "terminal_expressions/exp.hpp"

#include <string>

using std::string;

namespace number_interpreter {
const array<string, MAX_TOKENS>& ExpExpression::getTokens() const {
    static constexpr array<string, MAX_TOKENS> TOKENS = {"e"};
    return TOKENS;
}

uint8_t ExpExpression::getMaxTokenLength() const {
    return 1;
}
}  // namespace number_interpreter
