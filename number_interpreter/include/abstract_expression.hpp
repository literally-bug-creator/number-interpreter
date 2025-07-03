#pragma once
#include "context.hpp"

namespace number_interpreter {
class AbstractExpression {
  public:
    [[nodiscard]] virtual string interpret(Context& context) const;
    AbstractExpression(const AbstractExpression&) = default;
    AbstractExpression(AbstractExpression&&) = delete;
    AbstractExpression& operator=(const AbstractExpression&) = default;
    AbstractExpression& operator=(AbstractExpression&&) = delete;
    virtual ~AbstractExpression() = default;
};
}  // namespace number_interpreter
