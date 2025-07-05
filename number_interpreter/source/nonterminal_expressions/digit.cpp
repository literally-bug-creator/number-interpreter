#include "nonterminal_expressions/digit.hpp"

#include "contants.hpp"
#include "context.hpp"
#include "terminal_expressions/non_zero_digit.hpp"
#include "terminal_expressions/zero.hpp"

namespace number_interpreter {
namespace {
constexpr ZeroExpression ZERO_EXPR = ZeroExpression();
constexpr NonZeroDigitExpression NON_ZERO_DIGIT_EXPR = NonZeroDigitExpression();
}  // namespace
Token DigitExpression::interpret(Context& ctx) const {
    ContextImage img = ctx.backup();
    Token zeroToken = ZERO_EXPR.interpret(ctx);
    if (!zeroToken.isEmpty()) {
        return zeroToken;
    }
    Token nonZeroDigitToken = NON_ZERO_DIGIT_EXPR.interpret(ctx);
    if (!nonZeroDigitToken.isEmpty()) {
        return nonZeroDigitToken;
    }
    ctx.restore(img);
    return getEmptyToken();
}
}  // namespace number_interpreter
