#include "signed_integer.hpp"

#include <gtest/gtest.h>

#include "tools.hpp"

using namespace number_interpreter;

const int TESTS_AMOUNT = 10000;

TEST( TestInterpreter, RandomSignedInteger ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        SignedIntegerExpression signed_integer = SignedIntegerExpression();
        std::string sign = generator.generate_sign();
        std::string integer = generator.generate_integer_part();
        std::string number = sign + integer;
        Context ctx = get_context( number );

        bool is_interpreted = signed_integer.interpret( ctx );

        EXPECT_EQ( is_interpreted, true );
    }
}

TEST( TestInterpreter, RandomUnsignedInteger ) {
    NumberGenerator generator = NumberGenerator();

    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        SignedIntegerExpression signed_integer = SignedIntegerExpression();
        std::string integer = generator.generate_integer_part();
        std::string number = integer;
        Context ctx = get_context( number );

        bool is_interpreted = signed_integer.interpret( ctx );

        EXPECT_EQ( is_interpreted, true );
    }
}
