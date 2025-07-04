#pragma once

#include "abstract_expression.hpp"
#include "nonterminal_expressions/exponent_part.hpp"
#include "nonterminal_expressions/fractional_part.hpp"
#include "nonterminal_expressions/signed_integer.hpp"

namespace number_interpreter {
class DecimalExpression : public AbstractExpression {
  public:
    string interpret(Context& ctx) const override;

  private:
    SignedIntegerExpression signedInt_ = SignedIntegerExpression();
    FractionalPartExpression fraction_ = FractionalPartExpression();
    ExponentPartExpression exponent_ = ExponentPartExpression();
};
}  // namespace number_interpreter
