#include "terminal_expressions/dot.hpp"

#include <string>

using std::string;

namespace number_interpreter {
const array<string, MAX_TOKENS>& DotExpression::getTokens() const {
    static constexpr array<string, MAX_TOKENS> TOKENS = {"."};
    return TOKENS;
}

uint8_t DotExpression::getMaxTokenLength() const {
    return 1;
}
}  // namespace number_interpreter
