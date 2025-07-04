#include "nonterminal_expressions/digit.hpp"

#include "context.hpp"
#include "terminal_expressions/non_zero_digit.hpp"
#include "terminal_expressions/zero.hpp"

namespace number_interpreter {
Token DigitExpression::interpret(Context& ctx) const {
    static ZeroExpression zeroExpr = ZeroExpression();
    static NonZeroDigitExpression nonZeroDigitExpr = NonZeroDigitExpression();
    ContextImage img = ctx.backup();
    Token zeroToken = zeroExpr.interpret(ctx);
    if (!zeroToken.isEmpty()) {
        return zeroToken;
    }
    Token nonZeroDigitToken = nonZeroDigitExpr.interpret(ctx);
    if (!nonZeroDigitToken.isEmpty()) {
        return nonZeroDigitToken;
    }
    ctx.restore(img);
    return Token("");
}
}  // namespace number_interpreter
