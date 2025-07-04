#pragma once

#include "abstract_expression.hpp"
#include "digit.hpp"
#include "terminal_expressions/dot.hpp"

namespace number_interpreter {
class FractionalPartExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    DigitExpression digit_ = DigitExpression();
    DotExpression dot_ = DotExpression();
};
}  // namespace number_interpreter
