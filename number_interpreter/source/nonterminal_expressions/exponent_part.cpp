#include "contants.hpp"
#include "context.hpp"
#include "nonterminal_expressions/exponent.hpp"
#include "nonterminal_expressions/signed_integer.hpp"
#include "terminal_expressions/exp.hpp"

namespace number_interpreter {
namespace {
constexpr ExpExpression EXP_EXPR = ExpExpression();
constexpr SignedIntegerExpression INT_EXPR = SignedIntegerExpression();
}  // namespace
Token ExponentExpression::interpret(Context& ctx) const {
    ContextImage img = ctx.backup();
    Token exp = EXP_EXPR.interpret(ctx);
    if (exp.isEmpty()) {
        ctx.restore(img);
        return getEmptyToken();
    }
    Token integer = INT_EXPR.interpret(ctx);
    if (integer.isEmpty()) {
        ctx.restore(img);
        return getEmptyToken();
    }
    return exp.merge(integer);
}
}  // namespace number_interpreter
