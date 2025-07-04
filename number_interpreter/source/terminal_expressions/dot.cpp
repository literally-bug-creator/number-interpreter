#include "terminal_expressions/dot.hpp"

#include <string>

#include "exceptions.hpp"

using std::string;

namespace number_interpreter {
Token DotExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string DOT = ".";
    string token;
    try {
        token = ctx.get(DOT.length());
    } catch (const OutOfRangeException&) {
        return Token(EMPTY_STR);
    }
    return (token == DOT) ? Token(DOT) : Token(EMPTY_STR);
}
}  // namespace number_interpreter
