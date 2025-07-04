#include "nonterminal_expressions/fractional_part.hpp"

#include "context.hpp"
#include "nonterminal_expressions/digit.hpp"
#include "terminal_expressions/dot.hpp"

namespace number_interpreter {
Token FractionalPartExpression::interpret(Context& ctx) const {
    static DigitExpression digitExpr = DigitExpression();
    static DotExpression dotExpr = DotExpression();
    ContextImage img = ctx.backup();
    Token dot = dotExpr.interpret(ctx);
    if (dot.isEmpty()) {
        ctx.restore(img);
        return Token("");
    }
    Token fractionalPart = digitExpr.interpret(ctx);
    if (fractionalPart.isEmpty()) {
        ctx.restore(img);
        return Token("");
    }
    Token nextDigit = digitExpr.interpret(ctx);
    while (!nextDigit.isEmpty()) {
        fractionalPart = fractionalPart.merge(nextDigit);
        nextDigit = digitExpr.interpret(ctx);
    }
    return dot.merge(fractionalPart);
}
}  // namespace number_interpreter
