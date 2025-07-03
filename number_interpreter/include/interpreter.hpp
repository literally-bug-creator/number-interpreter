#pragma once

#include <string>
#include "number_parts.hpp"
namespace number_interpreter {
class NumberInterpreter {
  public:
    NumberParts interpret(std::string);
};
}  // namespace number_interpreter
