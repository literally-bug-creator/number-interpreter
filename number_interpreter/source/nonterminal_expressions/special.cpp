#include "nonterminal_expressions/special.hpp"

#include "context.hpp"
#include "terminal_expressions/infinity.hpp"
#include "terminal_expressions/not_a_number.hpp"
#include "terminal_expressions/sign.hpp"

namespace number_interpreter {
Token SpecialExpression::interpret(Context& ctx) const {
    static SignExpression signExpr = SignExpression();
    static InfinityExpression infExpr = InfinityExpression();
    static NotANumberExpression nanExpr = NotANumberExpression();

    ContextImage img = ctx.backup();
    Token signToken = signExpr.interpret(ctx);

    Token infToken = infExpr.interpret(ctx);
    if (!infToken.isEmpty()) {
        ctx.setIsInf(true);
        return signToken.merge(infToken);
    }

    Token nanToken = nanExpr.interpret(ctx);
    if (!nanToken.isEmpty()) {
        ctx.setIsNan(true);
        return signToken.merge(nanToken);
    }

    ctx.restore(img);
    return Token("");
}
}  // namespace number_interpreter
