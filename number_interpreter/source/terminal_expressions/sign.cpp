#include "terminal_expressions/sign.hpp"

#include <string>

using std::string;

namespace number_interpreter {
Token SignExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string MINUS = "-";
    static const string PLUS = "+";
    string token = ctx.get(MINUS.length());
    return (token == MINUS) || (token == PLUS) ? Token(token)
                                               : Token(EMPTY_STR);
}
}  // namespace number_interpreter
