#pragma once

#include <array>
#include <cstdint>
#include <string>

#include "abstract_expression.hpp"
#include "context.hpp"

using std::array;
using std::string;

namespace number_interpreter {
constexpr uint8_t MAX_TOKENS = 9;
class TerminalExpression : public AbstractExpression {
  public:
    [[nodiscard]] Token interpret(Context& ctx) const override;

  protected:
    [[nodiscard]] virtual const array<string, MAX_TOKENS>& getTokens()
        const = 0;
    [[nodiscard]] virtual uint8_t getMaxTokenLength() const = 0;
};
}  // namespace number_interpreter
