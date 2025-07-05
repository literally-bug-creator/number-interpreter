#include "nonterminal_expressions/decimal.hpp"

#include "contants.hpp"
#include "context.hpp"
#include "nonterminal_expressions/exponent.hpp"
#include "nonterminal_expressions/fractional_part.hpp"
#include "nonterminal_expressions/signed_integer.hpp"

namespace number_interpreter {
namespace {
constexpr ExponentExpression EXP_EXPR = ExponentExpression();
constexpr SignedIntegerExpression INT_EXPR = SignedIntegerExpression();
constexpr FractionalPartExpression FRACT_EXPR = FractionalPartExpression();
}  // namespace
Token DecimalExpression::interpret(Context& ctx) const {
    ContextImage img = ctx.backup();
    Token integer = INT_EXPR.interpret(ctx);
    if (integer.isEmpty()) {
        ctx.restore(img);
        return getEmptyToken();
    }
    Token fractionalPart = FRACT_EXPR.interpret(ctx);
    Token exponent = EXP_EXPR.interpret(ctx);
    return (integer.merge(fractionalPart)).merge(exponent);
}
}  // namespace number_interpreter
