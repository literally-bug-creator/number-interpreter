#include "terminal_expression.hpp"

#include <string>

#include "contants.hpp"
#include "exceptions.hpp"

using std::string;
using std::ranges::find;

namespace number_interpreter {
Token TerminalExpression::interpret(Context& ctx) const {
    static const string EMPTY_STR;
    string token;
    try {
        token = ctx.get(getMaxTokenLength());
    } catch (const OutOfRangeException&) {
        return getEmptyToken();
    }
    const auto& tokenArray = getTokens();
    const auto* findIterator =
        find(tokenArray.begin(), tokenArray.end(), token);
    if (findIterator != tokenArray.end()) {
        ctx.next(token.length());
        return Token(*findIterator);
    }
    return getEmptyToken();
}
}  // namespace number_interpreter
