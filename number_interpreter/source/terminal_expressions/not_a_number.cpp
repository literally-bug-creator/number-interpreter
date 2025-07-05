#include "terminal_expressions/not_a_number.hpp"

#include <string>

using std::string;

namespace number_interpreter {
const array<string, MAX_TOKENS>& NotANumberExpression::getTokens() const {
    static constexpr array<string, MAX_TOKENS> TOKENS = {"nan"};
    return TOKENS;
}

uint8_t NotANumberExpression::getMaxTokenLength() const {
    return 3;
}
}  // namespace number_interpreter
