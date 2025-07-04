#include "terminal_expressions/infinity.hpp"

#include <string>

#include "exceptions.hpp"

using std::string;

namespace number_interpreter {
Token InfinityExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string INF = "inf";
    string token;
    try {
        token = ctx.get(INF.length());
    } catch (const OutOfRangeException&) {
        return Token(EMPTY_STR);
    }
    return (token == INF) ? Token(INF) : Token(EMPTY_STR);
}
}  // namespace number_interpreter
