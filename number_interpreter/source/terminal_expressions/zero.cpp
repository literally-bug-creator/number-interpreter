#include "terminal_expressions/zero.hpp"

#include <string>

namespace number_interpreter {
std::string ZeroExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string ZERO = "0";
    string token = ctx.get(ZERO.length());
    return (token == ZERO) ? ZERO : EMPTY_STR;
}
}  // namespace number_interpreter
