#include "nonterminal_expressions/fractional_part.hpp"

#include "contants.hpp"
#include "context.hpp"
#include "nonterminal_expressions/digit.hpp"
#include "terminal_expressions/dot.hpp"

namespace number_interpreter {
namespace {
constexpr DigitExpression DIGIT_EXPR = DigitExpression();
constexpr DotExpression DOT_EXPR = DotExpression();
}  // namespace
Token FractionalPartExpression::interpret(Context& ctx) const {
    ContextImage img = ctx.backup();
    Token dot = DOT_EXPR.interpret(ctx);
    if (dot.isEmpty()) {
        ctx.restore(img);
        return getEmptyToken();
    }
    Token fractionalPart = DIGIT_EXPR.interpret(ctx);
    if (fractionalPart.isEmpty()) {
        ctx.restore(img);
        return getEmptyToken();
    }
    Token nextDigit = DIGIT_EXPR.interpret(ctx);
    while (!nextDigit.isEmpty()) {
        fractionalPart = fractionalPart.merge(nextDigit);
        nextDigit = DIGIT_EXPR.interpret(ctx);
    }
    return dot.merge(fractionalPart);
}
}  // namespace number_interpreter
