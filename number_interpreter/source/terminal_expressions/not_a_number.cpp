#include "terminal_expressions/not_a_number.hpp"

#include <string>

namespace number_interpreter {
std::string NotANumberExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string NAN = "nan";
    string token = ctx.get(NAN.length());
    return (token == NAN) ? NAN : EMPTY_STR;
}
}  // namespace number_interpreter
