
#include "sign.hpp"

#include <gtest/gtest.h>

#include "tools.hpp"

using namespace number_interpreter;

const int TESTS_AMOUNT = 10000;

TEST( TestInterpreter, RandomSign ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        SignExpression sign_exp = SignExpression();
        std::string sign = generator.generate_sign();
        if ( sign.empty() ) sign = "-";
        Context ctx = get_context( sign );

        bool is_interpreted = sign_exp.interpret( ctx );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomNotSign ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        SignExpression sign_exp = SignExpression();
        std::string value = generator.generate_integer_part();
        Context ctx = get_context( value );

        bool is_interpreted = sign_exp.interpret( ctx );

        EXPECT_EQ( is_interpreted, false );
    }

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        SignExpression sign_exp = SignExpression();
        std::string value = generator.generate_exponent_value();
        Context ctx = get_context( value );

        bool is_interpreted = sign_exp.interpret( ctx );

        EXPECT_EQ( is_interpreted, false );
    }

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        SignExpression sign_exp = SignExpression();
        std::string value = generator.generate_decimal_part();
        Context ctx = get_context( value );

        bool is_interpreted = sign_exp.interpret( ctx );

        EXPECT_EQ( is_interpreted, false );
    }
}
