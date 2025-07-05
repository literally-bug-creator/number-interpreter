#include "contants.hpp"

namespace number_interpreter {
const Token& getEmptyToken() {
    static const Token EMPTY_TOKEN("");
    return EMPTY_TOKEN;
}
}  // namespace number_interpreter
