#include <string>

#include "abstract_expression.hpp"

using std::string;

namespace number_interpreter {
Token::Token(string str) : value_(std::move(str)) {}

bool Token::isEmpty() const {
    return value_.empty();
}

string Token::getValue() const {
    return value_;
}

Token Token::merge(const Token& other) const {
    return Token(value_ + other.getValue());
}
}  // namespace number_interpreter
