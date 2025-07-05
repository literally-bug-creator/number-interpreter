#include "nonterminal_expressions/special.hpp"

#include "contants.hpp"
#include "context.hpp"
#include "terminal_expressions/infinity.hpp"
#include "terminal_expressions/not_a_number.hpp"
#include "terminal_expressions/sign.hpp"

namespace number_interpreter {
namespace {
constexpr SignExpression SIGN_EXPR = SignExpression();
constexpr InfinityExpression INF_EXPR = InfinityExpression();
constexpr NotANumberExpression NAN_EXPR = NotANumberExpression();
}  // namespace
Token SpecialExpression::interpret(Context& ctx) const {
    ContextImage img = ctx.backup();
    Token signToken = SIGN_EXPR.interpret(ctx);
    ctx.setSign(signToken.getValue());
    Token infToken = INF_EXPR.interpret(ctx);
    if (!infToken.isEmpty()) {
        ctx.setIsInf(true);
        return signToken.merge(infToken);
    }
    Token nanToken = NAN_EXPR.interpret(ctx);
    if (!nanToken.isEmpty()) {
        ctx.setIsNan(true);
        return signToken.merge(nanToken);
    }
    ctx.restore(img);
    return getEmptyToken();
}
}  // namespace number_interpreter
