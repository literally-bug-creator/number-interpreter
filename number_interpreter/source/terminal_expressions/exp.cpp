#include "terminal_expressions/exp.hpp"

#include <string>

using std::string;

namespace number_interpreter {
Token ExpExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string EXP = "e";
    string token = ctx.get(EXP.length());
    return (token == EXP) ? Token(EXP) : Token(EMPTY_STR);
}
}  // namespace number_interpreter
