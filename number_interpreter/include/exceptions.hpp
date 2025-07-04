#pragma once

#include <stdexcept>
#include <string>

namespace number_interpreter {
class NumberInterpreterException : public std::runtime_error {
  public:
    explicit NumberInterpreterException(const std::string& message)
        : std::runtime_error(message) {}

    explicit NumberInterpreterException(const char* message)
        : std::runtime_error(message) {}
};

// Exception for when parsing goes out of bounds
class OutOfRangeException : public NumberInterpreterException {
  public:
    explicit OutOfRangeException(const std::string& message = "Out of context")
        : NumberInterpreterException(message) {}

    explicit OutOfRangeException(const char* message)
        : NumberInterpreterException(message) {}
};
}  // namespace number_interpreter
