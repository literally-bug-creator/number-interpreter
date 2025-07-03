#pragma once
#include "abstract_expression.hpp"

namespace number_interpreter {
class ExpExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    string exp_ = "e";
};
}  // namespace number_interpreter
