#pragma once
#include "abstract_expression.hpp"

namespace number_interpreter {
class InfinityExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    std::vector<string> words_ = {"inf", "infinity"};
};
}  // namespace number_interpreter
