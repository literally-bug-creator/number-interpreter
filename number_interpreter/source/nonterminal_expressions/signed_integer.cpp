#include "nonterminal_expressions/signed_integer.hpp"

#include "contants.hpp"
#include "context.hpp"
#include "nonterminal_expressions/unsigned_integer.hpp"
#include "terminal_expressions/sign.hpp"

namespace number_interpreter {
namespace {
constexpr SignExpression SIGN_EXPR = SignExpression();
constexpr UnsignedIntegerExpression UINT_EXPR = UnsignedIntegerExpression();
}  // namespace
Token SignedIntegerExpression::interpret(Context& ctx) const {
    ContextImage img = ctx.backup();
    Token sign = SIGN_EXPR.interpret(ctx);
    Token uInt = UINT_EXPR.interpret(ctx);
    if (!uInt.isEmpty()) {
        return sign.merge(uInt);
    }
    ctx.restore(img);
    return getEmptyToken();
}
}  // namespace number_interpreter
