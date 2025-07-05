#include "nonterminal_expressions/unsigned_integer.hpp"

#include "contants.hpp"
#include "context.hpp"
#include "nonterminal_expressions/digit.hpp"
#include "terminal_expressions/non_zero_digit.hpp"
#include "terminal_expressions/zero.hpp"

namespace number_interpreter {
namespace {
constexpr ZeroExpression ZERO_EXPR = ZeroExpression();
constexpr DigitExpression DIGIT_EXPR = DigitExpression();
constexpr NonZeroDigitExpression NON_ZERO_DIGIT_EXPR = NonZeroDigitExpression();
}  // namespace
Token UnsignedIntegerExpression::interpret(Context& ctx) const {
    ContextImage img = ctx.backup();
    Token zero = ZERO_EXPR.interpret(ctx);
    if (!zero.isEmpty()) {
        return zero;
    }
    Token integer = NON_ZERO_DIGIT_EXPR.interpret(ctx);
    if (integer.isEmpty()) {
        ctx.restore(img);
        return getEmptyToken();
    }
    Token digit = DIGIT_EXPR.interpret(ctx);
    while (!digit.isEmpty()) {
        integer = integer.merge(digit);
        digit = DIGIT_EXPR.interpret(ctx);
    }
    return integer;
}
}  // namespace number_interpreter
