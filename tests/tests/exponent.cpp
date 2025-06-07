
#include "exponent.hpp"

#include <gtest/gtest.h>

#include "tools.hpp"

using namespace number_interpreter;

const int TESTS_AMOUNT = 10000;

TEST( TestInterpreter, RandomUnsignedExponent ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        ExponentExpression exp = ExponentExpression();
        std::string value = generator.generate_exponent_char() +
                            generator.generate_exponent_value();
        Context ctx = get_context( value );

        bool is_interpreted = exp.interpret( ctx );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomSignedExponent ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        ExponentExpression exp = ExponentExpression();
        std::string value = "e+" + generator.generate_exponent_value();
        Context ctx = get_context( value );

        bool is_interpreted = exp.interpret( ctx );

        EXPECT_EQ( is_interpreted, true );
    }

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        ExponentExpression exp = ExponentExpression();
        std::string value = "e-" + generator.generate_exponent_value();
        Context ctx = get_context( value );

        bool is_interpreted = exp.interpret( ctx );

        EXPECT_EQ( is_interpreted, true );
    }
}
