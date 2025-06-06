#pragma once

#include "signed_integer.hpp"

namespace number_interpreter {
    class ExpExpression : public TerminalExpression {
    public:
        bool interpret( Context& context ) const override;

    private:
        const Token token = make_token( 'e' );
    };

    class ExponentExpression : public NonTerminalExpression {
    public:
        bool interpret( Context& context ) const override;

    private:
        const ExpExpression exp = ExpExpression();
        const SignedIntegerExpression signed_int = SignedIntegerExpression();
    };
}
