#include "nonterminal_expressions/extended_decimal.hpp"

#include "contants.hpp"
#include "context.hpp"
#include "nonterminal_expressions/decimal.hpp"
#include "nonterminal_expressions/special.hpp"

namespace number_interpreter {
namespace {
constexpr DecimalExpression DECIMAL_EXPR = DecimalExpression();
constexpr SpecialExpression SPECIAL_EXPR = SpecialExpression();
}  // namespace
Token ExtendedDecimalExpression::interpret(Context& ctx) const {
    ContextImage img = ctx.backup();
    Token special = SPECIAL_EXPR.interpret(ctx);
    if (!special.isEmpty()) {
        return special;
    }
    Token decimal = DECIMAL_EXPR.interpret(ctx);
    if (!decimal.isEmpty()) {
        return decimal;
    }
    ctx.restore(img);
    return getEmptyToken();
}
}  // namespace number_interpreter
