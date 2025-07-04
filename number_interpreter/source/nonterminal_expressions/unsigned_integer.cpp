#include "nonterminal_expressions/unsigned_integer.hpp"

#include "context.hpp"
#include "nonterminal_expressions/digit.hpp"
#include "terminal_expressions/non_zero_digit.hpp"
#include "terminal_expressions/zero.hpp"

namespace number_interpreter {
Token UnsignedIntegerExpression::interpret(Context& ctx) const {
    static ZeroExpression zeroExpr = ZeroExpression();
    static DigitExpression digitExpr = DigitExpression();
    static NonZeroDigitExpression nonZeroDigitExpr = NonZeroDigitExpression();
    ContextImage img = ctx.backup();
    Token zero = zeroExpr.interpret(ctx);
    if (!zero.isEmpty()) {
        return zero;
    }
    Token integer = nonZeroDigitExpr.interpret(ctx);
    if (integer.isEmpty()) {
        ctx.restore(img);
        return Token("");
    }
    Token digit = digitExpr.interpret(ctx);
    while (!digit.isEmpty()) {
        integer = integer.merge(digit);
        digit = digitExpr.interpret(ctx);
    }
    return integer;
}
}  // namespace number_interpreter
