#include "terminal_expressions/infinity.hpp"

#include <string>

using std::string;

namespace number_interpreter {
const array<string, MAX_TOKENS>& InfinityExpression::getTokens() const {
    static constexpr array<string, MAX_TOKENS> TOKENS = {"inf"};
    return TOKENS;
}

uint8_t InfinityExpression::getMaxTokenLength() const {
    return 3;
}
}  // namespace number_interpreter
