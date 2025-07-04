#include "nonterminal_expressions/signed_integer.hpp"

#include "context.hpp"
#include "nonterminal_expressions/unsigned_integer.hpp"
#include "terminal_expressions/sign.hpp"

namespace number_interpreter {
Token SignedIntegerExpression::interpret(Context& ctx) const {
    static SignExpression signExpr = SignExpression();
    static UnsignedIntegerExpression uIntExpr = UnsignedIntegerExpression();
    ContextImage img = ctx.backup();
    Token sign = signExpr.interpret(ctx);
    Token uInt = uIntExpr.interpret(ctx);
    if (!uInt.isEmpty()) {
        return sign.merge(uInt);
    }
    ctx.restore(img);
    return Token("");
}
}  // namespace number_interpreter
