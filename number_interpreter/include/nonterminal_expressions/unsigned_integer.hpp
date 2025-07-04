#pragma once

#include "abstract_expression.hpp"
#include "terminal_expressions/non_zero_digit.hpp"
#include "terminal_expressions/zero.hpp"

namespace number_interpreter {
class UnsignedIntegerExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    ZeroExpression zero_ = ZeroExpression();
    NonZeroDigitExpression nonZeroDigit_ = NonZeroDigitExpression();
};
}  // namespace number_interpreter
