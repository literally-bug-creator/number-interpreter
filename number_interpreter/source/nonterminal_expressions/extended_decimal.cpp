#include "nonterminal_expressions/extended_decimal.hpp"

#include "context.hpp"
#include "nonterminal_expressions/decimal.hpp"
#include "nonterminal_expressions/special.hpp"

namespace number_interpreter {
Token ExtendedDecimalExpression::interpret(Context& ctx) const {
    static DecimalExpression decimalExpr = DecimalExpression();
    static SpecialExpression specialExpr = SpecialExpression();
    ContextImage img = ctx.backup();
    Token special = specialExpr.interpret(ctx);
    if (!special.isEmpty()) {
        return special;
    }
    Token decimal = decimalExpr.interpret(ctx);
    if (!decimal.isEmpty()) {
        return decimal;
    }
    ctx.restore(img);
    return Token("");
}
}  // namespace number_interpreter
