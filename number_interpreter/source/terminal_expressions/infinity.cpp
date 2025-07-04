#include "terminal_expressions/infinity.hpp"

#include <string>

using std::string;

namespace number_interpreter {
Token InfinityExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string INF = "inf";
    string token = ctx.get(INF.length());
    return (token == INF) ? Token(INF) : Token(EMPTY_STR);
}
}  // namespace number_interpreter
