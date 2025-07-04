#include "terminal_expressions/dot.hpp"

#include <string>

#include "exceptions.hpp"

using std::string;

namespace number_interpreter {
Token DotExpression::interpret(Context& ctx) const {
    const string EMPTY_STR;
    const string DOT = ".";
    string token;
    try {
        token = ctx.get(DOT.length());
    } catch (const OutOfRangeException&) {
        return Token(EMPTY_STR);
    }
    if (token == DOT) {
        ctx.next(DOT.length());
        return Token(DOT);
    }
    return Token(EMPTY_STR);
}
}  // namespace number_interpreter
