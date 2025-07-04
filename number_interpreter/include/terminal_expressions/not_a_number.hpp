#pragma once

#include "abstract_expression.hpp"

namespace number_interpreter {
class NotANumberExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    string nan_ = "nan";
};
}  // namespace number_interpreter
