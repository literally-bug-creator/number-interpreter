#include "terminal_expressions/not_a_number.hpp"

#include <string>

using std::string;

namespace number_interpreter {
Token NotANumberExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string NAN = "nan";
    string token = ctx.get(NAN.length());
    return (token == NAN) ? Token(NAN) : Token(EMPTY_STR);
}
}  // namespace number_interpreter
