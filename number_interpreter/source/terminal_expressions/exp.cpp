#include "terminal_expressions/exp.hpp"

#include <string>

#include "exceptions.hpp"

using std::string;

namespace number_interpreter {
Token ExpExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string EXP = "e";
    string token;
    try {
        token = ctx.get(EXP.length());
    } catch (const OutOfRangeException&) {
        return Token(EMPTY_STR);
    }
    if (token == EXP) {
        ctx.next(EXP.length());
        return Token(EXP);
    }
    return Token(EMPTY_STR);
}
}  // namespace number_interpreter
