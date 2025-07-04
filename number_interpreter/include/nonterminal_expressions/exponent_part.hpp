#pragma once

#include "abstract_expression.hpp"
#include "nonterminal_expressions/signed_integer.hpp"
#include "terminal_expressions/exp.hpp"

namespace number_interpreter {
class ExponentPartExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    ExpExpression exp_ = ExpExpression();
    SignedIntegerExpression signedInt_ = SignedIntegerExpression();
};
}  // namespace number_interpreter
