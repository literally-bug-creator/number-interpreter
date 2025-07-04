#pragma once

#include "abstract_expression.hpp"
#include "nonterminal_expressions/unsigned_integer.hpp"
#include "terminal_expressions/sign.hpp"

namespace number_interpreter {
class SignedIntegerExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    SignExpression sign_ = SignExpression();
    UnsignedIntegerExpression unsignedInt_ = UnsignedIntegerExpression();
};
}  // namespace number_interpreter
