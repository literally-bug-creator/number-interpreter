#include "terminal_expressions/not_a_number.hpp"

#include <string>

#include "exceptions.hpp"

using std::string;

namespace number_interpreter {
Token NotANumberExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string NAN = "nan";
    string token;
    try {
        token = ctx.get(NAN.length());
    } catch (const OutOfRangeException&) {
        return Token(EMPTY_STR);
    }
    if (token == NAN) {
        ctx.next(NAN.length());
        return Token(NAN);
    }
    return Token(EMPTY_STR);
}
}  // namespace number_interpreter
