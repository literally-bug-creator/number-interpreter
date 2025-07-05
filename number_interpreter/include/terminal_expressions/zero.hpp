#pragma once

#include "terminal_expression.hpp"

namespace number_interpreter {
class ZeroExpression : public TerminalExpression {
  protected:
    [[nodiscard]] const array<string, MAX_TOKENS>& getTokens() const override;
    [[nodiscard]] uint8_t getMaxTokenLength() const override;
};
}  // namespace number_interpreter
