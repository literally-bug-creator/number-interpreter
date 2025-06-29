#include "digits.hpp"

namespace number_interpreter {
    bool DigitExpression::interpret( Context& context ) const {
        if ( context.is_finished() ) return false;

        TokenSequenceView view = context.get_tokens( 1 );

        for ( auto& token : tokens ) {
            if ( view == token ) {
                context.next( size( token ) );
                return true;
            }
        }

        return false;
    }

    bool DigitsExpression::interpret( Context& context ) const {
        if ( !digit.interpret( context ) ) { return false; }

        while ( !context.is_finished() ) {
            if ( !digit.interpret( context ) ) { break; }
        }

        return true;
    }
}
