#include "terminal_expressions/sign.hpp"

#include <string>

#include "exceptions.hpp"

using std::string;

namespace number_interpreter {
Token SignExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string MINUS = "-";
    static const string PLUS = "+";
    static const uint8_t SIGN_LENGTH = 1;
    string token;
    try {
        token = ctx.get(SIGN_LENGTH);
    } catch (const OutOfRangeException&) {
        return Token(EMPTY_STR);
    }
    return (token == MINUS) || (token == PLUS) ? Token(token)
                                               : Token(EMPTY_STR);
}
}  // namespace number_interpreter
