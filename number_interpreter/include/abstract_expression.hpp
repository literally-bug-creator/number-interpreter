#pragma once

#include "context.hpp"

namespace number_interpreter {
class AbstractExpression {
  public:
    AbstractExpression(const AbstractExpression&) = default;
    AbstractExpression(AbstractExpression&&) = delete;
    AbstractExpression& operator=(const AbstractExpression&) = default;
    AbstractExpression& operator=(AbstractExpression&&) = delete;
    AbstractExpression();
    virtual ~AbstractExpression() = default;
    [[nodiscard]] virtual string interpret(Context& context) const;
};
}  // namespace number_interpreter
