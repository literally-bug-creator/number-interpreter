#pragma once

#include "abstract_expression.hpp"

namespace number_interpreter {
class DotExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;
};
}  // namespace number_interpreter
