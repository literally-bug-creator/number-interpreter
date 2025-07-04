#pragma once

#include "abstract_expression.hpp"

namespace number_interpreter {
class DecimalExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;
};
}  // namespace number_interpreter
