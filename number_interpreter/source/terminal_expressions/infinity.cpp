#include "terminal_expressions/infinity.hpp"

#include <string>

namespace number_interpreter {
std::string InfinityExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    static const string INF = "inf";
    string token = ctx.get(INF.length());
    return (token == INF) ? INF : EMPTY_STR;
}
}  // namespace number_interpreter
