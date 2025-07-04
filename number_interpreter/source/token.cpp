#include <string>

#include "abstract_expression.hpp"

using std::string;

namespace number_interpreter {
Token::Token(string str) : value_(std::move(str)) {}

bool Token::isEmpty() {
    return value_.empty();
}

string Token::getValue() {
    return value_;
}
}  // namespace number_interpreter
