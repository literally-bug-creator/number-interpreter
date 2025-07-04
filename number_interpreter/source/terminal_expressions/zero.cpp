#include "terminal_expressions/zero.hpp"

#include <string>

using std::string;

namespace number_interpreter {
Token ZeroExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string ZERO = "0";
    string token = ctx.get(ZERO.length());
    return (token == ZERO) ? Token(ZERO) : Token(EMPTY_STR);
}
}  // namespace number_interpreter
