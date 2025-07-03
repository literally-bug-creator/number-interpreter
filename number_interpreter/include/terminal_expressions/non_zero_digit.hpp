#pragma once
#include "abstract_expression.hpp"

namespace number_interpreter {
class NonZeroDigit : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    std::vector<string> digits_ = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
};
}  // namespace number_interpreter
