#pragma once

#include "abstract_expression.hpp"
#include "terminal_expressions/infinity.hpp"
#include "terminal_expressions/not_a_number.hpp"
#include "terminal_expressions/sign.hpp"

namespace number_interpreter {
class SpecialExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    SignExpression sign_ = SignExpression();
    InfinityExpression inf_ = InfinityExpression();
    NotANumberExpression nan_ = NotANumberExpression();
};
}  // namespace number_interpreter
