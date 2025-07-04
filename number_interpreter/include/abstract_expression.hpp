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
    AbstractExpression(const AbstractExpression&) = default;
    AbstractExpression(AbstractExpression&&) = default;
    AbstractExpression& operator=(const AbstractExpression&) = default;
    AbstractExpression& operator=(AbstractExpression&&) = delete;
    AbstractExpression();
    virtual ~AbstractExpression() = default;
    [[nodiscard]] virtual Token interpret(Context& context) const;
};
}  // namespace number_interpreter
