#pragma once
#include "abstract_expression.hpp"

namespace number_interpreter {
class SignExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    string minus_ = "-";
    string plus_ = "+";
};
}  // namespace number_interpreter
