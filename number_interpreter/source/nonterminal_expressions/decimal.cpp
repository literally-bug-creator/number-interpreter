#include "nonterminal_expressions/decimal.hpp"

#include "context.hpp"
#include "nonterminal_expressions/exponent.hpp"
#include "nonterminal_expressions/fractional_part.hpp"
#include "nonterminal_expressions/signed_integer.hpp"

namespace number_interpreter {
Token DecimalExpression::interpret(Context& ctx) const {
    static ExponentExpression expExpr = ExponentExpression();
    static SignedIntegerExpression intExpr = SignedIntegerExpression();
    static FractionalPartExpression fractExpr = FractionalPartExpression();
    ContextImage img = ctx.backup();
    Token integer = intExpr.interpret(ctx);
    if (integer.isEmpty()) {
        ctx.restore(img);
        return Token("");
    }
    Token fractionalPart = fractExpr.interpret(ctx);
    Token exponent = expExpr.interpret(ctx);
    return (integer.merge(fractionalPart)).merge(exponent);
}
}  // namespace number_interpreter
