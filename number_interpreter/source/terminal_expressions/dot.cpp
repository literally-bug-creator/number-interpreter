#include "terminal_expressions/dot.hpp"

#include <string>

using std::string;

namespace number_interpreter {
Token DotExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string DOT = ".";
    string token = ctx.get(DOT.length());
    return (token == DOT) ? DOT : EMPTY_STR;
}
}  // namespace number_interpreter
