#pragma once

#include "abstract_expression.hpp"
#include "terminal_expressions/non_zero_digit.hpp"
#include "terminal_expressions/zero.hpp"

namespace number_interpreter {
class DigitExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    ZeroExpression zero_;
    NonZeroDigit nonZeroDigit_;
};
}  // namespace number_interpreter
