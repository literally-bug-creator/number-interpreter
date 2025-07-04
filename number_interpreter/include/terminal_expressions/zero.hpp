#pragma once

#include "abstract_expression.hpp"

namespace number_interpreter {
class ZeroExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    string zero_ = "0";
};
}  // namespace number_interpreter
