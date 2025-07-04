#pragma once

#include <string>

#include "context.hpp"

using std::string;

namespace number_interpreter {
class Token {
  public:
    explicit Token(string str);

    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] string getValue() const;

    [[nodiscard]] Token merge(const Token& other) const;

  private:
    string value_;
};

class AbstractExpression {
  public:
    AbstractExpression() = default;
    AbstractExpression(const AbstractExpression&) = default;
    AbstractExpression(AbstractExpression&&) = default;
    AbstractExpression& operator=(const AbstractExpression&) = default;
    AbstractExpression& operator=(AbstractExpression&&) = default;
    virtual ~AbstractExpression() = default;
    [[nodiscard]] virtual Token interpret(Context& ctx) const = 0;
};
}  // namespace number_interpreter
