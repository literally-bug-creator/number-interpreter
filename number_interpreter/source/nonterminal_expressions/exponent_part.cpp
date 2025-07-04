#include "context.hpp"
#include "nonterminal_expressions/exponent.hpp"
#include "nonterminal_expressions/signed_integer.hpp"
#include "terminal_expressions/exp.hpp"

namespace number_interpreter {
Token ExponentExpression::interpret(Context& ctx) const {
    static ExpExpression expExpr = ExpExpression();
    static SignedIntegerExpression intExpr = SignedIntegerExpression();
    ContextImage img = ctx.backup();
    Token exp = expExpr.interpret(ctx);
    if (exp.isEmpty()) {
        ctx.restore(img);
        return Token("");
    }
    Token integer = intExpr.interpret(ctx);
    if (integer.isEmpty()) {
        ctx.restore(img);
        return Token("");
    }
    return exp.merge(integer);
}
}  // namespace number_interpreter
