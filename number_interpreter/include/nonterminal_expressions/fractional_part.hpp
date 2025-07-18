#pragma once

#include "abstract_expression.hpp"

namespace number_interpreter {
class FractionalPartExpression : public AbstractExpression {
  public:
    Token interpret(Context& ctx) const override;
};
}  // namespace number_interpreter
