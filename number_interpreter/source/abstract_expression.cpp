#include "abstract_expression.hpp"

namespace number_interpreter {
AbstractExpression::AbstractExpression() = default;

Token AbstractExpression::interpret(Context& context) const {
    return Token("");
}
}  // namespace number_interpreter