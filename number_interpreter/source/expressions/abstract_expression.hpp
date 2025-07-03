#include "context.hpp"

namespace number_interpreter {
class AbstractExpression {
  public:
    [[nodiscard]] string interpret(Context context) const;
};
}  // namespace number_interpreter
